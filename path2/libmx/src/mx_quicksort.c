#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	char *piv = arr[(left + right) / 2]; 
    int l = left;
    int r = right;
    int count = 0;

    if(*arr == NULL) {
        return -1;
    } 

    while(l <= r) {
        while(mx_strlen(arr[l]) < mx_strlen(piv)) {
            l++;
        }
        while(mx_strlen(arr[r]) > mx_strlen(piv)) {
            r--;
        }

        if(l <= r) {
            char *buff = arr[l];
            arr[l] = arr[r];
            arr[r] = buff;
            l++;
            r--;
            
        }
    }

    if(left < r) {
        count++;
        count = count + mx_quicksort(arr, left, r);
    }
    if(right > l) {
        count++;
        count = count + mx_quicksort(arr, l, right);
    } 


return count;

}
