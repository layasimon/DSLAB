#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*rearlink;
	int data;
	struct node*frontlink;
};
struct node*header=NULL;
void insfrnt(int item)
{
	struct node*new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->rearlink=NULL;
	if(header==NULL)
	{
		header=new;
		new->frontlink=NULL;
		printf("\nElement succesfully inserted at position 1\n");
	}
	else
	{
		header->rearlink=new;
		new->frontlink=header;
		header=new;
		printf("\nelement succesfully inserted atposition 1\n");
	}
}
void insend(int item)
{
	struct node*new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->frontlink=NULL;
	int count=0;
	if(header==NULL)
	{
		header=new;
		new->rearlink=NULL;
		printf("\n element succesfully inserted at position 1\n");
	}
	else
	{
		struct node*temp=header;
		while(temp->frontlink!=NULL)
		{
			temp=temp->frontlink;
			count++;
		}
		temp->frontlink=new;
		new->rearlink=temp;
		printf("\n element succesfully inserted at position%d\n",count+2);
	}
}
void inspos(int item,int key)
{
	struct node*new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	struct node*temp=header;
	int count=0;
	while((temp->data!=key) &&(temp->frontlink!=NULL))
	{
		temp=temp->frontlink;
		count++;
	}
	if((temp->frontlink==NULL)&&(temp->data==key))
	{
		new->frontlink=NULL;
		new->rearlink=temp;
		temp->frontlink=new;
		printf("\n element succesfullyinderted at position %d\n",count+2);
	}
	else if((temp->frontlink==NULL)&&(temp->data!=key))
	{
		printf("\n key not found\n");
	}
	else
	{
		new->frontlink=temp->frontlink;
		temp->frontlink=new;
		new->rearlink=temp;
		temp=new->frontlink;
		temp->rearlink=new;
		printf("\n ELement succesfully inserted at position %d\n",count+2);
	}
}
void delfrnt()
{
	if(header==NULL)
	{
		printf("\n list is empty\n");
	}
	else if(header->frontlink==NULL)
	{
		printf("element succesfully deleted:%d\n",header->data);
		free(header);
		header=NULL;
	}
	else
	{
	struct node*temp=header;
	printf("\n element deleted succesfully:%d\n", temp->data);
	header=temp->frontlink;
	header->rearlink=NULL;
	free(temp);
	}
}
void delend()
{
	if(header==NULL)
	printf("\n list is empty\n");
	else if(header->frontlink==NULL)
	{
		printf("\n element deleted succesfully:%d\n",header->data);
		free(header);
		header==NULL;
	}
	else
	{
		struct node*temp1=header;
		struct node*temp2=header;
		while(temp1->frontlink!=NULL)
		{
			temp2=temp1;
			temp1=temp1->frontlink;
		}
	printf("\n element deleted succesfully:%d\n",temp1->data);
	temp1->rearlink=NULL;
	temp2->frontlink=NULL;
	free(temp1);
	}
}
void delpos(int key)
{
	if(header==NULL)
	{	
	printf("\n list is empty\n");
	}	
	else
	{
		struct node*temp1=header,*temp2=header;
		while((temp1!=NULL)&&(temp1->data!=key))
		{
			temp2=temp1;
			temp1=temp1->frontlink;
		}
		if(temp1==NULL)
		{
			printf("\n key not found\n");
		}
		else
		{
			if(temp2->frontlink==NULL)
			{
				printf("\n element deleted succesfully:%d\n",temp2->data);
				free(temp2);
				header=NULL;
			}
			else
			{
				printf("\n Element deleted succesfully:%d\n",temp1->data);
				if(temp1==header)
				{
					header=temp1->frontlink;
					header->rearlink=NULL;
				}
				else
				{
					temp2->frontlink=temp1->frontlink;
					temp2=temp1->frontlink;
					if(temp2!=NULL)
					{
					temp2->rearlink=temp1->rearlink;
					}
				
				}
		free(temp1);
		}
	}
}
}
void disp()
{
	if(header==NULL)
	{
		printf("\n list is empty\n");
	}
	else
	{
		struct node*temp=header;
		printf("\n-----entered elements are------\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->frontlink;
		}
	printf("\n");
	}
}
void srch(int key)
{
	int count=0;
	if(header==NULL)
	{
		printf("\nkey not found\n");
	}
	else
	{
		struct node*temp1=header;
		while((temp1!=NULL)&&(temp1->data!=key))
		{
			temp1=temp1->frontlink;
			count++;
		}
		if(temp1==NULL)
		{
			printf("\n key not found\n");
		}
		else
		{
			printf("\n key found at position %d\n",count+1);
		}
	}
}
int main()
{
	int k,z,c;
	printf("\n------LINKED LIST OPERATION---\n");
	while(1)
	{
		printf("\n1.Insert at front\n2.Insert at end\n3.Insert after position\n4.Delete at front\n5.Delete at end\n6.Delete node at any position\n7.Display Elements\n8.Search position of Element\n9.Exit");  
       		printf("\nSelect the options\n");         
        	scanf("%d",&c); 	 
        	switch(c)  
        	{  
            		case 1:  
                	printf("\nenter the data to insert at front \n");
			scanf("%d",&z);
                        insfrnt(z);
                        break;
                        case 2:  
                        printf("\nenter the data to insert at end \n");
                        scanf("%d",&z);
                        insend(z);
                        break;
			case 3:  
			if(header==NULL)
			{
				printf("\n-----listis empty----\n");
			}
			else
			{
				disp();
				printf("\n-----select the position----\n");
				scanf("%d",&k);
				printf("enter the data to insert after the position\n");
				scanf("%d",&z);
				inspos(z,k);
			}
			break;
			case 4:  
			delfrnt();       
			break;  
			case 5:  
			delend();        
			break;  
			case 6:
			if (header==NULL)
			{
				printf("list is empty" );
			}
			else
			{
				disp();
				printf("\n---select the position---\n");
				scanf("%d",&k);  
				delpos(k);
			}          
			break;  
			case 7:   
			disp();        
			break;  
			case 8:
 			printf("\n---enter the key---\n");	
			scanf("%d",&k);  
			srch(k);          
			break;  
			case 9:
			printf("\nbye bye..\n");
			exit(0);  
			break;
			 
			default:  
			printf("wrong input..");			
		}
	}
	return 0;
}			















	






























		



























	























































































