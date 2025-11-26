# MPI: Distributed Arithmetic Operations

## What is MPI?

MPI (Message Passing Interface) is a standardized communication protocol for parallel computing in distributed-memory systems. It enables multiple processes to exchange data and coordinate tasks across a cluster or multicore machine.

## What does this program do?

This program demonstrates a simple master-worker model:
- The **master process (rank 0)** reads two numbers from the user.
- It sends these numbers to **four worker processes (ranks 1–4)**.
- Each worker performs one operation:
  - Rank 1: Addition  
  - Rank 2: Subtraction  
  - Rank 3: Multiplication  
  - Rank 4: Division  
- Workers send their results back to the master.
- The master computes and prints the **maximum** and **minimum** of the four results.

## Important MPI Functions Used


 `MPI_Init()` ->  Initializes the MPI environment 
 `MPI_Finalize()` -> Cleans up and ends MPI execution 
 `MPI_Comm_rank()` -> Gets the unique ID (rank) of the calling process 
 `MPI_Comm_size()` -> Gets the total number of processes in the communicator 
 `MPI_Send()` -> Sends data from one process to another 
 `MPI_Recv()` -> Receives data sent by another process 
 

These are the core **point-to-point communication** routines used in basic MPI programs.

## Generic Structure of an MPI Program

Every MPI program follows this minimal template:

```cpp
#include <mpi.h>

int main(int argc, char** argv) {
    // 1. Initialize MPI
    MPI_Init(&argc, &argv);

    // 2. Get process info
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 3. Parallel work (based on rank)
    if (rank == 0) {
        // Master logic
    } else {
        // Worker logic
    }

    // 4. Finalize MPI
    MPI_Finalize();
    return 0;
}