/*
  Author:
  Ashutosh Kumar
  @an_shuman777
  Graph adjacency matrix
*/
#include<bits/stdc++.h>
using namespace std;
#define Max 1000
int adjMatrix[Max][Max];
int Pmatrix[Max][Max];

//Graph representation using adjacency Matrix
class Graph{
public:
    void createAdjMatrix(int adjMatrix[Max][Max],int n);
    void display(int adjMatrix[Max][Max],int n);
    void pathMatrix(int adjMatrix[Max][Max],int n);
};

void Graph::createAdjMatrix(int adjMatrix[Max][Max],int n){
    int origin,destination,edges,weight;
    cout<<"Enter your choice Either 'Directed or Undirected' Graph: "<<endl;
    string graph_type;
    cin>>graph_type;
    if(graph_type[0]=='D'){
        cout<<"Enter the number of edges of Directed Graph: "<<endl;
        cin>>edges;
        cout<<"Enter the edges in the format 'Source -> Destination -> Weight': "<<endl;
        for(int var=0;var<edges;var++){
            cin>>origin>>destination>>weight;
            adjMatrix[origin][destination]=weight;
        }
    }
    else{
        cout<<"Enter the number of edges of Undirected Graph: "<<endl;
        cin>>edges;
        cout<<"Enter the edges in the format 'Source -> Destination': "<<endl;
        for(int var=0;var<edges;var++){
            cin>>origin>>destination;
            adjMatrix[origin][destination]=1;
            adjMatrix[destination][origin]=1;
        }
    }
}

void Graph::display(int adjMatrix[Max][Max],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Path matrix using warshall's Algorithm
void Graph::pathMatrix(int adjMatrix[Max][Max],int n){
    for(int l=0;l<n;l++){
        for(int m=0;m<n;m++){
            Pmatrix[l][m]=adjMatrix[l][m];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Pmatrix[i][j]=(Pmatrix[i][j] || (Pmatrix[i][k] && Pmatrix[k][j]));
            }
        }
    }
}

int main()
{
    int vertex;
    cout<<"Enter the number of Vertex in the Graph: "<<endl;
    cin>>vertex;
    Graph G;
    G.createAdjMatrix(adjMatrix,vertex);
    cout<<"Adjacency Matrix for Graph is: "<<endl;
    G.display(adjMatrix,vertex);
    G.pathMatrix(adjMatrix,vertex);
    cout<<"Path Matrix for Graph is: "<<endl;
    G.display(Pmatrix,vertex);
    return 0;
}
