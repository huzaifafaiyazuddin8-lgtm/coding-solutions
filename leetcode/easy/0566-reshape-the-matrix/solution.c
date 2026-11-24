
int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize,
                    int** returnColumnSizes) {

    int rows = matSize;
    int cols = matColSize[0];

    // Check if reshaping is possible
    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = (int*)malloc(rows * sizeof(int));

        for (int i = 0; i < rows; i++) {
            (*returnColumnSizes)[i] = cols;
        }

        return mat;
    }

    // Create new matrix
    int** result = (int**)malloc(r * sizeof(int*));

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
    }

    // Copy elements in row order
    for (int i = 0; i < rows * cols; i++) {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }

    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }

    return result;
}
