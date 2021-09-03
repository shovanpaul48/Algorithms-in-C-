//---------------------  KRUSKAL ALGORITHM (UNDIRECTED)  ------------------

#include<stdio.h>
#include<stdlib.h>


typedef struct sets
{
    int set[20];
};

int temp=99999,max_edge,MST=0,Count=0;
int n,Edges[20][20],steps, mainset[20];
// int parent[20],rank[20];
struct sets arr[20];


int main()
{
    int i,ver,j;
    
    printf("---------------------   KRUSKAL algorithm (undirected)  --------------------------\n");
    GRAPH();

    printf("Entered Matrix is : \n");     // Print the Given Matrix

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d    ",Edges[i][j]);
        printf("\n");
    }

    SORT(steps);

//    printf("After Sort the matrix is :\n");
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=n;j++)
//            printf("%d ",Edges[i][j]);
//        printf("\n");
//    }
//
//    printf("\n\n\-------------------------------------------------------------------\n");
//

    printf("The Minimum Spanning Tree is : %d",MST)

}


//---------------------- CREATE THE GRAPH  -----------------------
int GRAPH()         
{
    int i,start,end,cost,j;
    printf("Enter the total number of  vertices :  ");
    scanf("%d",&n);
    max_edge=(n*(n-1)/2);

    for(i=1;i<=n;i++)                  
    {
        mainset[i]=-1;
        for(j=1;j<=n;j++)
        	arr[i].set[i]=-1;
    	//parent[i] = -1;             // Initially all element of parent is -1 
        //rank[i] = 0;                // Initially all element of rank is 0 
	}

    for(i=1;i<=n;i++)                         // All element of matrix is -1 and LEFT DIAGONAL 0
        for(j=1;j<=n;j++){
            if(i!=j)
                Edges[i][j] = -1;
            else
            	Edges[i][j] = 0;
		}

    printf("Insert the Edges :\n");
    printf("!!! Enter -1 -1 -1 to stop insertion \n");


    for(i=1;i<=max_edge;i++)
    {
        scanf("%d %d %d",&start,&end,&cost);
        if(start== -1 && end == -1 && cost == -1 )
            break;
        else if(start<0 || end <0  || start>n || end >n)
            printf("Entered edge is Invalid\n");
        else{
        	Edges[start][end]=cost;
        	Edges[end][start]=cost;
		}

    }
    max_edge = i - 1;
    steps = 1;
}

// -------------------- SORT the Edges --------------------------
int SORT()       
{    int i,j,p,q,temp = 99999;

	while((steps <= max_edge) ){
	for(i=1;i<=n;i++)
	    {
	    	for(j=1;j<=n;j++)
	//               if(j>i){
	//                     if(( Edges[i][k] > 0 && Edges[i][k] < temp ) && (Edges[i][j] > 0 && Edges[i][j] < temp))
	//                          if(Edges[i][j] > Edges[i][j])
	            if(Edges[i][j] > 0 && Edges[i][j] < temp){
	                temp = Edges[i][j];
	                p = i;
	                q = j;
	            }
	//          }
	    }
	    KRUSKAL(p,q);
	    //printf("%d\t %d\t %d\n",p,q,Edges[p][q]);
	    steps++;
	    Edges[p][q] = Edges[q][p] = -1;
	    SORT();
		}


}

//---------------- KRUSKAL MAIN LOGIC --------------------------------
int KRUSKAL(int p, int q)  
{
	int i,j;
	
	if(Count <= n-1)                               
	{
		if(Count == 0){                                                // Initially fast two element  goes into mainset
			mainset[p] = mainset[q] = 1;
			MST = Edges[p][q] + MST;
	        Count ++;
	        PRINT(p,q);
		}
		
		else if(mainset[p] == -1 && mainset[q] == 1){                  // checking if q exist in mainset but not p
			mainset[p]= mainset[q] = 1;                                 // do p and q '1' in main set
			if(arr[p].set[p] == 1){                                     // Check if p has a sub set or not
				for(j=1;j<=n;j++){          
					if(arr[p].set[j] == 1){                     /* if p has a subset then put the adjoint element in the 
					                                               mainset (do mainset = 1) and change the value of subset  to '-1' */
						//printf("%d  ",arr[p].set[j]);
						mainset[j] = 1;
						arr[p].set[j] = -1;                      // Change value to -1 of the subset of p
						arr[q].set[j] = -1;                        // Change value to -1 of the subset of q
					}
				}
				//printf("\n");
			}
			MST = Edges[p][q] + MST;
	        Count ++;
	        PRINT(p,q);
		}
		
		else if(mainset[p] == 1 && mainset[q] == -1 ){          // checking if p exist in mainset but not q
			mainset[p]= mainset[q] = 1;						    // do p and q '1' in main set
			if(arr[q].set[q] == 1){							    // Check if q has a sub set or not
				for(j=1;j<=n;j++){
					if(arr[q].set[j] == 1){					/* if q has a subset then put the adjoint element in the 
					                                        mainset (do mainset = 1) and change the value of subset  to '-1' */										
						//printf("%d  ",arr[p].set[j]);
						mainset[j] = 1;
						arr[q].set[j] = -1;                    // Change value to -1 of the subset of q
						arr[p].set[j] = -1;                     // Change value to -1 of the subset of p
					}
				}
				//printf("\n");
			}
			MST = Edges[p][q] + MST;
	    	Count ++;
			PRINT(p,q);		
		}
		
		else if(mainset[p] == 1 && mainset[q] == 1){     // Check if p and q in the same set or not 
			Count = Count;                               // if yes the do nothong  
			MST = MST ;
		}
		
		//************ ccheck if p and q both are not in mainset but p or q any one of them has a subset *************
		else if((arr[p].set[p] == 1) || (arr[p].set[q] == 1) && ((mainset[p] == -1) && (mainset[q] == -1))){
			arr[p].set[p] = arr[p].set[q] = 1;             //do subset of p for p and q = 1 
			arr[q].set[p] = arr[q].set[q] = 1;             //do subset of q for p and q = 1
			MST = Edges[p][q] + MST;                        // increase the MST
	        Count ++;                                  
	        PRINT(p,q);
	
		}
		
		else if((mainset[p] == -1 && mainset[q] == -1 ))  // if p and q both are not in mainset then 
		{
			arr[p].set[p] = arr[p].set[q] = 1;             //do subset of p for p and q = 1 
			arr[q].set[p] = arr[q].set[q] = 1;             //do subset of q for p and q = 1
			MST = Edges[p][q] + MST;                        // increase the MST
	        Count ++;                                  
	        PRINT(p,q);
		}
		
		
	}
}


//--------------------- PRINT THE SETS -------------------------------
int PRINT(int p, int q)  
{
	int i,j,oth[20];
	for(i=1;i<=n;i++){                           // oth used to store single vertex set  
		oth[i] = -1;                             // initially all element of oth is set to -1
 	}
 	
 	if(Count == 1)
 		printf("Steps \t\tEdge Consider \t\t Connected Component \n");
 	
	printf("%d\t\t {%d,%d} \t\t",Count,p,q);    // Print the step number and selected vertex 
	
	



	
    // print the mainset
	printf("{");
	for(i=1;i<=n;i++){
		if(mainset[i] == 1)
		{
			oth[i] = -1;                     // if sub set found for i then i is not single set
			printf("%d,",i);
		}
		else
			oth[i] = 1;                     // if sub set not found for i then i is  single set
	}
	printf("},");
	

	
	
	// print if any sub set create
	printf("{");                             
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		{
			if(arr[i].set[j] == 1) //&& ( i>j)) // Check if i,j has sub set then print , (j>i) logic used to print the data one time 
			{                                  // if (j > i) not used then the data print for(i,j and j,i as undirected graph) 
				oth[j] = -1;
				// printf("i=%d,j=%d  ",i,j);                  // if sub set found for i then i is not single set
				printf("%d,",j);
			}
			else
				oth[i] = 1;              // if sub set not found for i then i is  single set
		}
	}
	printf("}");
	
	for(i=1;i<=n;i++)
		if(oth[i] == 1)
			printf("{%d},",i);

	
	printf("\n");
	
}



/*       -------------------- KRUSKAL LOGIC ---------------------------------
    if(Count <= n-1 )
    {
		if( mainset[p] == 1 )     // If it is true that means p  or q is in main set
		{
			if(arr[p].set[p] == 1)
			{
				printf("11:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[q] = 1;
				arr[p].set[p] == -1;
				arr[p].set[q] == -1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}
			else if(arr[q].set[p] == 1)
			{
				printf("12:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[q] = 1;
				arr[q].set[p] == -1;
				arr[q].set[q] == -1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}
			else{
				printf("13:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[q] = 1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}		

		}
		else if(mainset[q] == 1 ) // If it is true that means  q is in main set
		{
			if(arr[p].set[q] == 1)
			{	
				printf("21:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[p] = 1;
				arr[p].set[p] == -1;
				arr[p].set[q] == -1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}
			else if(arr[q].set[q] == 1 )
			{
				printf("22:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[p] = 1;
				arr[q].set[p] == -1;
				arr[q].set[q] == -1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}
			else{
				printf("23:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[p] = 1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}

		}
		
		else if( ( mainset[p] != 1 ) && (mainset[q] != 1 ) )
		{
			if(Count == 0 )
			{
				printf("31:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				mainset[p] = 1;
				mainset[q] = 1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;
			}
			else{
				printf("12:mainset[p] =  %d  | arr[p].set[p] =  %d | arr[p].set[q] = %d |p = %d | q= %d\n",mainset[p],arr[p].set[p],arr[p].set[q],p,q);
				arr[p].set[p] = 1;
				arr[p].set[q] = 1;
				PRINT(p,q);
				Count++;
				MST = Edges[p][q] + MST;				
			}
		}

    }

*/
