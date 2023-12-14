

#include<stdio.h>
int front=-1,rear=-1,q[25];
//int graph[5][5]={{0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,0},{0,1,1,0,1},{0,1,0,1,0}};
int graph[5][5];
int visit[5]={0,0,0,0,0};
int v,e,type;

void getmatrix(int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{	
		for(j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}

}
void creatematrix(int v,int e,int type)
{
	int i,j;
	int e1,e2;
	for(i=0;i<v;i++)
	{	
		for(j=0;j<v;j++)
		{
			graph[i][j]=0;
		}
	}
	for(i=0;i<e;i++)
	{
		scanf("%d" ,&e1);
		scanf("%d" ,&e2);
		graph[e1][e2]=1;
		if(type==2)
		graph[e2][e1]=1;
		
	}	
}


void enq(int item)
{   
    
	if(rear==24)
	{
	        printf("Queue is full\n");
	}
    	else if(rear==-1 && front==-1)
    	{
    		front=rear=0;
    		q[rear]=item;
    	}
    	else
	{
        	rear++;
        	q[rear]=item;
    	}
}
int deq()
{
	int item=0;
    	if(front==-1)
	{
	 	printf("Queue is empty\n");
 	}
    	else if(front==rear)
	{
		item=q[front];
	        front=rear=-1;
	}
    	else
	{
		item=q[front];
        	front++;
        }
	return item;
}

void bfs(int s)
{
	int V,i;
	enq(s);
	while((front!=-1)&&(rear!=-1))
	{
		V=deq();
		
		if(visit[V]!=1)
		{
			visit[V]=1;
			printf("%d ",V);
			for(i=0;i<5;i++)
			{
				if(graph[V][i]==1)
					enq(i);

			}

		}
	}

}


void disp_graph()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		 printf("%d ",graph[i][j]);
	
		printf("\t");	
	}


}





int main()
{  
	printf("enter the number of vertices:\t");
	scanf("%d",&v);
	
	
	printf("enter the type of graph (enter 1 for directedgraph and 2 for undirected graph):\n");
	scanf("%d",&type);
	
	printf("Enter the number of edges:");
	scanf("%d",&e);
	
	creatematrix(v,e,type);	
	
	printf("\nTHE MATRIX OF GRAPH: \n");
	disp_graph();
	printf("\nTHE BFS TRAVERSAL OF VERTICES ARE: ");	
	bfs(0);
	

    return 0;

}
