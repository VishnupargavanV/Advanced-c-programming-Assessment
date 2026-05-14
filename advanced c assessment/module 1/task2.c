#include <stdio.h>
#include <stdlib.h>

void rearrange(int *arr, int size)
{
    int *temp = (int *)malloc(size * sizeof(int));

    int *ptr = arr;
    int *t = temp;
    int i;
    for(i = 0; i < size; i++)
    {
        if(*(ptr + i) % 2 == 0)
        {
            *t = *(ptr + i);
            t++;
        }
    }
    for(i = 0; i < size; i++)
    {
        if(*(ptr + i) % 2 != 0)
        {
            *t = *(ptr + i);
            t++;
        }
    }
    for(i = 0; i < size; i++)
    {
        *(arr + i) = *(temp + i);
    }

    free(temp);
}

int main()
{
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int *p = arr;

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", (p + i));
    }
    rearrange(arr, n);

    printf("Rearranged array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}