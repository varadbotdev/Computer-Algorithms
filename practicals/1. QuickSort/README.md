
# What is Quick Sort?

Quick Sort splits data using a chosen pivot, putting lower values on one side, higher ones on the other. It breaks down big lists into smaller chunks through repeated division. Each step focuses on rearranging items based on their size compared to the middle point. This process repeats until everything’s in place. Instead of tackling the whole set at once, it handles pieces separately. Sorting happens faster since each section gets processed individually. The positioning will be carried out with the help of Hoare's mathod of paritioning.

# How does it work?

On average, it organizes a messy list right where it sits, running in about n log n time. People use it a lot because it’s fast and works well with how memory caches behave.

# What's the process behind this?

1. Pick one item from the list - maybe the first or the last. Use that as your starting point instead.
2. Shift the items around - put smaller ones before the pivot, bigger ones behind; that’s what partitioning means.
3. Keep doing this same thing on the smaller parts to the left or right.
4. The recursion ends once arrays contain just one item or none at all.

The algorithm takes O(n²) time in worst case.


# Algorithm

ALGORITHM QuickSort(A, low, high)
INPUT: Array A, indices low and high
OUTPUT: Sorted subarray A[low..high]

IF low < high THEN
    pi ← Partition(A, low, high)
    QuickSort(A, low, pi - 1)
    QuickSort(A, pi + 1, high)
END IF


ALGORITHM Partition(A, low, high)
INPUT: Array A, indices low and high
OUTPUT: Index of pivot after partitioning

pivot ← A[high]
i ← low - 1

FOR j ← low TO high - 1 DO
    IF A[j] < pivot THEN
        i ← i + 1
        SWAP A[i] AND A[j]
    END IF
END FOR

SWAP A[i + 1] AND A[high]
RETURN i + 1

## For more details
https://code2tutorial.com/tutorial/edf6bb4b-67c9-4f30-9f31-891701ff4a47/01_sorting_algorithms_.md

