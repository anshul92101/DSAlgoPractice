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
    unordered_map<int,int> freq;
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        
        if(head==NULL) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr!=NULL){
            freq[curr->val]++;
            curr = curr->next;
        }
        
        curr = dummy;
        while(curr!=NULL && curr->next!=NULL){
            
            if(freq[curr->next->val]>1){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
               // delete temp;
            }
            else{
                curr = curr->next;
            }
            
        }
    
        return dummy->next;
        
    }
};