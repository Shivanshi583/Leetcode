/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/
//TC=o(n*m)
//sc=o(n*m)
/*
Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)
*/

class Solution {
public:
    int dp[1001][1001];
     int lcs(string& x,string& y,int n,int m){
         if(n==0 || m==0) return 0;
         if(dp[n][m]!=-1) return dp[n][m];
         if(x[n-1]==y[m-1]) {return dp[n][m]= 1+lcs(x,y,n-1,m-1);}
         else{
             return dp[n][m]= max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
         }
         
     }
    int longestCommonSubsequence(string x, string y) {
        memset(dp,-1,sizeof dp);
        int n=x.size();
        int m=y.size();
        
        
        return lcs(x,y,n,m);
    }
};

class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int n=x.size();
        int m=y.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            t[i][0]=0;
        }
         for(int j=0;j<=m;j++){
            t[0][j]=0;
        }
            
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};