/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/
//tc would be 3^(n) and sc=o(n) which is tle
// so memo
class Solution {
public:
	int f(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
		if(j<0 || j>=mat.size()) return 1e6;
		if(i==mat.size()-1) return mat[i][j];
		if(dp[i][j]!=-1) return dp[i][j];
		int left = mat[i][j] + f(i+1,j-1,mat,dp); 
		int down = mat[i][j] + f(i+1,j,mat,dp);
		int right = mat[i][j] + f(i+1,j+1,mat,dp);
		return dp[i][j] = min(down,min(left,right)); 
	}

	int minFallingPathSum(vector<vector<int>>& mat) {
		int n=mat.size();
		int ans=INT_MAX;
		vector<vector<int>>dp(n,vector<int>(n,-1));
		for(int j=0;j<n;j++) ans=min(ans,f(0,j,mat,dp));
		return ans;
	}
};
//tc =o(m*n)+o(n) ans sc=o(m*n)
 int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
         dp[0][i]=matrix[0][i];
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=INT_MAX,left=INT_MAX,right=INT_MAX;
                dp[i][j]=matrix[i][j];
                if(i-1>=0)
                    up=dp[i-1][j];
                if(i-1>=0&&j-1>=0)
                    left=dp[i-1][j-1];
                if(i-1>=0&&j+1<m)
                    right=dp[i-1][j+1];
                dp[i][j]+=min(up,min(left,right));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,dp[m-1][i]);
        return ans;