/*ou are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/
class Solution {
public:
    bool isValid(int i,int j,int row,int col){
        if(i<0||j<0||i>=row||j>=col){
            return false;
        }
        return true;
    }
    
    void dfs(int& count,vector<vector<int>>& grid,int i,int j,int row,int col){
        if(!isValid(i,j,row,col))
            return ;
        if(grid[i][j]==0) return;
        count++;
        grid[i][j]=0;
        dfs(count,grid,i+1,j,row,col);
                dfs(count,grid,i-1,j,row,col);
        dfs(count,grid,i,j+1,row,col);
        dfs(count,grid,i,j-1,row,col);

    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(count,grid,i,j,row,col);
                    maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};