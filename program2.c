#include <stdio.h>
#include <omp.h>

int main()
{
    int n, thread;

    printf("\nEnter the number of tasks: ");
    scanf("%d", &n);

    printf("Enter the number of threads: ");
    scanf("%d", &thread);

    // Set the requested number of OpenMP threads
    omp_set_num_threads(thread);

    printf("\n--------------------------------------\n");

    // Static schedule with chunk size = 2
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < n; i++)
    {
        printf("Thread %d executes iteration %d\n", omp_get_thread_num(), i);
    }

    printf("--------------------------------------\n");

    return 0;
}

