/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/
class Solution {
public:
    int dp[301][5001];
    int help(int am,vector<int>& coins,int n){
       
        if(n==0) return 0;
        if(am==0) return 1;
        if(dp[n][am]!=-1) return dp[n][am];
        if(coins[n-1]<=am){
            return dp[n][am]=help(am-coins[n-1],coins,n)+help(am,coins,n-1);
        }
        else{
           return dp[n][am]=help(am,coins,n-1);
        }
        
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
         int n=coins.size();
        return help(amount,coins,n);
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int t[coins.size()+1][amount+1];
        
        for(int i=0;i<coins.size()+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i == 0){
                    t[i][j] = 0;
                }
                if(j == 0){        
                    t[i][j] = 1;
                }
            }
        }
        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1] <= j){
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[coins.size()][amount];
    }
};