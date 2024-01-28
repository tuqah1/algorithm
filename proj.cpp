#include<bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

int minDistance(int dist[],bool visited[]){
    // Initialize min value
    int minV= INT_MAX, min_vertex;
       for(int i=0; i < V; i++){
            if( visited[i] == false && dist[i] <= minV)
               minV = dist[i], min_vertex = i;

    }
    return min_vertex;
}

 void printShortestpath(int dist[]){
       cout << "Vertex \t  shortest Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
 }

void dijkstra(int graph[V][V],int src){

    int dist[V];//will contain the shortest path (the output array)
                //dist[i] will contain the distance from src to i


    bool visited[V]; //visited[i] will true be if the vertex i
                    // is included to shortest path tree from src to i (is finlized)

    // Initialize all distances as INFINITE and visited[] as
    // false
    for(int i=0; i < V; i++){
        dist[i]=INT_MAX, visited[i]= false;
    }

     // Distance of source vertex from itself is always equal 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for(int c = 0; c < V - 1 ; c++){

        // Pick the minimum distance vertex from the set of
        // vertices not yet processed (closest vertex).
        //u is always equal tosrc in the first iteration.

       int u = minDistance(dist,visited);

       // Mark the picked vertex as processed(shortest path done)
       visited[u] = true;

       // Update dist value of the adjacent vertices of the
       // picked vertex.
       for(int v=0; v <V; v++){

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
             if( !visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v] )
            dist[v] = dist[u] + graph[u][v];
       }
     }




     // print the constructed distance array
    printShortestpath(dist);
 }




int main(){
        /* Let us create the example graph discussed above */
    int graph[V][V] ;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
                        /*0 6 0 1 0
                         6 0 5 2 2
                         0 5 0 0 5
                         1 2 0 0 1
                         0 2 5 1 0 */


    // Function call

     /*int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };*/
    dijkstra(graph, 0);
return 0;}

