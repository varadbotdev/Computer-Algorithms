# Vector Quantization

## What is Vector Quantization?

Vector Quantization (VQ) is a technique for data compression and representation that maps a large set of vectors into a smaller set of representative vectors called *codevectors* (or *centroids*). It is widely used in speech coding, image compression, and signal processing.

## What does it do?

Given a dataset of input vectors and a desired codebook size \( k \), VQ constructs a codebook of \( k \) codevectors such that each input vector can be approximated by its nearest codevector. This reduces storage and transmission cost while preserving essential features.

This method works in areas like audio encoding, picture crunching, plus handling signals. Instead of storing everything, it uses typical examples to stand in. Each original vector gets swapped with one from the compact group.

## How does it work?

1. Initialize a codebook with k codevectors (e.g., randomly or using a subset of input data).
2. Assign each input vector to the nearest codevector (using Euclidean or other distance).
3. Update each codevector as the average of all vectors assigned to it.
4. Repeat steps 2–3 until the codebook stabilizes (convergence).

This iterative process is nearly identical to K-Means—indeed, VQ is often viewed as K-Means applied to signal vectors.

