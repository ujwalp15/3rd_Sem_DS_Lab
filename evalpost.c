/*
Lab Program 4
Infix to Postfix
Author ujwalp15
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define SIZE 10
int top=-1;
float stack[SIZE];

void push(float ele)
{
	stack[++top]=ele;
}

float pop()
{
	return (stack[top--]);
}

float evalpost(char postfix[SIZE])
{
	int i;
	float op1,op2,res;
	char ch;
	
	for(i=0;postfix[i]!='\0';i++)
	{
		ch=postfix[i];
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else
		{
			switch(ch)
			{
				case '+': op2=pop();
					  op1=pop();
					  res=op1+op2;
					  push(res);
					  break;
				case '-': op2=pop();
					  op1=pop();
					  res=op1-op2;
					  push(res);
					  break;
				case '*': op2=pop();
					  op1=pop();
					  res=op1*op2;
					  push(res);
					  break;
				case '/': op2=pop();
					  op1=pop();
					  if(op2==0)
					  {
						printf("\n Divide by zero error\n\n");
						break;
					  }
				 	  res=op1/op2;
					  push(res);
  					  break;
				case '$':
				case '^': op2=pop();
					  op1=pop();
					  res=op1-op2;
					  push(res);
					  break;
				default:  printf("\n Invalid Postfix expression!!!!\n\n");
					  break;
			}
		}
	}
	res=pop();
	return (res);
}

int main()
{
	char postfix[SIZE];
	float res;
	printf("\n Enter the valid postfix expression :   ");
	gets(postfix);
	res=evalpost(postfix);
	printf("\n Result of    %s     is     %f     \n\n",postfix,res);
	return 0;
}
