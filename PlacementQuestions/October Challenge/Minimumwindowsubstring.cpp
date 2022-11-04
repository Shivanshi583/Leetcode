/*
76. Minimum Window Substring
Hard

13364

590

Add to List

Share
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

//TC=O(M+N)
//SC=O(N)

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>hash_s;
        unordered_map<char,int>hash_t;
         int len_s=s.length();
        int len_t=t.length();
        if(len_s<len_t) return "";
        for(int i=0;i<len_t;i++){
            hash_t[t[i]]++;
        }
        int count=0,start=0,min_len=INT_MAX,start_ind=-1;
        for(int j=0;j<len_s;j++){
            hash_s[s[j]]++;
            if(hash_s[s[j]]<=hash_t[s[j]]){//duplicates
                count++;
            }
            if(count==len_t){
                while(hash_s[s[start]]>hash_t[s[start]]|| hash_t[s[start]]==0){
                    if(hash_s[s[start]]>hash_t[s[start]]){
                        hash_s[s[start]]--;
                        start++;
                    }
                }
                if(min_len>j-start+1){
                    min_len=j-start+1;
                    start_ind=start;
                }
                
            }
            
        }
        if(start_ind==-1) return "";
        else return s.substr(start_ind,min_len);
    }
};