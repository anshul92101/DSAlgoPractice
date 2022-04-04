/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };  1--2--3--4
       1--2--3
 */
class Solution {
public:
    
     void printList(ListNode* head){
         
         ListNode* curr = head;
         while(curr!=NULL){
             
             cout<<curr->val<<" ";
             curr = curr->next;
         }
         cout<<endl;
         
     }
    
     ListNode* getMiddle(ListNode* head){
         
         
         ListNode* slow = head;
         //ListNode* prev = new ListNode(-1,slow);
         ListNode* fast = head;
         while(slow!=NULL && fast!=NULL && fast->next!=NULL){
           //  prev = slow;
             slow = slow->next;
             fast = fast->next->next;
             
         }
         //prev->next = NULL;
         return slow;
         
     }   
    
    ListNode* reverseList(ListNode* head){
        
        ListNode* curr= head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        
        }
        head = prev;
        return head;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2){
            
           ListNode* solution = NULL;
           if(list1==NULL) return list2;
           if(list2==NULL) return list1;
           solution = list1;
           solution->next = merge(list2,list1->next);
            
           return solution;
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* middle = getMiddle(head);
        if(head->next==NULL) return;
       // cout<<middle->val<<endl;
        ListNode* curr = head;
        while(curr!=NULL && curr->next!=middle){
            curr= curr->next;
        }
        if(curr) curr->next = NULL;
        ListNode* list1 = head;
        ListNode* list2 = reverseList(middle);
        ListNode* reorderedList = merge(list1,list2);
        head = reorderedList;
    
    }
};