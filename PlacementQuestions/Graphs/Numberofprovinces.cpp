/*

Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V ≤ 500
*/
class Solution {
  public:
  void dfs(vector<int>adjlist[],int v,vector<bool>&vis){
        vis[v]=true;
        
        for(auto neighbor : adjlist[v]){
            if(vis[neighbor]==false){
                dfs(adjlist,neighbor,vis);
            }
        }
        return;
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<int>adjlist[V+1];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    adjlist[i+1].push_back(j+1);
                }
            }
        }
        
        vector<bool>vis(V+1,false);
        int count=0;
        for(int i=1;i<=V;i++){
            if(vis[i]==false){
                count++;
                dfs(adjlist,i,vis);
            }
        }
        
        return count;
    }
};



class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
           int cnt=0;
        
        vector<bool>vis(V,false);
        
        queue<int>q;
        
        for(int i=0;i<V;++i){
            
            if(!vis[i]){
                cnt++;
                q.push(i);
                vis[i]=true;
                
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<adj[node].size();++j){
                        
                        if(adj[node][j] && !vis[j]){
                            vis[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
            
        }
        return cnt;
    }
};

class Solution {
  public:
    void dfs(vector<vector<int>>&graph,int node,int n,vector<int>&visited){
        visited[node] = true;
        for(int i = 0 ; i < n; i++){
            if(graph[node][i]==1){
                 if(visited[i]!=true){
                    // cout << i << " ";
                    dfs(graph,i,n,visited);
                }
            }
           
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        vector<int>visited(V,false);
        for(int i=0; i < V ; i++){
            if(visited[i]!=true){
                ans++;
                dfs(adj,i,V,visited);
            }
        }
        return ans;
    }
};