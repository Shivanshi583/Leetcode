/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 105
*/
int dp[101][100001];
bool sub(vector<int>arr, int sum ,int n){
    if(sum==0) return 1;
    if(sum<=0||n==0) return 0;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(arr[n-1]<=sum){
        return dp[n][sum]=sub(arr,sum-arr[n-1],n-1)||sub(arr,sum,n-1);
    }
    else{
        return dp[n][sum]=sub(arr,sum,n-1);
    }
}
class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
         int n=arr.size();
      
        memset(dp,-1,sizeof dp);
       
        return sub(arr,sum,n);
    }
};

//Tabulation
//tc=o(sum*n)
//sc=o(sum*n)
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here i
        int n=arr.size();
        int t[n+1][sum+1];
        for( int j=0;j<=sum;j++){
            t[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for( int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};