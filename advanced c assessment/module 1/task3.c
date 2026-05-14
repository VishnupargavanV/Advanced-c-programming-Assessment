#include <stdio.h>

int searchMatrix(int rows, int cols,
                 int matrix[rows][cols],
                 int key)
{
    int row = 0;
    int col = cols - 1;
    while(row < rows && col >= 0)
    {
        if(matrix[row][col] == key)
        {
            return 1; // found
        }
        else if(matrix[row][col] > key)
        {
            col--; // move left
        }
        else
        {
            row++;
        }
    }
    return 0; 
}
int main()
{
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int i, j;

    printf("Enter matrix elements:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int key;

    printf("Enter key to search: ");
    scanf("%d", &key);
    if(searchMatrix(rows, cols, matrix, key))
    {
        printf("Key found in matrix.\n");
    }
    else
    {
        printf("Key not found.\n");
    }

    return 0;
}