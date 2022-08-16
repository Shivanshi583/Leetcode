/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
*/
//recursive approach had a tc of 2^n*n which is exponential ,so use memo
//in memoization the tc is o(n*n) and sc=o(n) +o(n*n)
class Solution {
public:
    int dp[205][205];
    int solve(int i,int j,vector<vector<int>>& triangle){
        int n=triangle.size();
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]= min(solve(i+1,j,triangle)+triangle[i][j],solve(i+1,j+1,triangle)+triangle[i][j]);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof dp);
       return solve(0,0,triangle);
    }
};
//sc will still be o(n*n),so reduce this

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n];
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        
    }
};

//space optimization to give sc =o(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int r=t.size(),c=t[0].size();
        
       vector<int>prev(r,0),curr(r,0);  
        
        for(int j=0;j<t[r-1].size();j++)
            prev[j]=t[r-1][j];
        
        for(int i=r-2;i>=0;i--)
        {
            for(int j=0;j<t[i].size();j++)
            {
                int d=t[i][j]+prev[j];
                int r=t[i][j]+prev[j+1];
               curr[j]=min(d,r);
            }
            prev=curr;
        }
        
        return prev[0];
    }
};