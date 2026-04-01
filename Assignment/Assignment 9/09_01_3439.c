#include <stdio.h>
int diagonal_sum(int matrix[3][3]){
    int sum = 0;
    
    for (int i=0; i<3; i++) {
        sum += matrix[i][i];
    }

    return sum;
}
int row_sum(int matrix[3][3], int row){
    int sum = 0;
    for (int i=0; i<3; i++) {
        sum += matrix[row][i];
    }
    return sum;
}
int column_sum(int matrix[3][3], int col){
    int sum = 0;
    for (int i=0; i<3; i++) {
        sum += matrix[i][col];
    }
    return sum;
}
int max_row_sum(int matrix[3][3]){
    int max_sum = 0;
    int max_row = 0;
    
    for (int i=0; i<3; i++) {
        int sum = row_sum(matrix, i);
        if (max_sum < sum) {
            max_sum = sum;
            max_row = i;
        }
    }

    return max_row;
}
int main()
{
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int sum = diagonal_sum(matrix);
    printf("%d\n", sum);

    for(int i=0;i<3;i++)
    {
        sum = row_sum(matrix,i);
        printf("%d ", sum);
    }

    printf("\n");

    for(int i=0;i<3;i++)
    {
        sum = column_sum(matrix,i);
        printf("%d ", sum);
    }
    printf("\n");
    sum = max_row_sum(matrix);
    printf("%d", sum);
    return 0;
}