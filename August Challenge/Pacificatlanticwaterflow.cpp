/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 

Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        vector<vector<int>>ans;
        if(matrix.size()<1)return ans;
        vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int col=0;col<matrix[0].size();col++)
        {
            fnc(matrix,0,col,INT_MIN,pacific);
            fnc(matrix,matrix.size()-1,col,INT_MIN,atlantic);
            
        }
        
        for(int row = 0;row<matrix.size();row++)
        {
             fnc(matrix,row,0,INT_MIN,pacific);
            fnc(matrix,row,matrix[0].size()-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    vector<int>v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }
        
        
        
        return ans;
    }
    
    void fnc(vector<vector<int>>& matrix,int i, int j,int prev,vector<vector<int>>& ocean)
    {
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
            return;
        if(ocean[i][j]==1)
            return;
        if(matrix[i][j]<prev)
            return;
        
        ocean[i][j]=1;
        
        fnc(matrix,i+1,j,matrix[i][j],ocean); 
        fnc(matrix,i-1,j,matrix[i][j],ocean);
        fnc(matrix,i,j+1,matrix[i][j],ocean);
        fnc(matrix,i,j-1,matrix[i][j],ocean);
        
        
        
        
        
    }
};