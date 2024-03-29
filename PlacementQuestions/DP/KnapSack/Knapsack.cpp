/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
*/
//tc=o(m*n),sc=o(m*n)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int profit(int W, int wt[], int val[], int n){
        if(n==0||W==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        if(wt[n-1]<=W){
            return dp[n][W]= max(val[n-1]+profit(W-wt[n-1],wt,val,n-1),profit(W,wt,val,n-1));
        }
        else if(wt[n-1]>W){
            return dp[n][W]= profit(W,wt,val,n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof dp);
       int ans=profit(W,wt,val,n);
       return ans;
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int t[n+1][W+1];
       for(int i=0;i<=n;i++){
       
       for(int j=0;j<=W;j++){
           t[i][j]=0;
       }
       }
           for(int i=1;i<=n;i++){
               for(int j=1;j<=W;j++){
                   if(wt[i-1]<=j){
                      t[i][j]=  max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                   }
                   else if(wt[i-1]>j){
                     t[i][j]=   t[i-1][j];
                   }
               }
           
       }
       return t[n][W];
    }
};

