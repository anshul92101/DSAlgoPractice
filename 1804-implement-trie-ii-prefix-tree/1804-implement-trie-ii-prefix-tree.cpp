class Trie {
public:
    
    struct TrieNode{
        char val;       
        unordered_map<char, TrieNode*> children;
        bool isTerminal;
        int countStart {0};
        int countEnd {0};
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode(); 
        root->countStart = 0;
        root->countEnd = 0;
        root->isTerminal = false;
        root->val = '/';
    }
    
    void insert(string word) {
        
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            TrieNode* childNode = new TrieNode();
            if(curr->children.find(c)!=curr->children.end()){
                childNode = curr->children[c];
            }
            else{
                childNode->val = c;
                childNode->isTerminal = false;
                curr->children[c] = childNode;
            }
            childNode->countStart+=1; 
            curr = childNode;
           
        }
        curr->countEnd+=1; 
        curr->isTerminal = true;
        
    }
    
    int countWordsEqualTo(string word) {
        
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(curr->children.find(c)==curr->children.end()) return 0;
            curr = curr->children[c];
        }
        if(curr->isTerminal==true) return curr->countEnd;
        else return false;
        
    }
    
    int countWordsStartingWith(string prefix) {
        
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++){
            char c = prefix[i];
            if(curr->children.find(c)==curr->children.end()) return 0;
            curr = curr->children[c];
        }
        return curr->countStart;
        
    }
    
    void erase(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(curr->children.find(c)==curr->children.end()) return;
            curr->children[c]->countStart-=1;
            curr = curr->children[c];
            
        }
        curr->countEnd-=1;
        if(curr->countEnd==0) curr->isTerminal = false;
       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */