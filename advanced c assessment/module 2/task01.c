#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

volatile sig_atomic_t keepRunning = 1;

void signalHandler(int sig)
{
    printf("\nSIGINT received. Program will not terminate.\n");
}

int isPrime(int num)
{
    int i;

    if(num < 2)
        return 0;

    for(i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
            return 0;
    }

    return 1;
}

void* primeSumThread(void* arg)
{
    int N = *(int*)arg;

    int count = 0;
    int num = 2;
    long sum = 0;

    clock_t start, end;

    start = clock();

    while(count < N)
    {
        if(isPrime(num))
        {
            sum += num;
            count++;
        }

        num++;
    }

    end = clock();

    double timeTaken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n[Thread A]\n");
    printf("Sum of first %d prime numbers = %ld\n",
           N, sum);

    printf("Execution Time = %f seconds\n",
           timeTaken);

    pthread_exit(NULL);
}

void* thread1(void* arg)
{
    int elapsed = 0;

    clock_t start = clock();

    while(elapsed < 100)
    {
        printf("Thread 1 running\n");

        sleep(2);

        elapsed =
            (clock() - start) / CLOCKS_PER_SEC;
    }

    pthread_exit(NULL);
}

void* thread2(void* arg)
{
    int elapsed = 0;

    clock_t start = clock();

    while(elapsed < 100)
    {
        printf("Thread 2 running\n");

        sleep(3);

        elapsed =
            (clock() - start) / CLOCKS_PER_SEC;
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2, t3;

    int N;

    printf("Enter value of N: ");
    scanf("%d", &N);

    signal(SIGINT, signalHandler);

    pthread_create(&t1, NULL,
                   primeSumThread, &N);

    pthread_create(&t2, NULL,
                   thread1, NULL);

    pthread_create(&t3, NULL,
                   thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("\nAll threads completed.\n");

    return 0;
}