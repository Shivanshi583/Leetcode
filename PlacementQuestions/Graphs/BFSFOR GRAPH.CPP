
/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


Example 1:

Input:

Output: 0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3.After this 2 to 4, thus bfs will be
0 1 2 3 4.
Example 2:

Input:

Output: 0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2 3 4. 

Your task:
You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 104



*/
//SC=O(N)+O(N)+O(N)=O(N),queue,bfs,vis
//tc=o(n+2E)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        vector<int>vis(V+1,0);
        queue<int>q;
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                vis[it]=1;
                q.push(it);
                }
            }
        }
        return bfs;
    }
};


//for disconnected graph
class solution{
public:
    vector<int>bfs(int V,vector<int>adj[]){
        vector<int>bfs;
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return bfs;

}

}