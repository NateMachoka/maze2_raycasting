# Maze Path Tracker

## 📌 Overview
This project demonstrates how to implement and manage **dynamic arrays** in C through a simple maze dynamic path array.  
The path is represented as a sequence of `(x, y)` positions, with operations to add, delete, undo, shift, and keep only a portion of history.

It provides a foundation for:
- Understanding **dynamic memory allocation** with `malloc`, `realloc`, and `free`.
- Implementing **array resizing**.
- Performing **insertions, deletions, and shifts** inside an array.
- Managing **undo functionality** and **limited memory history** for path tracking.

---

## ⚙️ Features
- Initialize a dynamic path with a starting position `(0, 0)`.
- Add moves (`dx`, `dy`) to the path.
- Undo last move
- Delete at a specific index(though this will rarely be implemented in a
  maze game).
- Keep only the last **N** moves (like a memory-limited history). Alternativ  ely, you can do ring or circular buffer to avoid shifting memory.
- Remove the last **N** moves (e.g., when a player "dies" and is taken back   a few steps).
- Print full path history.
- Proper cleanup of dynamically allocated memory.

---

## 🗂️ File Structure
- ⚠️ Now all functions are in a one file (`maze_array.c`) for easier testing.
- Later, will split into declarations, path logic, and driver logic as for
  modularity as maze grows.

---

## 🚀 Compilation & Usage

### Compile
```bash
gcc -Wall -Wextra -Werror -pedantic main.c path.c -o maze

### Run

```bash
./maze

### Example output

```bash
path history:
Step 0 -> (0 , 0)
Step 1 -> (1 , 0)
Step 2 -> (1 , 1)
Step 3 -> (0 , 1)
Step 4 -> (0 , 0)

## 🛠️ Functions Implemented

- `initPath(int size)` → Initialize a path with capacity.  
- `resizePath(Path *path)` → Expand array when full.  
- `move(Path *path, int dx, int dy)` → Add a new move.  
- `delete_lastPosition(Path *path)` → Remove last step.  
- `undoDelete(Path *path)` → Undo last step (returns removed position).  
- `delete_atIndex(Path *path, int index)` → Remove element by index.  
- `keepLastN(Path *path, int N)` → Keep only last N steps.  
- `removeLastN(Path *path, int N)` → Remove last N steps.  
- `printPath(Path *path)` → Print history.  
- `freePath(Path *path)` → Free memory.  

## 🎯 Learning Outcomes 

By working with this project, you will:

- Understand dynamic array design in C.
- Gain hands-on practice with insertion, deletion, and shifting operations.
- Learn how to implement undo-like functionality and history truncation.
- Improve memory management practices.



## 📚 Further Reading & Resources

- **Arrays vs Linked Lists**
  [Arrays vs. Linked Lists: Which One Should You Use? (GeeksforGeek)]) (https://www.geeksforgeeks.org/dsa/linked-list-vs-array/) 

- **Video: Arrays Explained**
  [Data Structures: Arrays (freeCodeCamp)](https://www.youtube.com/watch?v=VVZTVHuVSqw)  

- **Video: Big O Notation**
  [Big O Notation in 100 Seconds (freeCodeCamp)](https://www.youtube.com/watch?v=Mo4vesaut8g&t=4624s)  

- **Book Recommendation**
  *Grokking Algorithms* by Aditya Bhargava – beginner-friendly, illustrated guide to understanding data structures and algorithms. 

## 📜 License

This project is for educational purposes and is unlicensed.
