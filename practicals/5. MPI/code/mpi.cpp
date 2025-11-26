#include <mpi.h>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 5) {
        if (rank == 0) {
            cout << "Error: At least 5 processes required (1 master + 4 workers).\n";
        }
        MPI_Finalize();
        return 0;
    }

    double a, b;
    double result = 0.0;

    if (rank == 0) {
        cout << "Enter two numbers: ";
        cin >> a >> b;

        // Send to workers 1-4
        MPI_Send(&a, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&a, 1, MPI_DOUBLE, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_DOUBLE, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&a, 1, MPI_DOUBLE, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_DOUBLE, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&a, 1, MPI_DOUBLE, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_DOUBLE, 4, 0, MPI_COMM_WORLD);
    }

    if (rank == 1) {
        MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        result = a + b;
        MPI_Send(&result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    else if (rank == 2) {
        MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        result = a - b;
        MPI_Send(&result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    else if (rank == 3) {
        MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        result = a * b;
        MPI_Send(&result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    else if (rank == 4) {
        MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (b == 0) result = 0; 
        else result = a / b;
        MPI_Send(&result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        double results[4];
        MPI_Recv(&results[0], 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&results[1], 1, MPI_DOUBLE, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&results[2], 1, MPI_DOUBLE, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&results[3], 1, MPI_DOUBLE, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        double min_val = *min_element(results, results + 4);
        double max_val = *max_element(results, results + 4);

        cout << "Results: ";
        for (int i = 0; i < 4; i++) cout << results[i] << " ";
        cout << "\nMin: " << min_val << ", Max: " << max_val << endl;
    }

    MPI_Finalize();
    return 0;
}