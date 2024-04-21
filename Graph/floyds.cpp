#include <iostream>
int main()
{
    int n, i, j, k;
    int flyod[100][100], cost[100][100];
    printf("Enter the no. of vertices : ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &flyod[i][j]);
            
    for (k = 0; k < n; k++)
    {

        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {
                flyod[i][j] = (flyod[i][j] < (flyod[i][k] + flyod[k][j])) ? (flyod[i][j]) : (flyod[i][k] + flyod[k][j]);
            }
        }
    }
    printf("Path Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", flyod[i][j]);
        }
        printf("\n");
    }
    return 0;
}
