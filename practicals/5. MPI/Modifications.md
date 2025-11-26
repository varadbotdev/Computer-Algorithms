# Critical Thinking Questions

After running and analyzing the MPI arithmetic program, consider:

1. What happens if you run this program with fewer than 5 processes (e.g., `mpirun -n 3`)? How can you make the code robust to varying process counts?

2. Suppose you want to add a fifth operation (e.g., modulus). What changes would you need to make? Could the program auto-assign operations based on rank?

3. In a real cluster, processes may run on different machines with different speeds. Could a slow worker delay the entire program? Why?

4. Instead of sending two numbers repeatedly, could you use `MPI_Bcast` or `MPI_Scatter`? When is point-to-point better than collective communication?

