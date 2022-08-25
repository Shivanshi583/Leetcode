/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/
//copy the contents of linked list intoan array and then check with the help of pointers
//tc=o(n),sc=o(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool ispalindrome(vector<int> arr){
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            if(arr[s]!=arr[e]){
                return false;
            }
            s++;
            e--;
                    }
        return true;
        
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        return ispalindrome(arr);
    }
};


//Appraoch 2
/*
Find middle node of linked list ,reverse from middle +1 
Compare both halves,repeat step 2 to not manipualte the original linked list*/


//TC=O(N),SC=O(1)


class Solution {
public:
    ListNode* reverse(ListNode *head){
        if(head==NULL) return NULL;
        ListNode*p=NULL,*c=head,*n=head->next;
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;if(n!=NULL){
                n=n->next;
            }
        }
            return p;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       slow->next= reverse(slow->next);
        ListNode *start=head,*mid=slow->next;
        while(mid!=NULL){
            if(mid->val!=start->val) return false;
            start=start->next;
            mid=mid->next;
        }
        return true;
        slow->next=reverse(slow->next);
    }
};