# huffan-coding
# Huffman Coding (C++ Implementation)

This project implements **Huffman Coding** in C++, using a **greedy algorithm** to build an optimal prefix code from given characters and their frequencies. The program outputs the **Huffman codes** in **preorder traversal** of the constructed Huffman tree.

---

## Problem Statement

Given:
- A string `S` of **distinct characters**.
- An array `f[]` of corresponding **frequencies**.

Task:
- Construct a **Huffman Tree** using the characters and their frequencies.
- Print all Huffman codes in **preorder traversal** (i.e., node → left → right).

---

## Example

**Input:**
```cpp
S = "abcdef"
f = {5, 9, 12, 13, 16, 45}
