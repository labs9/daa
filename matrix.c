// Program 6: Write and execute a program for matrix chain multiplication for the given the sequence of
// Matrices <A1, A2. . . . . An>

#include<stdio.h>
#include<limits.h>

// Matrix Chain Order Function
int mcm (int p[], int i, int j) {
    int k, count;
    int min = INT_MAX;
    if(i == j)
        return 0;
    for(k = i; k < j; k++) {
        count = mcm(p, i, k) + mcm(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if(min>count)
            min = count;
    }
    return min;
}

// Main Program
int main() {
    int a[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(a)/sizeof(a[10]);
    printf("Minimum number of multiplications is %d\n", mcm(a, 1, n - 1));
}

/*
Enter the numbre of matrices
4
Enter the sizes of matrices (p0,p1....)
5 6 4 2 3
Minimum number of multiplications is :
-------------------------------------------
0 120 108 138
-- 0 48 84
-- -- 0 24
-- -- -- 0
*/

/*
Enter the numbre of matrices
6
Enter the sizes of matrices (p0,p1....)
30 35 15 5 10 20 25
Minimum number of multiplications is :
-------------------------------------------
0 15750 7875 9375 11875 15125
-- 0 2625 4375 7125 10500
-- -- 0 750 2500 5375
-- -- -- 0 1000 3500
-- -- -- -- 0 5000
-- -- -- -- -- 0
*/