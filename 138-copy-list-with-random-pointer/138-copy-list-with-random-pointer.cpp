/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //populating the linked list with copy of nodes
        if(head==NULL) return NULL;
        Node* cur = head;
        Node* temp;
        while(cur!=NULL){
            
            temp = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = temp;
            cur = temp;
            
        }
        
        //setting up the arbitrary pointers
        Node* original = head;
        Node* copy = original->next;
        temp = copy;
        while(original){
            if(original->random) (original->next)->random = (original->random)->next;    
            original = original->next->next;
        }
        //now rearrange the links back to original state
        original = head;
        while(original && copy){
            
            original->next = original->next->next;
            if(copy->next) copy->next = copy->next->next;
            original = original->next;
            copy = copy->next;
        }
        return temp;
    }
};