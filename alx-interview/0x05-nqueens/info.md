Backtracking ?

    is like trying different paths, and when you hit a dead end, you backtrack to the last choice and try a different route.

    is a problem-solving algorithmic technique that involves finding a solution incrementally by trying different options and undoing them if they lead to a dead end. It is commonly used in situations where you need to explore multiple possibilities to solve a problem, like searching for a path in a maze or solving puzzles like Sudoku. When a dead end is reached, the algorithm backtracks to the previous decision point and explores a different path until a solution is found or all possibilities have been exhausted.

How does Backtracking works?

    1- Select a choice from the set of possible choices.
    2- Recursively explore this choice and make further choices.
    3- If this choice does not lead to a solution, undo the choice and try the next option.

Types of Backtracking Problems ?

    1- Decision Problems: we search for a feasible solution.
      feasible solution =>  is a partial or complete solution that adheres to all constraints.
    2- Optimization Problems: we search for the best solution.(Optimal Solution)
    3- Enumeration Problems: We find set of all possible feasible solutions

===================================
Recursion ?

    A recursive function is a function defined in terms of itself via self-referential expressions.

    -- This means that the function will continue to call itself and repeat its behavior until some condition is met to return a result. All recursive functions share a common structure made up of two parts: base case and recursive case.

    => If the current problem represents a simple case, solve it. If not, divide it into subproblems and apply the same strategy to them.


List Manipulations in Python ?

    -- Lists in Python are used to store sequences of data. In backtracking     algorithms, lists are often used to store the current state or partial solutions.
    =====> 
    `# Creating a list
    board = [-1] * 8  # For an 8-queens problem

    # Modifying list elements
    board[0] = 1
    board[1] = 3

    # Accessing list elements
    print(board[0])  # Output: 1
    print(board)     # Output: [1, 3, -1, -1, -1, -1, -1, -1]
    `
Python Command Line Arguments ?

    -- Python provides a module named sys which allows you to access command-line arguments passed to the script.

    `import sys

    def main():
        if len(sys.argv) != 2:
            print("Usage: python script.py <number>")
            sys.exit(1)
        
        n = int(sys.argv[1])
        solutions = solve_n_queens(n)
        print(solutions)

    if __name__ == "__main__":
        main()`

    
