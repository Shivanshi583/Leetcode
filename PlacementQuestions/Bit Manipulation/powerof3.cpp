/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
 

Constraints:

-231 <= n <= 231 - 1
*/
//o(log2(n))
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        while(n!=1){
            if(n%3!=0) return false;
            n/=3;
        }
        return true;
    }
};

//tc and sc=o(log3(n))

class Solution {
public:
    bool isPowerOfThree(int n) {
        //converting to base 3 and checking most significant bit is 1
        if(n<1) return false;
        string nbase3="";
        while(n){
            nbase3+=to_string(n%3);
            n/=3;
        }
        int i=0;
        while(i<size(nbase3)-1){
            if(nbase3[i]!='0') return false;
            i++;
        }
        return nbase3[i]=='1';
    }
};

