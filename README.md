# Symbol-Table-Implementation
This project simulates a symbol table typically used in compilers for managing variables and their scopes. It uses hashing to organize variable entries efficiently and stack operations to control variable visibility through nested scopes. This project implements a **symbol table management system** using **hash tables** and a **stack-based scope mechanism** in the C programming language.
It provides functionality to **insert variables**, **begin new scopes**, **end scopes**, and **lookup or print variables** following simple scoping rules.

---

## Features
- Create and manage a symbol table for variables.
- Hash-based storage for efficient variable lookup and insertion.
- Stack structure to manage nested scopes.
- Insert new variables or update values.
- Lookup and print variable values with proper scope resolution.
- Proper memory management to free scopes once they end.
- Error handling for invalid operations (like empty stack access or NULL names).

---

## Main Components
| Component | Description |
| :--- | :--- |
| `symbolentry` | Structure representing a variable entry (name, value, and next pointer) |
| `symboltable` | Hash table (array of pointers to linked lists) |
| `scopestack` | Stack for managing different nested scopes |
| `hash()` | Calculates a hash value for variable names |
| `insert()` | Inserts a variable into the current top scope |
| `lookup()` | Looks up a variable across scopes from top to bottom |
| `begin()` | Pushes a new symbol table to begin a new scope |
| `end()` | Pops the symbol table when ending a scope and frees memory |
| `print()` | Prints the value of a variable if found |

---

## How to Run

1. Save the code to a file named `program.c`
2. Open a terminal and navigate to the directory containing `program.c`
3. Compile the program:
   ```bash
   gcc program.c -o program
   ```
4. Run the executable:
   ```bash
   ./program
   ```

---

## Project Structure
```
program.c
README.md
```

---

## Future Enhancements
- Support multiple data types like float, char, or strings.
- Implement variable redeclaration checking within the same scope.
- Add functionality to delete a specific variable manually.
- Menu-driven user interface for better interactivity.

---

---

**Note:** Make sure to handle memory carefully in large applications to prevent leaks.

