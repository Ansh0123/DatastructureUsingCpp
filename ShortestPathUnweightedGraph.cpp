/*
  Author:
  Ashutosh Kumar
  @an_shuman777
  Graph -> Shortest Path 
 */

#include <bits/stdc++.h>
using namespace std;

void modifiedBFS(int graph[7][7],int source,int n,int distance[]){
	distance[source]=0;
	queue<int>q;
	q.push(source);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v=0;v<n;v++){
			if(graph[u][v]==1 and distance[v]==-1){
				distance[v]=distance[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
    int n=7;
    /*Graph with adjacency matrix representation */
    /*For implementation of adjacency matrix you may see the previous graph repository*/
	int g[7][7]={
			{0,1,0,1,0,0,0},
			{0,0,0,1,1,0,0},
			{1,0,0,0,0,1,0},
			{0,0,1,0,0,1,1},
			{0,0,0,0,0,0,1},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,1,0}};
    /* to store the shortest distance of each vertex from source vertex */
	int distance[n];
	for(int i=0;i<n;i++){
		distance[i]=-1;
	}
    modifiedBFS(g,0,n,distance);
    /* Shortest distance from 0th vertex */
	for(auto x:distance){
		cout<<x<<" ";
	}
	/* 0 1 2 1 2 2 2 */
	return 0;
}
