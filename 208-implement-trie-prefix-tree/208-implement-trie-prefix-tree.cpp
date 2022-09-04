class Trie {
public:
    
    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        char val;
        bool isTerminal;
    };
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        
       TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            
            
            char c = word[i];
            TrieNode* childNode = new TrieNode();;
            if(curr->children.find(c)!=curr->children.end()){
                childNode = curr->children[c];
            }
            else{
                childNode->val = c;
                childNode->isTerminal = false;
                curr->children[c] = childNode;
            }
            curr = childNode;
        }
        
        curr->isTerminal = true;
        
    }
    
    bool search(string word) {
        
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(curr->children.find(c)==curr->children.end()) return false;
            curr = curr->children[c]; 
        }
        
        if(curr->isTerminal==true) return true;
        else return false;
    
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++){
            char c = prefix[i];
            if(curr->children.find(c)==curr->children.end()) return false;
            curr = curr->children[c]; 
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */