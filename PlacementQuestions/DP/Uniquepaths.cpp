/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
*/
class Solution {
private:
    int f(int i,int j,vector<vector<int>> &dp)
    {
       
        if(i == 0 && j == 0)
            return 1;
        
        if(i<0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = f(i-1,j,dp);
        int left = f(i,j-1,dp);
        return dp[i][j] = up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,dp);
    }
};
class Solution {
public:
    int dp[105][105];
    int rec(int i,int j,int m,int n)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        
        
        if(i==m-1 && j==n-1)
        {
           
            return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
       
  
        
         int ans=rec(i+1,j,m,n)+rec(i,j+1,m,n);
        
        return dp[i][j]=ans;
    }
    int uniquePaths(int m,int n) {
        memset(dp,-1,sizeof dp);
        return rec(0,0,m,n);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i=1;i<=m;i++){
            dp[i][1]=1;
        }
             for(int j=1;j<=n;j++){
            dp[1][j]=1;
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
           return dp[m][n];     

    }
};




