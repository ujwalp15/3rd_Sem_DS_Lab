/*
Lab Program 10
Max Heap
Author ujwalp15
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

int count=0,heap[SIZE];

void insertHeap(int key)
{
	int cur,par;
	if(count == SIZE)
	{
		printf("\n Heap is Full \n");
		exit(0);
	}
	cur = count;
	if(cur == 0)
	{
		heap[cur]=key;
		count++;
		return;
	}	
	
	par=(cur-1)/2;
	while(cur!=0 && key > heap[par])
	{
		heap[cur]=heap[par];
		cur=par;
		par=(cur-1)/2;
	}
	heap[cur]=key;
	count++;
}
void display()
{
	int i;
	for(i=0;i<count;i++)
		printf(" %d ",heap[i]);
}

int main()
{
	int key;
	for(;;)
	{
		printf("\n Enter the key(enter -1 to stop) :  ");
		scanf("%d",&key);
		if(key==-1)
		{	if(count==0)
				printf("\n No element inserted \n");
				break;
		}
		insertHeap(key);
		printf("\n The elements in the heap are: \t");
		display();
	}
	return(0);
}
		
