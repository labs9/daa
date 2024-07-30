// Program 8: Write and execute a program to find Minimum Spanning Tree using Prim’s method

#include<stdio.h>

// Prims Function
int prims(int n, int a[10][10], int source) {
    int d[100], s[10], i, j, u, v, minval, sum = 0;
    for(i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = a[source][i];
    }
    s[source] = 1;
    for(i = 1; i <= n - 1; i++) {
        minval = 999;
        for(j = 1; j <= n; j++) {
            if(s[j] == 0) {
                if(d[j] < minval) {
                    minval = d[j];
                    u = j;
                }
            }
        }
        s[u] = 1;
        sum = sum + d[u];
        for(v = 1; v <= n; v++)
            if(s[v] == 0 && d[v] > a[u][v])
                d[v] = a[u][v];
    }
    return sum;
}

// Main Program
int main() {
    int n, a[10][10], i, j, source, mstcost;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d",&a[i][j]);
    printf("Enter the source node:\n");
    scanf("%d",&source);
    mstcost = prims(n, a, source);
    printf("The cost of MST is %d\n",mstcost);
}

/*
 Enter the Number of Nodes
4
 Enter the Adjacency Matrix
0 10 999 999
999 0 10 999
999 999 0 10
10 999 999 0
 Enter the Source Node
1
 The cost of minimum spanning Tree is 30
 Enter the Number of Nodes
6
 Enter the Adjacency Matrix
0 18 2 999 999 999
18 0 20 1 90 999
2 20 0 4 50 999
999 1 4 0 3 100
999 90 50 3 0 4
999 999 999 100 4 0
 Enter the Source Node
1
 The cost of minimum spanning Tree is 14 */