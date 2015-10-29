/*
Lab Program 1
Infix to Postfix
Author ujwalp15
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coef,exp;
	struct node *link;
}NODE;


NODE* getNode()
{
	NODE* temp;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("\n No free memory...\n");
		exit(0);
	}
	return(temp);
}

NODE* insertRear(int c,int e,NODE *h)
{
	NODE *temp,*last;
	temp=getNode();
	temp->coef=c;
	temp->exp=e;
	temp->link=h;
	last=h->link;
	while(last->link!=h)
		last=last->link;
	last->link=temp;
	return(h);
}

NODE* readPoly(NODE *h)
{
	int n,i,c,e;
	printf("\n How many terms in Polynomial :  ");
	scanf("%d",&n);
	printf("\n Enter all %d terms one by one:\n",n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter %d term:\n",i+1);
		printf("\n Coefficient :  ");
		scanf("%d",&c);
		printf("\n Exponent :  ");
		scanf("%d",&e);
		h=insertRear(c,e,h);
	}
	return(h);
}

NODE* addPoly(NODE *ha, NODE *hb, NODE *hc)
{
	NODE *ta,*tb;
	ta=ha->link;
	tb=hb->link;
	while(ta!=ha && tb!=hb)
	{
		if(ta->exp == tb->exp)
		{
			if((ta->coef + tb->coef)!=0)
				hc=insertRear(ta->coef+tb->coef, ta->exp,hc);
			ta=ta->link;
			tb=tb->link;
                }
		else if(ta->exp > tb->exp)
		     {	
			hc=insertRear(ta->coef,ta->exp,hc);
			ta=ta->link;
		     }
		     else 
		     {
			hc=insertRear(tb->coef,tb->exp,hc);
			tb=tb->link;
		     }
	}
	while(ta!=ha)
	{
		hc=insertRear(ta->coef,ta->exp,hc);
		ta=ta->link;
	}
	while(tb!=hb)
	{
		hc=insertRear(tb->coef,tb->exp,hb);
		tb=tb->link;
	}
	return(hc);
}

void display(NODE *h)
{
	NODE *temp;
	temp=h->link;
	if (temp == h)
	{
		printf("\n The Polynomial is empty...\n");
		return;
	}
	while(temp!=h)
	{
		

		printf(" %d X^%d ",temp->coef,temp->exp);
		temp=temp->link;
		if(temp!=h && (temp->coef > 0))
			printf("+");
	}
}

int main()
{
	NODE *heada, *headb, *headc;
	heada=getNode();
	headb=getNode();
	headc=getNode();
	
	heada->coef=heada->exp=headb->coef=headb->exp=headc->coef=headc->exp=0;
	heada->link=heada;
	headb->link=headb;
	headc->link=headc;

	printf("\n Enter the details of Polynomial-1:\n");
	heada=readPoly(heada);
	printf("\n Enter the details of Polynomial-2:\n");
	headb=readPoly(headb);
	
	headc=addPoly(heada,headb,headc);
	printf("\n Polynomial-1\n");
	display(heada);
	printf("\n Polynomial-2\n");
	display(headb);
	printf("\n Sum of TWO Polynomials:\n");
	display(headc);	
	return(0);
}
 
	



