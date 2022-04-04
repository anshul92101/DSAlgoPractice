/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };  //1,2,3,4
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* temp = head->next; 
        head->next = swapPairs(head->next->next);
        temp->next = head;
        
        return temp; //as after changing temp acts like our head
    }
};