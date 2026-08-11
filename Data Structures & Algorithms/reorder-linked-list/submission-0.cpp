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
    ListNode* rev(ListNode*& temp){
        ListNode* prev=nullptr;
        ListNode* curr=temp;
        while(curr!=nullptr){
            ListNode* nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=nullptr;
        ListNode* l2=rev(temp);
        ListNode* l1=head;
        
        
        while(l1!=nullptr && l2!=nullptr){
            ListNode* next1=l1->next;
            ListNode* next2=l2->next;
            l1->next=l2;
            l2->next=next1;
            l1=next1;
            l2=next2;
        }
    }
};
