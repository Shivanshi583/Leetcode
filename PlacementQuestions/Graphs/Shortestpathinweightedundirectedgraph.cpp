/*
You are given a weighted undirected graph having n vertices and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes n vertex and m edges and vector of edges having weight as inputs and returns the shortest path between vertex 1 to n.

Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 105
0 <= m <= 105
1 <= a, b <= n
1 <= w <= 105*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // {dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        vector<int> parent(n+1);
        vector<int> dist(n+1, 1e9);
        
        dist[1] = 0;
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        min_heap.push({0, 1});
        while(!min_heap.empty()){
            int dis = min_heap.top().first;
            int node = min_heap.top().second;
            min_heap.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                
                if(dist[adjNode] > dis + weight){
                    dist[adjNode] = dis + weight;
                    parent[adjNode] = node;
                    min_heap.push({dist[adjNode], adjNode});
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        dist[1]=0;
        set<pair<int,int>> s;
        s.insert({0,1});
        while(!s.empty())
        {
            auto st = *s.begin();
            int node = st.second;
            int dis = st.first;
            s.erase(st);
            for(auto it: adj[node])
            {
                int adjNode=it.first;
                int edgeW=it.second;
                if(dis+edgeW<dist[adjNode])
                {
                    if(dist[adjNode]!=1e9)
                    {
                        s.erase({dist[adjNode],adjNode});
                    }
                    parent[adjNode]=node;
                    dist[adjNode]=dis+edgeW;
                    s.insert({dist[adjNode],adjNode});
                }
            }
        }
        vector<int> ans;
        ans.push_back(n);
        int k = n;
        while(ans.size()<k)
        {
            int node = parent[n];
            ans.push_back(node);
            n=node;
            if(n==1)
            {
                reverse(ans.begin(),ans.end());
                return ans;
            }
        }
        
        ans.clear();
        ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends