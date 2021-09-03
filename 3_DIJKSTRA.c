//------------------------ DIJKSTRA ALGORITHM  ( DIRECTED ) ------------------------------

#include<stdio.h>
#include<stdlib.h>

int Edges[20][20],n,max_edge;
int source=-1,steps= 1,TOP = 1;
int c[20],s[20],d[20];


int main()
{
    int i,j,k;
    printf("--------------------      DIJKSTRA ALGORITHM ( DIRECTED ) -------------------------\n");
    GRAPH();

    printf("Entered data matrix is :\n");
    for(i=1;i<=n;i++)                      // printing the given matrix
    {
        for (j=1;j<=n;j++){
            printf("%d    ",Edges[i][j]);
        }
        printf("\n");
    }

    printf("Enter the Source : ");         // User given source
    scanf("%d",&source);

    printf("Steps \t V \t C \t\t S \t\t D \n");
    DIJKSTRA();

    for(i=1;i<=n;i++)
        if(d[i] > 0){
            printf("Cost from %d (source) to %d (destination) : %d \n",source,i,d[i]);
        }

}

//-------------------------- CREATING GRAPH -------------------------------
int GRAPH()
{
    int i,j,start,end,cost;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);

    max_edge = n*(n-1) / 2;

    for(i=1;i<=n;i++){
        for(j=1;j<= n ; j++){
            if(i!=j)
                Edges[i][j] = -1;                         // making all edges -1
            else
                Edges[i][j] = 0;                         // making left diagonal 0
        }
    }

    for(i=1;i<=n;i++){
        c[i] = -1;                            // C store non visited vertex
        //TOP++;
        s[i] = -1;                            // s store visited vertex
        d[i] = -1;                            // d store cost of each vertex from source
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
        else if(start<0 || end <0  || start>n || end >n){       // if enter edge is not possible then re enter
            printf("Entered edge is Invalid\n");
            scanf("%d %d %d",&start,&end,&cost);
            Edges[start][end]=cost;
        }
        else
            Edges[start][end]=cost;

    }
    max_edge = i -1;
}

//----------------------- DIJKSTRA ALGORITHM ---------------------------
int DIJKSTRA()
{

    int v=source, i, j, k, f=0, temp=9999;

    if(steps <=n-1){
        s[1] = source;                              //s store the visited vertices

        if(steps == 1 ){
            for(i=1;i<n+1;i++){
                //TOP=i;
                if(i != source){
                    c[i] = i;                      // c is a stack which store the non visited vertices
                    TOP++;
                }

                if(Edges[source][i] > 0 ){
                    d[i] = Edges[source][i];
                    // if(d[i-1]>0 && d[i]<temp){
                    //     v=i;
                    //     temp=d[i];
                    //}
                }
            }
            printf("\n1 TOP = %d , C[TOP] =%d \n",TOP,c[TOP]);
            printf("%d\t%d\t",steps,v);             // Print Stepes an selected vertex(v)

            for(i=1;i<=TOP;i++)
                if(c[i] != -1)                     // Print  non visited vertexa array (c)
                    printf("%d, ",c[i]);

            printf("\t ");
            for(i=1;i<=n;i++)                        // Print  visited vertex array (s)
                if(s[i] > 0)
                    printf("%d, ",s[i]);

            printf("\t");
            for(i=1;i<=n;i++)                       // Print cost from source vertex array (d)
                if(d[i] > 0)
                    printf("%d, ",d[i]);

            printf("\n");

            steps++;
        }

        else{
        	//printf("\n2 TOP = %d , C[TOP] =%d \n",TOP,c[TOP] );
            v=TOP;
            TOP--;
            for(i=TOP;i>=0;i--){
                for(j=1;j<=n;j++){
                    if(Edges[v][j] > 0){
                        if((Edges[v][j] + Edges[source][v]) < Edges[source][j]){
                            d[j] = Edges[v][j] + Edges[source][v];
                            //TOP --;
                            for(k=1;k<=n;k++){
                                if(f == 0 )
                                    if(s[k] == -1 ){
                                        s[k] = v;
                                        f=f+1;
								}
                            }
                        }
                    }
                }
        	}
            //printf("\n2 TOP = %d , C[TOP] =%d \n",TOP,c[TOP] );
            printf("%d\t%d\tc=>",steps,v);             // Print Stepes an selected vertex(v)

            for(i=1;i<=TOP;i++)                     // Print  non visited vertexa array (c)
            	if(c[i]  > 0)
                	printf("%d, ",c[i]);

            printf("\ts=>");
            for(i=1;i<=n;i++)                        // Print  visited vertex array (s)
                if(s[i] > 0)
                    printf("%d, ",s[i]);

            printf("\td=>");
            for(i=1;i<=n;i++)                       // Print cost from source vertex array (d)
                if(d[i] > 0)
                    printf("%d, ",d[i]);

            printf("\n");


            steps++;
        }
        DIJKSTRA();
    }
}
