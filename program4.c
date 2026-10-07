#include <stdio.h>
#include <omp.h>

// Function to check if a number is prime
int is_prime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    long n = 500000; // Adjusted default range for quick execution (you can increase this)
    double start, end;
    double time_serial, time_parallel;

    printf("\nEnter the upper limit (n): ");
    if (scanf("%ld", &n) != 1 || n <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\nChecking prime numbers in range 1 to %ld\n", n);
    printf("---------------------------------------------------\n");

    // ---------- SERIAL EXECUTION ----------
    start = omp_get_wtime();
    for (int i = 1; i <= n; i++)
    {
        is_prime(i);
    }
    end = omp_get_wtime();
    time_serial = end - start;
    printf("Time to compute prime numbers (Serial)   : %.6f seconds\n", time_serial);

    // ---------- PARALLEL EXECUTION ----------
    start = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
    for (int i = 1; i <= n; i++)
    {
        is_prime(i);
    }
    end = omp_get_wtime();
    time_parallel = end - start;
    printf("Time to compute prime numbers (Parallel) : %.6f seconds\n", time_parallel);

    printf("---------------------------------------------------\n");
    printf("Speedup Ratio                            : %.2fx\n", time_serial / time_parallel);
    printf("---------------------------------------------------\n");

    return 0;
}
