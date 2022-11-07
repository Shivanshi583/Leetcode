/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/
//using DFS

class Solution {
public:
bool dfs(int node,vector<int> adj[],vector<int>vis,vector<int>pathvis){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            vis[it]=1;
            pathvis[it]=1;
            if(dfs(it,adj,vis,pathvis)==true) return true;
        }
        else if(pathvis[it]==1){
            return true;
        }
    }
    return false;
}
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>adj[n];
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);

        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true) return false;
            }
        }
        return true;
    }
};

//using kahn's algo
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==n) return true;
        return false;

    }
};