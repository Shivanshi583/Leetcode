/*
Number of Distinct Islands
MediumAccuracy: 53.99%Submissions: 15115Points: 4
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     
     void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,vector<pair<int,int>>& vec,int row0,int col0){
         vis[row][col]=1;
         int n=grid.size();
         int m=grid[0].size();
         vec.push_back({row-row0,col-col0});
         int dr[]={0,-1,0,1};
         int dc[]={-1,0,1,0};
         for(int i=0;i<4;i++){
             int nr=row+dr[i];
             int nc=col+dc[i];
             if(nr>=0 && nr<n &&nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                 dfs(nr,nc,vis,grid,vec,row0,col0);
             }
         }
         
     }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
                
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
       set< vector<pair<int,int>>>st;
       queue<pair<int,int>>q;
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++){
                vector<pair<int,int>>vec;
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    vec.push_back({i-i,j-j});
                    q.push({i,j});
                }
                int row0=i;
                int col0=j;
                int dr[]={0,-1,0,1};
                int dc[]={-1,0,1,0};
                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    
                    for(int i=0;i<4;i++){
                        int nr=row+dr[i];
                        int nc=col+dc[i];
                        if(grid[i][j]==1 && nr>=0 && nr<n && nc>0 && nc<m){
                            grid[i][j]=0;
                            vec.push_back({nr-row0,nc-col0});
                            q.push({nr,nc});
                            st.insert(vec);
                            
                        }
                    }
                    
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends