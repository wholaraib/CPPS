#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, a[10][10], i, j, k, w[10], p[10], m;
    printf("Enter n\n");
    scanf("%d", &n);
    printf("Enter maximum capacity\n");
    scanf("%d", &m);
    printf("\nEnter the weights\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("\nEnter the profits\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {

            if (i == 0 || j == 0)
                a[i][j] = 0;
            else if (w[i] > j)
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(a[i - 1][j], a[i - 1][j - w[i]] + p[i]);
        }
    }
    printf("\nSolved Matrix:\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    cout << "maximum profit is " << a[n][m] << endl;
    return 0;
}