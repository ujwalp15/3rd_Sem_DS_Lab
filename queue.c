/*
Lab Program 4
Queue
Author ujwalp15
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int queue[SIZE],front=-1,rear=-1;

int isqempty()
{
	if(front==-1 && rear==-1)
		return 1;
	else
		return 0;
}

int isqfull()
{
	if(rear==SIZE-1)
		return 1;
	else
		return 0;
}

void insertq(int elem)
{
	rear++;
	queue[rear]=elem;
	if(front==-1)
		front++;
}

int deleteq()
{
	int elem;
	elem=queue[front];
	if(front==rear)
		front=rear=-1;
	else
		front++;
	return(elem);
}

void display()
{
	int i;
	for(i=front;i<=rear;i++)
		printf("\n %d",queue[i]);
}

int main()
{
	int i, ele, choice;
	do
	{
		printf("\n Demonstrating the working of Queues :-   ");
		printf("\n 1. Insert.\n 2. Delete.\n 3. Display. \n 4. Quit.\n");
		printf("\n Enter your choice  :   ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("\n Your choice is 1. Insert");
				if(isqfull())
				{
					printf("\n Queue is full \n\n");
					break;
				}
				printf("\n Enter the element to be inserted into the Queue :  ");
				scanf("%d", &ele);
				insertq(ele);
				printf("\n %d is inserted successfully\n", ele);
				break;
			case 2 :
                                printf("\n Your choice is 2. Delete....");
                                if(isqempty())
                                {
                                        printf("\n Queue is Empty \n\n");
                                        break;
                                }
				ele=deleteq();
                                printf("\n %d is deleted successfully\n\n", ele);
                                break;
			case 3 :
                                printf("\n Your choice is 3. Display");
                                if(isqempty())
                                {
                                        printf("\n Sorry.... Queue is empty... Nothing to display...\n");
                                        break;
                                }
                                printf("\n The elements present in the Queue are:\n");
                                display();
                                break;
			case 4 :
				printf("\n Your choice is 4. Quit");
				printf("\n Bye \n");
				break;
			default:
				printf("\n Invalid choice... Try again...\n");
		}
	}while(choice!=4);

	return 0;
}

	


 


