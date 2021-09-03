//-------------------------- PRIMS ALGORITHM  ( UNDIRECTED )-------------------------------------

#include<stdio.h>
#include<stdlib.h>

int G[20][20],MST=0,V[20],E[100][100];
int n,max_edge,source,p,q,steps=1;


int main()
{
	int ver;
	printf("----------------------      PRIMS ALGORITHM ( UNDIRECTED )       ---------------------------\n");

	GRAPH();
	//printf("Enter the Starting Vertex :");
	//scanf("%d",&source);

    printf("4\n");
	SORT();                       // Sort algorithm finds lowest cost edge
	
	printf("5 : p =%d ,q =%d\n",p,q);

	printf("Steps \t P,Q \t SET \n");
	PRIMS();

	printf("The minimum cost spanning tree is : %d ",MST);

}

//------------------  CREATING THE GRAPH   ---------------------------
int GRAPH()
{
	int i, j,start, end, cost;

	printf("\nEnter the  total Number of vertices : ");
	scanf("%d",&n);
	printf("1\n");


    max_edge = n*(n-1) / 2;                                    // Calculating max edge

	for(i=1;i<=n;i++){
		V[i] = - 1;                                          // V is set store the vartex that is aleady visited , initaially all element -1
		for(j=1;j<=n;j++){
			if(i!=j){
				G[i][j] = -1;                                 // Set All the element of graph G  -1
				E[i][j] = -1;				                  // E set store all edge details
			}
			else{
				G[i][j] = 0;                                  // Set the left Diagonal 0
				E[i][j] = -1;                                // initally all edges are set to -1(that means no edges exist)
			}

		}
	}

    printf("!!! Enter the Source , Destination  and Cost ( To stop enter -1 -1 -1 ) \n");
    for(i=1;i<=max_edge;i++){
        scanf("%d %d %d",&start,&end,&cost);
        if(start == -1 && end == -1 && cost == -1)
            break;
        // else if(end == NULL || cost == NULL ){                  // IF any value not entered then re enter
        //     printf("Entered edge is Invalid\n");
        //     scanf("%d %d %d",&start,&end,&cost);
        //     Edges[start][end]=cost;
        // }
        else if(start<0 || end <0  || start>n || end >n){          // if enter edge is not possible then re enter
            printf("Entered edge is Invalid\n");
            scanf("%d %d %d",&start,&end,&cost);
            G[start][end] =E[start][end] = cost;
            G[end][start] = E[end][start] = cost;
        }
        else{
        	G[start][end] = E[start][end] = cost;
        	G[end][start] = E[end][start] = cost;
		}


    }
    max_edge = i - 1;
    
}



//------------------  SORT AlGORITHM     -----------------------------
int SORT()
{
	int i, j, temp = 999999;

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(G[i][j] > 0 && G[i][j] < temp){
				temp = G[i][j];
				p = i;
				q = j;
			}
		}
	}
}



//-----------------  PRIM ALGORITHM LOGIC    -------------------------
int PRIMS()
{
	int i,j,k,var;

	 if(steps<=n-1){

			MST= MST + G[p][q];                            // initally storing the first lowest cost edge in MST array
			G[p][q] = -1;                                  // It means G[p][q] = - 1 is no longer use
			                                
			V[p] = V[q] = 1;                               // set V[p] ,V[q] = 1that means vertex p and q are used
			E[p][q] = 0;                                   // Set E[p][q] = 0 that means p-q edge is used


			printf("%d \t %d,%d \t",steps,p,q);
			for(i=1;i<=n;i++)
				if(V[i] > 0)
					printf("%d, ",i);

			printf("\n");

			//---------- Call for next vertices ------------
			ADJACENT_EDGE_SORT();                        // To find the next adjacent lowest cost edge aof p and q
			steps ++;                                    // Increment setps

		PRIMS();
	}
}


//--------------------    SORT THE ADJACENT EDGE ---------------------
int ADJACENT_EDGE_SORT()
{
	int i, j, k, l,temp = 9999;

	for(i=1;i<=n;i++){
		if(V[i] == 1){
		//printf("Temp =%d, p=%d,q=%d i=%d\n",temp,p,q,i);                              // that means V[i] is already used,(find its adjacent vertex)
			for(j=1;j<=n;j++){
				if(V[j] == -1){
					//printf("E[p][q] =%d i=%d j=%d \n",E[p][q],i,j);
					if(E[i][j] > 0 && E[i][j] < temp ){
						temp = E[i][j];
						p=i;
						q=j;
						//printf("Temp =%d, p=%d,q=%d i =%d j=%d\n",temp,p,q,i,j);
					}				
				}	

				
			}
		}
	}
	//printf("Temp =%d, p=%d,q=%d\n",temp,p,q);
}