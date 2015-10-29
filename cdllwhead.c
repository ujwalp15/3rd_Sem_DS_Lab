/*
 * Lab Cycle Program No.11
 * Program to demonstrate the working of Circular Doubly Linked List with Header Node.
 * Akram Pasha. 20/10/2015.
*/
#include<stdio.h>
//#include<alloc.h>
#include<stdlib.h>

typedef struct node
{
	struct node *llink;
	int info;
	struct node *rlink;
}NODE;

NODE* getNode()
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("\n Sorry... No Free Memory...\n");
		exit(0);
	}
	return(temp);
}

NODE * insertFront(int elem, NODE *head)
{
	NODE *temp,*first;
	temp=getNode();
	temp->info=elem;
	first=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	temp->rlink=first;
	first->llink=temp;
	head->info++;
	return(head);
}

NODE * insertB4Key(int elem, int key, NODE *head)
{
	NODE *temp,*cur,*prev;
	if(head->rlink==head)
	{
		printf("\n Sorry List is empty...\n");
		return(head);
	}
	cur=head->rlink;
	while(cur!=head && cur->info!=key)
	{
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("\n Sorry...%d not found...\n",key);
		return(head);
	}
	prev=cur->llink;
	temp=getNode();
	temp->info=elem;
	prev->rlink=temp;
	temp->llink=prev;
	temp->rlink=cur;
	cur->llink=temp;
	head->info++;
	return(head);
}
NODE* deleteKey(int key, NODE *head)
{
        NODE *cur,*prev,*next;
        if(head->rlink==head)
        {
                printf("\n Sorry List is empty...\n");
                return(head);
        }
        cur=head->rlink;
        while(cur!=head && cur->info!=key)
        {
                cur=cur->rlink;
        }
        if(cur==head)
        {
                printf("\n Sorry...%d not found...\n",key);
                return(head);
        }
	prev=cur->llink;
	next=cur->rlink;
	prev->rlink=next;
	next->llink=prev;
	printf("\n %d is deleted from the list...Proceed...\n",cur->info);
	free(cur);
	head->info--;
	return(head);
}
void display(NODE *head)
{
	NODE *cur;
	if(head->rlink==head)
	{
		printf("\n Sorry...List is Empty...\n");
		return;
	}
	for(cur=head->rlink;cur!=head;cur=cur->rlink)
		printf("\n %d ",cur->info);
}


	
int main()
{
	NODE *head;
        int elem,key,choice;
	head=getNode();
	head->info=0;
	head->llink=head->rlink=head;
	do
        {
                printf("\n ***************************************************************");
		printf("\n MENU \n 1. Insert Front \n 2. Insert Before Key \n 3. Delete Key \n 4. Dispay \n 5. Exit \n");
		printf("\n ***************************************************************");
                printf("\n Enter your choice--->");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1 : printf("\n Your choice Insert Front");
                                 printf("\n Enter the element--->");
                                 scanf("%d", &elem);
				 head=insertFront(elem,head);
                                 printf("\n %d is inserted at front.....Proceed.\n",elem);
				 printf("\n ***************************************************************");
                                 break;

                        case 2 : printf("\n Your choice Insert Before Key");
                                 printf("\n Enter the element--->");
                                 scanf("%d", &elem);
                                 printf("\n Enter the key element--->");
                                 scanf("%d", &key);
                                 head=insertB4Key(elem,key,head);
                                 printf("\n %d is inserted before %d .....Proceed.\n",elem,key);
				 printf("\n ***************************************************************");
                                 break;

                        case 3 : printf("\n Your choice Delete Key\n");
				 printf("\n Enter the key element-->");
				 scanf("%d",&key);
				 head = deleteKey(key,head);
				 printf("\n ***************************************************************");
                                 break;

                        case 4 : printf("\n Your choice Display");
				 display(head);
				 printf("\n ***************************************************************");
                                 break;

                        case 5 : printf("\n Quitting...............\n");
                                 break;
                        default : printf("\n Invalid Choice...............\n");
                }
        } while(choice != 5);
        printf("\n ***************************************************************\n\n");
	return(0);
	
}


