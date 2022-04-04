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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL) return head;
        ListNode* curr = head;
        int numNodes = 0;
        ListNode* last=head;
        while(curr!=NULL){
            numNodes++;
            curr = curr->next;
            if(curr!=NULL && curr->next == NULL) last = curr;
        }
        if(k>=numNodes){
            k= k%numNodes;
        }
        last->next = head;
        curr = head;
        for(int i=0;i<numNodes-k-1;i++){
            curr=curr->next;
        }
        head = curr->next;
        curr->next =NULL;
        
        return head;
    }
};