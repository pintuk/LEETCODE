

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, n;
    int **array;
    n = numsSize;
    *returnSize = 1 << n;
    array = (int **)malloc(sizeof(int *)*(*returnSize));
    returnColumnSizes = (int **)malloc(sizeof(int *)*(*returnSize));
    for (i = 0; i < (1 << n); i++) {
        int col = 0;
        array[i] = (int *)malloc(sizeof(int)*n);
        memset(array[i], 0, sizeof(int)*n);
        for (j = 0; j < n; j++) {
             if (i & (1 << j)) {
                 array[i][j] = nums[j];
                 col++;
             }
        }
        returnColumnSizes[i] = (int *)malloc(sizeof(int));
        returnColumnSizes[i][0] = col;
    }
    return array;
}

