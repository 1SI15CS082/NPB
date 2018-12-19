#include<stdio.h> 
#include<stdlib.h>

const int MAXNODES = 10,INF = 9999;
void fnDijkstra(int [][MAXNODES], int [], int [], int[], int, int, int);

int main(void)
{
    int n,cost[MAXNODES][MAXNODES],dist[MAXNODES],visited[MAXNODES],path[MAXNODES],i,j,source,dest;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the Cost Matrix\n");
    
    for (i=0;i<n;i++)
    	for (j=0;j<n;j++)
        scanf("%d",&cost[i][j]);


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
     		if(cost[i][j]!=9999 && i!=j)
		{
                    printf("hello message sent from %d to %d\n",i,j);
               	 	for(int k=0;k<100;k++);
                    printf("echo message sent from %d to %d\n",i,j);
                	
   	  	}
	}
    }

    for (source = 0; source < n; source++)
    {
        printf("//For Source Vertex : %d shortest path to other vertices\n",source);
        for (dest=0; dest < n; dest++)
        {
            fnDijkstra(cost,dist,path,visited,source,dest,n);
            if (dist[dest] == INF)
            printf("%d not reachable",dest);
            else
            {
                printf("\n");
                i = dest;
                do
                {
                    printf("%d <--",i);
                    i = path[i];
                }while (i!= source);
                printf("%d = %d\n",i,dist[dest]);
                
            }
        }
        
    }
    return 0;
}
void fnDijkstra(int c[MAXNODES][MAXNODES], int d[MAXNODES], int p[MAXNODES],int s[MAXNODES], int so, int de, int n)
{
    int i,j,a,b,min;
    for (i=0;i<n;i++)
    {
        s[i] = 0;
        d[i] = c[so][i];
        p[i] = so;
    }
    s[so] = 1;
    for (i=1;i<n;i++)
    {
        min = INF;
        a = -1;
        for (j=0;j<n;j++)
        {
            if (s[j] == 0)
            {
                if (d[j] < min)
                {
                    min = d[j];
                    a = j;
                }
            }
        }
        if (a == -1) return;
        s[a] = 1;
        if (a == de) return;
    
	for (b=0;b<n;b++)
	    {
		if (s[b] == 0)
		{
		    if (d[a] + c[a][b] < d[b])
		    {
		        d[b] = d[a] + c[a][b];
		        p[b] = a;
		    }
		}
	   }
   }
  
}
