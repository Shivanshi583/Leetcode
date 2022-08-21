/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
*/
//tc=o(n*sum);
//sc=o(n*sum);
class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int>& nums,int sum,int n){
       if(n<=0) return 0;
        if(sum<=0) return 1;
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(nums[n-1]<=sum){
            return dp[n][sum]=solve(nums,sum-nums[n-1],n-1)||solve(nums,sum,n-1);
        }
        else{
return dp[n][sum]= solve(nums,sum,n-1);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
 }
    if(sum%2!=0){
       return false; 
        }
        else{
            return solve(nums,sum/2,nums.size());
        }
    }
};

class Solution {
public:
    bool solve(vector<int>& nums,int sum,int n){
        int t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
if(nums[i-1]<=j){
t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];}
            else{
t[i][j]=t[i-1][j];
            }
        
        }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        return solve(nums,sum/2,nums.size());
    }
};