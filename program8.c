#include <stdio.h> 
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, size;
    int send_data[4] = {10, 20, 30, 40}; 
    int recv_data; 

    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Scatter 1 integer from send_data array on Root (rank 0) to each process's recv_data
    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    printf("Process %d received: %d\n", rank, recv_data);

    // Each process modifies its received chunk
    recv_data += 1;

    // Gather 1 modified integer from each process back into send_data array on Root (rank 0)
    MPI_Gather(&recv_data, 1, MPI_INT, send_data, 1, MPI_INT, 0, MPI_COMM_WORLD); 

    // Root process prints the newly gathered data
    if (rank == 0)
    {
        printf("\nGathered data on Process 0: "); 
        for (int i = 0; i < size; i++)
        {
            printf("%d ", send_data[i]); 
        }
        printf("\n");
    }

    MPI_Finalize(); 
    return 0;
}
