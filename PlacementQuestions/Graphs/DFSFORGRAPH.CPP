

/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Example 1:

Input:

Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 1 2 4 3.
Example 2:

Input:

Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 0, 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3. 

Your task:
You don't need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:

Time complexity: O(N+E), Where N is the time taken for visiting N nodes and E is for travelling through adjacent nodes.

Space Complexity:O(N+E)+O(N)+O(N) , Space for adjacency list, Array,Auxiliary space.

*/

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> &vis,vector<int> &dfsstore,vector<int> adj[]){
          vis[node]=1;
          dfsstore.push_back(node);
          for(auto it:adj[node]){
              if(!vis[it]){
              vis[it]=1;
             dfs(it,vis,dfsstore,adj);
              }
          }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>dfsstore;
        vector<int>vis(V+1,0);
        int start=0;
       dfs(start,vis,dfsstore,adj);
       return dfsstore;
        
        
    }
};

//for disconnected graph


#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj, storeDfs); 
      }
	    return storeDfs; 
	}
};
 
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<int> adj[6];
    
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);
    Solution obj;
    vector<int> df;
    df= obj.dfsOfGraph(5, adj);
    for(auto it: df)
    cout<<it<<" ";
 
    return 0;
}
Output:

1 2 4 3 5
