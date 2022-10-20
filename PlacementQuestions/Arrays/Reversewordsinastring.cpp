/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/
//recusrsive
class Solution {   
   public:
   
   string helper(string s){ 
   
	   if(s.size()==0) return "";
    
    int i=0;
	
    while(s[i]==32) i++;
    
	
    string a;
    while(i<s.size() && s[i]!=32){
        a+=s[i];
        i++;
    }
    //for after the first word
    string smallAns=helper(s.substr(i));
    
    string ans;
    ans+=smallAns; 
    ans+=" ";
    ans+=a;
    return ans; 
}

string reverseWords(string s) {
   string ans=helper(s);
   while(ans[0]==32) ans=ans.substr(1);
    return ans;
}
};

class Solution {
public:
    string reverseWords(string s) {
         stack<string> st;
    
        for(int i=0;i<s.size();i++){
        if(s[i]==32) continue;
          
            if(s[i]!=32){
                  string word="";
                int j=i;
                while(j<s.size() && s[j]!=32){
                    word+=s[j];
                    j++;
                }
                i=j;
                st.push(word);
                
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans=ans.substr(0,ans.size()-1);
        return ans;
       
    }
};