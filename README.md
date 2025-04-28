# Leetcode-2658.-Maximum-Number-of-Fish-in-a-Grid
# Find Maximum Fish in a Grid

> Author: **Ridham Garg**  
> This repository provides three solutions to find the maximum number of fishes that can be collected from a grid of cells, where each cell may have some fishes. Movement is allowed **up, down, left, right**.

---

## 🛠 Problem Description

Given a 2D grid where each cell contains a certain number of fishes (or zero if empty), the task is to find the **maximum sum of fishes** that can be collected from any connected region.  
You can move to adjacent cells in **four directions** if they have fishes.

---

## 🚀 Solutions Implemented

### 1. **Depth-First Search (DFS) Approach**

- Explore the connected region recursively.
- Mark each visited cell by setting its fish count to 0.
- Accumulate the fish count during traversal.

> File: `dfs_solution.cpp`

### 2. **Breadth-First Search (BFS) Approach**

- Use a queue to explore the region level by level.
- Mark visited cells during traversal.
- Accumulate the fish count as we traverse.

> File: `bfs_solution.cpp`

### 3. **Disjoint Set Union (DSU) Approach**

- Treat each cell as a node in a graph.
- Union adjacent fish-containing cells.
- Maintain the sum of fishes in each connected component using union operations.
- Find the maximum among all components.

> File: `dsu_solution.cpp`

---

## 📈 Comparison

| Approach | Time Complexity | Space Complexity | Notes |
|:--------:|:---------------:|:----------------:|:------|
| DFS      | O(m × n)         | O(m × n)          | Recursive traversal |
| BFS      | O(m × n)         | O(m × n)          | Iterative traversal using queue |
| DSU      | O(m × n × α(mn)) | O(m × n)          | α is Inverse Ackermann Function |

- **DFS and BFS** are traversal-based.
- **DSU** is more structured and better when the grid is large and operations are frequent.


---

## 📚 Learnings

- Efficient graph traversal techniques (DFS, BFS).
- Optimized union-find techniques using path compression.
- Grid-based graph modeling.

---

## 🗕️ Author Information

- **Name**: Ridham Garg
- **Course**: B.Tech Computer Engineering, Thapar University, Patiala
- **Roll Number**: 102203014

---



