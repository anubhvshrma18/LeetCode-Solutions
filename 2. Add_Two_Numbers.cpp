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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL,*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverse(l1);
        // l2=reverse(l2);
        ListNode *head3=NULL;
        int carry=0;
        while(l1 || l2 || carry!=0){
            int x=carry;
            if(l1){
                x+=l1->val;
            }
            if(l2){
                x+=l2->val;
            }
            
            carry=x/10;
            x=x%10;
            ListNode* neNode=new ListNode(x);
            neNode->next=head3;
            head3=neNode;
            
            if(l1){
                l1=l1->next;
                
            }
            if(l2){
                l2=l2->next;
                
            }
            
        }
        head3=reverse(head3);
        return head3;
    }
};