# Tree Traversals - Solution

**ID:** 1702 | **URL:** https://cses.fi/problemset/task/1702

## Approach

### Problem Restatement

Given preorder and inorder traversals of a binary tree with distinct labels, determine the postorder traversal.

### Core idea

The first element of preorder is always the root. In inorder, the root splits the sequence into left subtree (elements before it) and right subtree (elements after it). Recursively: read root from preorder, split inorder at root position, recurse left then right, then output the root last — which is exactly postorder (left → right → root). The pair (preorder, inorder) uniquely determines the tree: the root is fixed by preorder, and the inorder split is unique for each subtree. Use a position array for $O(1)$ root lookup in inorder.

### Algorithm

1. Precompute `pos[v]` = position of value $v$ in inorder.
2. Recursively process with a pointer `cur` into preorder:
   - Root = `preorder[cur]`, `mid = pos[root]`.
   - Recurse on left subtree (inorder range `[Left, mid-1]`).
   - Recurse on right subtree (inorder range `[mid+1, Right]`).
   - Output root.

### Example

Preorder: [5, 3, 2, 1, 4]. Inorder: [3, 5, 1, 2, 4].

Root 5 → left {3}, right {1,2,4}. Left: root 3 → output 3. Right: root 2 → left {1}, right {4} → output 1, 4, 2. Output 5.

Postorder: 3, 1, 4, 2, 5.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Tree%20Traversals.cpp)
