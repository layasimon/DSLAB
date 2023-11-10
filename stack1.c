#include<stdio.h>
#include<stdlib.h>
int push();
void pop();
void display();
int stackarr[100],temp;
int max=5;
int top=-1,i;
void main()
{
	int choice;
	printf("implementation of stack using array");
	while(1)
	{
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.display");
		printf("\n4.exit");
                printf("enter your choice(1/2/3/4)");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nenter the elements to push");
			       scanf("%d",&temp);
			       push(temp);
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(1);
			       break;
			default:printf("\n invalid input");
		}
	}
}
int push()
{
	
	if(top<max)
	stackarr[++top]=temp;
	else
	printf("stack is full");
}
void pop()
{
	if(top<0)
	printf("stack is empty");
	else
	{
		printf("the poped element is:%d\n",stackarr[top]);
		top--;
	}
}
void display()
{
	if(top==-1)
	printf("\nstack is empty");
	/*else
	{
		printf("elements are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stackarr[i]);
		}
	}*/
	else
	{
		printf("elements are:\n");
		for(i=0;i<=top;i++)
		{
			printf("%d\n",stackarr[i]);
		}
	}
}




  			
		


