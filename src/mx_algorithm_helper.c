int *mx_algorithm_helper(int *mx, int *vis, int **matrix, int *dest) {
    if (matrix[mx[1]][mx[2]] != 0 
        && matrix[mx[1]][mx[2]] != 2147483647
        && (mx[0] + matrix[mx[1]][mx[2]] < dest[mx[2]]) 
        && vis[mx[2]] != 1) 
        {
            dest[mx[2]] = matrix[mx[1]][mx[2]] + mx[0];
        } 
    return dest;
}
