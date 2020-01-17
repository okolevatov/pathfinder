int mx_problem(int **recover, int *arr, int i) {
    int count = 0;

    for (int j = 0; j < arr[0]; j++) {
        if (recover[i][j] == -1) {
            count++;
        }
        if (count == arr[0]) {
            return 0;
        }
    }
    return 1;
}
