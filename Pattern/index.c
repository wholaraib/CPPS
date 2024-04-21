// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int m,n,rsum = 0,csum = 0;
//     printf("Enter the rows and columns of matrix A: ");
//     scanf("%d%d",&m,&n);
//     int arr[m][n];
//     printf("Enter %d elements for Matrix A:\n",m*n);
//     for(int i = 0; i < m; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             scanf("%d",&arr[i][j]);
//         }
//     }
//     printf("Matrix A <%d> x <%d>:\n",m,n);
//     for(int i = 0; i < m; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             printf("%d  ",arr[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\nRow sum:");
//     for(int i = 0; i < m; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             rsum+=arr[i][j];
//         }
//         printf("\nSum of row %d = %d",i+1, rsum);
//         rsum = 0;
//     }
//     printf("\nColumn sum:");
//     for(int j = 0; j < n; j++)
//     {
//         for(int i = 0; i < m; i++)
//         {
//             csum+=arr[i][j];
//         }
//         printf("\nSum of col %d = %d",j+1, csum);
//         csum = 0;
//     }
// }
#include <stdio.h>
void readarray(int a[], int n);
void displayarray(int a[], int n);
void selectionsort(int a[], int n);
int main()
{
    int n;
    int a[100];
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    readarray(a,n);
    printf("Unsorted array is:\n");
    displayarray(a,n);
    selectionsort(a,n);
    printf("\nSorted array is:\n");
    displayarray(a,n);
    return 0;
}
void readarray(int a[], int n)
{
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
}
int minindex;
int temp;
void selectionsort(int a[],int n)
{
    for(int i = 0; i < n - 1; i++)
    {   
        minindex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
    }
}
void displayarray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d  ",a[i]);
    }
}