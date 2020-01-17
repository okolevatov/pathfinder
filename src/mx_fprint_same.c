#include "../inc/pathfinder.h"

int *mx_fprint_same(int kilkist, int **recover) {
    int *sf = (int*)(malloc)(sizeof(int) * (2));
    int flag = 0;

    for (int j = kilkist - 1; j >= 0; j--) {
        if(recover[0][j] != -1) {
            flag = 1;
        } 
        if(flag == 1) {
            sf[0] = recover[0][j];
            while (j != 0 && recover[0][j - 1] != -1) {
                j--;
            }
            sf[1] = recover[0][j];
            break;
        }
    }
    return sf;
}
