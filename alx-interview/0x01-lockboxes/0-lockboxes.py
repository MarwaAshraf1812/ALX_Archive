#!/usr/bin/python3
"""
0. Lockboxes
"""


def canUnlockAll(boxes):
    """
    canUnlockAll - check if all boxes can be opened
    @boxes: list of boxes
    Return: True if all boxes can be opened, False otherwise
    """
    from collections import deque
    if not boxes:
        return False

    opened = {0}
    queue = deque([0])

    while queue:
        c_box = queue.popleft()
        for key in boxes[c_box]:
            if key not in opened and key < len(boxes):
                queue.append(key)
                opened.add(key)
    return opened == set(range(len(boxes)))
