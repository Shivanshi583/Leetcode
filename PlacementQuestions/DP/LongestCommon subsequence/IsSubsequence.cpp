/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

*/
//tc=o(n)
//sc=o(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k=0;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[k]){
                k++;
            }
               
        }
            if(k==s.length()){
                return true;
            }
     
       return false; 
        
    }
};
//tc=o(n)
//sc=o(n*m)
class Solution {
public:
    int LCS(string x, string y) {
        int m=x.length();
        int n=y.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string s, string t) {
        if(LCS(s,t)==s.length()){
            return true;
        }
        return false;
    }
};