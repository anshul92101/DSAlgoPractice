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
// 1 4 3 2 5 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k){
        
        ListNode* curr = head;
        ListNode* node1;
        ListNode* node2;
        int numNodes = 0;
        while(curr!=NULL){
            numNodes++;
            curr= curr->next;
        }
        curr = head;
        for(int i=0;i<numNodes;i++){
            
            if(i==k-1) node1= curr;
            if(i==numNodes-k) node2 = curr;
            curr = curr->next;
            
        }
        swap(node1->val,node2->val);
        return head;
    }
};