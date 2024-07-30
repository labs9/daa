// Program 1: Write and execute a program to sort a given set of elements using the Quick sort method.

#include<stdio.h>

// Partition Function
int partition(int a[100], int low, int high) {
    int key, i, j, temp;
    key = a[low];
    i = low + 1;
    j = high;
    while(1) {
        while (key >= a[i])
            i++;
        while (key < a[j])
            j--;
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}

// Quicksort Function
void quicksort(int a[100], int low, int high) {
    int j;
    if(low < high) {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

// Main Program
int main() {
    int n, a[100], i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    quicksort(a, 0, n - 1);
    printf("The sorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d\t",a[i]);
}

/*
Output:
enter the number of elements
10
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
the sorted array is
41 6334 11478 15724 18467 19169 26500 24464 26962 29358
time taken is 0.000000
*/