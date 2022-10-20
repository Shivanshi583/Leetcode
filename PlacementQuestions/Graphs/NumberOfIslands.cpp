/*
Number of Islands
Medium

17517

401

Add to List

Share
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.



*/

class Solution {
public:   
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>> grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty())
        {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(abs(i)==abs(j)){continue;}
                    int newr = r + i;
                    int newc = c + j;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && 
                       grid[newr][newc]=='1' && vis[newr][newc]==0)
                    {
                        q.push({newr,newc});
                        vis[newr][newc]=1;
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
      return ans;  
    }
};


//without vis matrix

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int islands=0;
        int offset[]={0,1,0,-1,0};
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    grid[i][j]='0';
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int>todo=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r=todo.first;
                            int c=todo.second;
                            int nr=r+offset[k];
                                int nc=c+offset[k+1];
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' ){
                                grid[nr][nc]='0';
                                q.push({nr,nc});
                            }
                        }
                        
                    }
                    
                    
                }
            }
        }
        return islands;
    }
};


//using dfs

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid);
                }
            }
        }
        return islands;
    }
};