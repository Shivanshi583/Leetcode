/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
*/
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head!=NULL){
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head,*prev=NULL;
        int count=1;
        while(count!=left){
            prev=curr;
            curr=curr->next;
            count++;
        }
        ListNode* start=curr;
        while(count!=right){
            curr=curr->next;
            count++;
        }
        ListNode* end=curr->next;
        curr->next=NULL;
        ListNode* nhead=reverse(start);
        if(prev!=NULL){
            prev->next=nhead;
        }
        curr=nhead;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=end;
        if(left==1){ return nhead;}
        else{ return head;}
    }
};



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(head==NULL || left==right){
    return head;
      }
        ListNode*temp,*tail=NULL;
        ListNode* dummy=new ListNode(NULL);
        dummy->next=head;
        ListNode*prev=dummy;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        tail=prev->next;
        for(int i=0;i<right-left;i++){
            temp=prev->next;
            prev->next=tail->next;
            tail->next=tail->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
    }
};