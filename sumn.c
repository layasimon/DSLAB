#include<stdio.h>
int main()
{
	int a[50];
	int sum=0;
	int n,i;
	printf("enter the number of elemets");
	scanf("%d",&n);
	if(n<=50)
{
	printf("enter the values");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	sum=sum+a[i];
	}
	printf("sum of array is%d",sum);
}
	else
	printf("error");
}
