//-----------------     BFS (Breath First Search Algorithm )        -----------------------

#include<stdio.h>
#include<stdlib.h>
#define visited 1

int n,Edges[20][20],queue[20],visited_Array[20];
int rear = - 1;
int front = - 1;

int main()
{
    int i,ver;
    printf("---------------------   BFS algorithm  --------------------------\n");
    Graph();  // 0 1 2 3 4 5 6 7
/*    Edges[20][20]={
				{0,1,1,1,1,0,0,0},//0
				{1,0,0,0,0,1,0,0},//1
				{1,0,0,0,0,1,0,0},//2
				{1,0,0,0,0,0,1,0},//3
				{1,0,0,0,0,0,0,1},//4
				{0,1,1,0,0,0,0,0},//5
				{0,0,0,1,0,0,0,1},//6
				{0,0,0,0,1,1,0,0} //7
				}; */
    
    printf("Enter the starting vertex:\n");
    scanf("%d",&ver);

	printf("Queue Content \t   Visited_Array \t\t Visited Vertex\n");
	        //---------------- Print QUEUE CONTENT -------------------
        if (front == - 1)
            printf("Empty\t\t");
        else
        {  
            for (i = front; i <= rear; i++)
                printf("%d ",queue[i]);
            printf("\t\t");
        }
        //---------------- Print VISITED ARRAY -------------------
        printf("[");
		for(i=0;i<n;i++)
            printf("%d,",visited_Array[i]);
        printf("]\t\t");

        //---------------- Print VISITED VERTEX -------------------
        printf("%d\n",ver);
        
    BFS(ver);
    
}

int Graph()
{
    int i,max_edge,start,end;
    printf("Enter the total number of  vertices :  ");
    scanf("%d",&n);
    max_edge=(n*(n-1))/2;

     printf("Insert the Edges :\n");
     printf("!!! Enter -1 -1 to stop insertion \n");

	//---------------Initially Visited Array is 0     
	for(i=1;i<=n;i++)
         visited_Array[i] = 0;                   

    for(i=1;i<=max_edge;i++)
    {
        scanf("%d %d",&start,&end);
        if(start== -1 && end == -1)
            break;
        else if(start<0 || end <0  || start>n || end >n)
            printf("Entered edge is Invalid\n");
        else
            Edges[start][end]=1;
     }
}

int BFS(int ver)
{
    int i;
    Enqueue(ver);
    while(!CheckEmpty())
    {
        ver=Dequeue();       // Deleted vertex
        visited_Array[ver]= visited;
        //---------------- Print QUEUE CONTENT -------------------
        if (front == - 1)
            printf("Empty\t\t");
        else
        {  
            for (i = front; i <= rear; i++)
                printf("%d ",queue[i]);
            printf("\t\t");
        }
        //---------------- Print VISITED ARRAY -------------------
        printf("[");
		for(i=0;i<n;i++)
            printf("%d,",visited_Array[i]);
        printf("]\t\t");

        //---------------- Print VISITED VERTEX -------------------
        printf("%d\n",ver);

        for(i=0;i<n;i++)
        {
            if(Edges[ver][i] == 1  && visited_Array[i] != visited)
            {
                Enqueue(i);
            }
        }
    }
}

int Enqueue(int s)
{
    if (rear == 20-1)
        printf("Queue is Full \n");

    else 
	{
		if (front == - 1)
			front = 0;
	    rear ++;
	  	queue[rear] = s;           // enter source 
	}
}

int Dequeue()
{
    int del;
    if(front == -1 || front > rear)
    {
        printf("The Queue is Empty \n");
        exit(1);
    }
    del=queue[front];
    front++;
    return del;

}

int CheckEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
