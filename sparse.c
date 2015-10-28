/*
Lab Program 9
Sparse Martix Search
Author ujwalp15
*/

#include <stdio.h>

#define SIZE 10

typedef struct SPARSE
{
    int row;
    int column;
    int value;
}sparse;

int main()
{
    sparse E[SIZE];
    int n, i, key, flag=0;


    printf("\nEnter the Number of Non-Zero Elements in the Sparse Matrix: ");
    scanf("%d", &n);
    printf("\n");

    for(i = 0; i < n; i++)
    {   printf("\n Enter the details :\n");
	printf("\n Row Index: ");
        scanf("%d", &E[i].row);
	printf("\n Column Index: ");        
        scanf("%d", &E[i].column);
	printf("\n Value: ");       
        scanf("%d", &E[i].value);
    }

    printf("\n\nEnter the element to search for : ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
        if(E[i].value == key)
        {
            printf("\nThe element %d is Found At Row %d And Column %d \n", key, E[i].row, E[i].column);
            flag=1;
	    break;
        }

    if(flag == 0)
        printf("\nElement Not Found\n");

	return 0;
}
