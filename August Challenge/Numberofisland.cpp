/*
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

//tc=o(n),sc=o(n)=recursion stack space
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    help(grid,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
    void help(vector<vector<char>>& grid,int i,int j){
         int n=grid.size();
        int m=grid[0].size();
        if(i<0 ||j<0 ||i>=n||j>=m) return ;
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        help(grid,i+1,j);
        help(grid,i-1,j);
        help(grid,i,j+1);
        help(grid,i,j-1);
    }
};