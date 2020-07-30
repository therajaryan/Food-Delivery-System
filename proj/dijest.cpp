// Example program
#include <bits/stdc++.h>

using namespace std;


int  MAX = 9999;
int  MIN = -9999;
#define V  9
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };


int dist[V];
int parent[V];
bool marked[V];
void mark42(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    mark42(parent, parent[j]);
    marked[j]=true;
    cout<<j<<" ";
}

int minDistance(int dist[], bool sptSet[])
{
   int min1 = MAX;
   int min_index=0;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min1)
         min1 = dist[v], min_index = v;

   return min_index;
}


/*int printSolution(int dist[], int n)
{
   cout<<"Vertex   Distance from Source";
   for (int i = 0; i < V; i++)
   {


       cout<< i << " " << dist[i];
       cout<<endl;
   }
} */

void dijkstra(int graph[V][V], int src )
{
     parent[0]=-1;

     bool sptSet[V];

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
        {


         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
                                       {


            parent[v] = u;
            dist[v] = dist[u] + graph[u][v];
                                       }
        }
     }


    /*cout<<"from"<<" "<<src<<" "<<"to"<<" "<<dest<<" "<<dist[dest];
    cout<<endl;*/
    /*printPath(parent,dest);
     // print the constructed distance array*/

}


int home()
{
    int x;
    cout<<"enter your choice"<<endl;
    cout<<"1. inventory"<<endl;
    cout<<"2.delivery"<<endl;
    cin>>x;
    return x;
}




int main()
{

    int y,a;
    y=home();
    if(y==2)
    {
         dijkstra(graph, 0);
        cout<<"delivery system"<<endl;
        cout<<endl;
        cout<<"enter your location"<<endl;
        cin>>a;
        for(int i=0;i<V;i++)
    {
        marked[i]=false;
    }
        mark42(parent,a);
    }
    return 0;
}

