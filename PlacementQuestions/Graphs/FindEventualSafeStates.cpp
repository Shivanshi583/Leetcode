/*
Find Eventual Safe States
Medium
3K
342
Companies
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].
*/

//using DFS
class Solution {
public:
bool dfs(int src, vector<int>& vis, vector<int>& pathvis, vector<int>& check,vector<vector<int>>& graph){
    vis[src]=1;
    pathvis[src]=1;
    for(auto it:graph[src]){
        if(!vis[it]){
            pathvis[it]=1;
            if(dfs(it,vis,pathvis,check,graph)==true) {
                check[src]=0;
                return true;
            }
        }
        else if(pathvis[it]){
            check[src]=0;
            return true;
        }
        

    }
    check[src]=1;
        pathvis[src]=0;
        return false;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>vis(n,0);
         vector<int>pathvis(n,0);
          vector<int>check(n,0);
        vector<int>safenodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,check,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) {
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();       
        vector<int> visited(n, 0), ans;
        for(int i = 0; i < n; ++i) {
            if(nocylic(graph, i, visited)) {
                ans.push_back(i);
            };
        }
        return ans;
    }
    
    bool nocylic(vector<vector<int>>& g, int i, vector<int>& visited) {
        if(visited[i] != 0)
            return visited[i] == 1;
        visited[i] = 2;
        for(int adj: g[i]) {
            if(!nocylic(g, adj, visited)) {
                return false;
            }
        }
        visited[i] = 1;
        return true;
    }

    //using single vector

    class Solution {
    bool dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        vis[i] = 2;
        
        for(auto n : adj[i])
        {
            if(vis[n] == 0)
            {
                if(dfs(n, adj, vis)) return true;
            }
            else if (vis[n] == 2) return true;
        }
        
        vis[i] = 3;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        /*
            0 -> unvisited node
            1 -> visited node
            2 -> visited previously in current path
            3 -> safe node
        */
        vector<int> vis (V, 0);
        vector<int> ans;
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0) 
            {
                dfs(i, adj, vis);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 3) ans.push_back(i);
        }
        
        return ans;
    }
};


//using BFS(Kahn's algo)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>adjrev[v];
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>eventualSafeNodes;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            eventualSafeNodes.push_back(node);
            for(auto it:adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(eventualSafeNodes.begin(),eventualSafeNodes.end());
        return eventualSafeNodes;

    }
};