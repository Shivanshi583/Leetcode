/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


//ITERATIVE-TC=O(N),SC=O(1)

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=NULL;
        while(head!=NULL){
 ListNode* next=head->next;
        head->next=temp;
            temp=head;
            head=next;
        }
        return temp;
    }
};

//recursive

//tc=o(n) && sc=o(n)

class Solution {
public:
    void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode* forward=curr->next;
        reverse(head,forward,curr);
        curr->next=prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        reverse(head,curr,prev);
        return head;
        
    }
};
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* forward=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return forward;
    }
    ListNode* reverseList(ListNode* head) {
       return reverse(head);
    }
};