int *mx_algorithm_helper(int *min_mindex, int *vis, int **matrix, int *dest) {
	if (matrix[min_mindex[1]][min_mindex[2]] != 0 
		&& matrix[min_mindex[1]][min_mindex[2]] != 2147483647
		&& (min_mindex[0] + matrix[min_mindex[1]][min_mindex[2]] < dest[min_mindex[2]]) 
		&& vis[min_mindex[2]] != 1) 
		{
			dest[min_mindex[2]] = matrix[min_mindex[1]][min_mindex[2]] + min_mindex[0];
		} 
	return dest;
}
