/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void processNode(Node** prev, Node** childnode,Node** leftmost){
        
        if((*prev)!=NULL){
            
            (*prev)->next = *childnode;
            
        }
        else{
            *leftmost = *childnode;
        }
        
        (*prev) = *childnode;
        
    }
    
    Node* connect(Node* root) {
       
        if(root==NULL) return root;
        Node* leftmost = root;
        Node* prev = NULL;
        Node* curr= leftmost;
        
        while(leftmost!=NULL){
            
            Node* curr = leftmost;
            leftmost = NULL;
            prev = NULL;
            while(curr!=NULL){
                
               if(curr->left) processNode(&prev, &(curr->left),&leftmost);
               if(curr->right) processNode(&prev, &(curr->right),&leftmost);
               curr = curr->next;
            }
            
            
        }
        return root;
        
    }
};