#include <stdio.h>
#include <stdlib.h>
int insert(int *arr, int n, int x, int pos)
{
    int size = n + 1;
    arr = (int *)realloc(arr, size * sizeof(int));

    int i = 0;

    for (i = size - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;
    return size;
}
int delet(int *arr, int n, int pos)
{
    int size = n - 1;
    arr = (int *)realloc(arr, size * sizeof(int));
    for (int i = pos - 1; i <= size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size;
}
int search(int value,int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            printf("element found at %d position",i+1);
            return 0;
        }
    
    }
    printf("element not found");
}
int main()
{

    int n, i, *arr;
    int value, pos;

    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int)); // data[size]

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int newsize = n;
start:
    printf("enter i for insert , d for delete,s for search");
    char key;
    scanf("%s", &key);
    if (key == 'i')
    {
        printf("enter element and pos");
        scanf("%d", &value);
        scanf("%d", &pos);

        newsize = insert(arr, n, value, pos);
        for (i = 0; i < newsize; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        system("cls");
        goto start;
    }
     else if (key == 's')
    {
        printf("enter value to search");
        scanf("%d", &value);
        search(value, arr,n);
        system("cls");
        goto start;
    }
    else 
    {
        printf("enter pos");

        scanf("%d", &pos);
        newsize = delet(arr, n, pos);

        for (i = 0; i < newsize; i++)
        {
            printf("%d ", arr[i]);
        }
        system("cls");
        goto start;
    }
    return 0;
}
