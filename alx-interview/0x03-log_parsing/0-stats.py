#!/usr/bin/python3
"""
This script reads from standard input and computes metrics.
"""
import sys
import signal
import re


status_code_count = {}
total_f_size = 0
counter = 0
# log_pattern = re.compile(r'^(\S+) - \[(.+)\] "(\S+) (\S+)" (\d{3}) (\d+)$')
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def print_stats(status_codes, total_f_size):
    """
    Print the total file size and status codes counts.
    """
    print(f"File size: {total_f_size}")
    for k, v in sorted(status_codes.items()):
        if v > 0:
            print(f"{k}: {v}")


def exit_handler(sig, frame):
    """
    Handle the exit signal (SIGINT).
    """
    print_stats(total_f_size, status_codes)
    sys.exit(0)


# Register the signal handler
signal.signal(signal.SIGINT, exit_handler)


try:
    for line in sys.stdin:
        parsed_line = line.split()
        parsed_line = parsed_line[::-1]  # Reverses the list of components.

        if len(parsed_line) > 2:
            counter += 1

            if counter <= 10:
                total_f_size += int(parsed_line[0])
                status_code = parsed_line[1]

                if (status_code in status_codes.keys()):
                    status_codes[status_code] += 1
            if counter == 10:
                print_stats(status_codes, total_f_size)
                counter = 0
finally:
    print_stats(status_codes, total_f_size)
