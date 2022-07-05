/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }
        int m1[256]={};
        int m2[256]={};
        for(int i=0;i<n;i++){
            if(!m1[s[i]] && !m2[t[i]]){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m1[s[i]]!=t[i]) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mps,mpt;
        
        for(int i=0;i<s.length();i++)
        {
            if(mps.find(s[i])!=mps.end() && mps[s[i]]!=t[i])   // checking if the pair exists and is it's value is same or not
               return false;
            if(mpt.find(t[i])!=mpt.end() && mpt[t[i]]!=s[i])
               return false;
			mps[s[i]]=t[i];                                   // inserting the new pairs into the map
            mpt[t[i]]=s[i];
        }
        return true;
    }
};