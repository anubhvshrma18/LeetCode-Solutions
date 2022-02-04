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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        ListNode* temp=head,*te=head;
        for(int i=0;i<n;i++){
            
            if(temp->next==nullptr){
                if(i==n-1){
                    head=head->next;
                    
                }
                return head;
            }
            temp=temp->next;
        }
        while(temp->next!=nullptr){
            temp=temp->next;
            te=te->next;
        }
        te->next=te->next->next;
        
        return head;
        
    }
};