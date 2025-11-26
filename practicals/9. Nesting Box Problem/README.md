# Nesting Boxes (Box Stacking) Problem

## What is the Nesting Boxes Problem?

Given a set of rectangular boxes, each with dimensions (length, width, height), determine the **maximum number of boxes** that can be nested inside one another—like Russian dolls.

A box **A** can fit inside box **B** if **all dimensions of A are strictly smaller** than those of B (after optionally rotating boxes to align dimensions).

This is a classic **dynamic programming (DP)** problem and a variant of the Longest Increasing Subsequence (LIS).

## How is it solved?

1. **Normalize each box**: sort its dimensions so that `d1 ≤ d2 ≤ d3`.  
2. **Sort all boxes** lexicographically by dimensions.  
3. **Apply DP**:  
   - `dp[i] = 1 + max(dp[j])` for all `j < i` where box `j` fits in box `i`  
4. The answer is `max(dp)`.

## Visualization with SageMath

SageMath is used to:
- Compute the longest nesting chain using DP  
- Build a **directed acyclic graph (DAG)** where an edge `A → B` means "A fits in B"  
- **Visualize the longest path** (optimal nesting sequence) in the graph  

This gives both **algorithmic insight** and **visual intuition**.

## Code Structure

- [`nesting_logic.sage`](code/nesting_logic.sage): Computes the maximum nesting depth and the actual sequence using DP  
- [`visualize_boxes.sage`](code/visualize_boxes.sage): Builds and plots the DAG, highlighting the longest path  

> 💡 Both files can be run independently in SageMath (e.g., via CoCalc).

## How to Run

1. Run `nesting_logic.sage` to see the result.  
2. Run `visualize_boxes.sage` to see the graph with the longest path highlighted.  

