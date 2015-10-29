/*
Lab Program 3
Infix to Postfix
Author ujwalp15
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int top=-1;
char stack[SIZE];

void push(int ele)
{
	stack[++top]=ele;
}

char pop()
{
	return (stack[top--]);
}

int stackprec(char ele)
{
	switch(ele)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '^':
		case '$': return 5; 
		case '(': return 0;
		case '#': return -1;
		default : return 7;
	}
}

int inputprec(char ele)
{
	switch(ele)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '^':
		case '$': return 6;
		case '(': return 9;
		case ')': return 0;
		default : return 7;
	}
}

void intopost(char infix[SIZE],char postfix[SIZE])
{
	int i,j=0;
	char ch;
	push('#');
	
	for(i=0;infix[i]!='\0';i++)
	{
		ch=infix[i];
		while(stackprec(stack[top])>inputprec(ch))
		{
			postfix[j++]=pop();
		}
		
		if(stackprec(stack[top])!=inputprec(ch))
		{
			push(ch);
		}
		else
		{
			pop();
		}
	}
	while(stack[top]!='#')
	{
		postfix[j++]=pop();
	}
	
	postfix[j]='\0';
}

int main()
{
	char infix[SIZE],postfix[SIZE];
	printf("\n Enter an infix expression :  ");
	gets(infix);
	intopost(infix,postfix);
	printf("\n Postfix Expression of   %s   is   %s    \n",infix,postfix);
	return 0;
}
