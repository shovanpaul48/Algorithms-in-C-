//---------------------- DFS  ----------------------------       


#include<stdio.h>
#include<stdlib.h>
#define visited 1

int TOP =-1;
int n,Edges[20][20],stack[20],visited_Array[20];

int main()
{
    int i,ver;
    printf("---------------------   DFS algorithm  --------------------------\n");
    Graph();
    
    printf("Enter the starting vertex:\n");
    scanf("%d",&ver);

	printf("stack Content \t   Visited_Array \t\t Visited Vertex\n");
        //---------------- Print STACK CONTENT -------------------
    if (TOP== - 1)
        printf("EMPTY\t\t");
    else
    {  
        for (i = 0; i <= TOP; i++)
            printf("%d ",stack[i]);
        printf("\t\t");
    }
    //---------------- Print VISITED ARRAY -------------------
    printf("[");
	for(i=0;i<n;i++)
        printf("%d,",visited_Array[i]);
    printf("]\t\t");

    //---------------- Print VISITED VERTEX -------------------
    printf("%d\n",ver);
    PUSH(ver);
    DFS(ver);
    printf("End main");
    
}

int DFS(int ver)
{
    int i,l;
    if(stack[TOP] != ver)
    {
    	PUSH(ver);
	}

    while(!CheckEmpty())
    {
    	visited_Array[ver] = visited;

        
        
		POP();                           //  delete top vertex and then enter adjacent vertices
		
        for(i=0;i<n;i++)
        {
//            if((Edges[ver][i] == 1 &&  visited_Array[i] == 0 ) || ( Edges[i][ver] == 1 && visited_Array[ver] == 0))
			if(Edges[ver][i] == 1  &&  visited_Array[i] == 0 )
            {
           		PUSH(i);
				
			}
        }
        		//---------------- Print STACK CONTENT -------------------
        if (TOP == - 1)
            printf("EMPTY\t\t");
        else
        {  
            for (i = 0; i <= TOP; i++)
                printf("%d ",stack[i]);
            printf("\t");
        }
        //---------------- Print VISITED ARRAY -------------------
        printf("[");
		for(i=0;i<n;i++)
            printf("%d,",visited_Array[i]);
        printf("]\t\t");

        //---------------- Print VISITED VERTEX -------------------
        printf("%d\n",ver);
		DFS(stack[TOP]); 	
	}
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
        {
        	Edges[start][end]=1;
        	Edges[end][start]=1;
		}
            
     }
}


void PUSH(int s)
{
	int l;
	if(TOP == n-1)
	    printf("FULL\n");
	else
	{
//		for(l=0;l<=TOP;l++)
//			if(stack[l] !=  s)
//				break;
//			else
//			{
				TOP++;
				stack[TOP]= s; // Store the source
//			}

	}
}
void POP()
{
	if(TOP==-1)
	    printf("EMPTY");
	else
		TOP--;
}
int CheckEmpty()
{
    if(TOP == -1 || TOP > n)
        return 1;
    else
        return 0;
}
