#include <stdio.h> 
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, data = 0;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Root process (Rank 0) sets the initial data value
    if (rank == 0) {
        data = 100;
    }

    // Broadcast data from root (rank 0) to all processes in MPI_COMM_WORLD
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // All processes print the broadcasted data
    printf("Process %d received data: %d\n", rank, data);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
