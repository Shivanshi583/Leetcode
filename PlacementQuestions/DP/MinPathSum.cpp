/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/
//tc=o(mn)
//sc=o(mn)+recursion stack space
class Solution {
public:
    int dp[205][205];
	int solve(vector<vector<int>>&grid, int i, int j){

		if(i<0 || j<0)
			return 1e9;

		if(i==0 && j==0)
			return grid[i][j];

		if(dp[i][j]!=-1)
			return dp[i][j];

		return dp[i][j] = grid[i][j] + min(solve(grid, i-1, j), solve(grid, i, j-1));   
	}

	int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
		int n = grid.size();
		int m = grid[0].size();
		
		return solve(grid, n-1, m-1);
	}
};

//to avoid recursion stack space in  space complexity ,we do tabulation

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>dp(n, vector<int>(m, 0));

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==0 && j==0)
					dp[i][j] = grid[i][j];
				else{
					int left = 1e9, right=1e9;
					if(i>0)
						left = dp[i-1][j];
					if(j>0)
						right = dp[i][j-1];

					dp[i][j] = grid[i][j] + min(left, right);
				}
			}
		}
		return dp[n-1][m-1];
	}
};