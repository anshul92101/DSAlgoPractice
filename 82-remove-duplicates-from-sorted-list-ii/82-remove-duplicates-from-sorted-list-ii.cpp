/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */        //1--2--2--3--3--3--4--4

class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head){
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        int value;
        while(curr->next && curr->next->next){
            
            if((curr->next)->val==(curr->next->next)->val){
                value = curr->next->val;
                while(curr->next!=NULL && curr->next->val==value)
                {
                    ListNode* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }   
            }
            else{
                curr = curr->next;
            } 
            
        }
        ListNode* temp = dummy;
        head = dummy->next;
        delete temp;
        return head;
    }
};