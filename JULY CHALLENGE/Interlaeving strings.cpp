/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

class Solution {
public:
    bool isleave(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>> &m){
        if(m[i][j]!=-1) return m[i][j];
        if(i==s1.length() && j==s2.length() && k==s3.length()) return true;
        bool x=false,y=false;
        if(i!=s1.length()){
            if(s1[i]==s3[k]){
                x=isleave(s1,s2,s3,i+1,j,k+1,m);
            }
            
        }
        if(j!=s2.length()){
            if(s2[j]==s3[k]){
                y=isleave(s1,s2,s3,i,j+1,k+1,m);
            }
        }
        return m[i][j]=x||y;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.length();
        int b=s2.length();
        vector<vector<int>>m(a+1,vector<int>(b+1,-1));
        int i=0;int j=0;int k=0;
        return isleave(s1,s2,s3,0,0,0,m);
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                else dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};