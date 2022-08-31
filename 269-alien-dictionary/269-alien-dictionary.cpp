class Solution {
public:
    bool dfs(unordered_map<char, int>& vis, unordered_map<char,unordered_set<char>> graph,char vertex, string &ordering ){
        
        if(vis[vertex]==1) return true;
        if(vis[vertex]==2) return false;
        vis[vertex]=1;
        for(auto node: graph[vertex]){
            if(dfs(vis,graph,node,ordering)) return "";
        }
        vis[vertex]=2;
        ordering += vertex;        
        return false;
    }
    
    
    
    string alienOrder(vector<string>& words) {
       
        int n = words.size();
        unordered_map<char,unordered_set<char>> graph;
        unordered_set<char> letters;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
                letters.insert(words[i][j]);
            }
        }
    
        for(int i=0;i<n-1;i++){
            
            string word1 = words[i];
            string word2 = words[i+1];
            int n1 = word1.length();
            int n2 = word2.length();
            if(n1>n2 && word1.substr(0,n2)==word2) return "";
            for(int j=0;j<min(word1.length(),word2.length());j++){
                
                if(word1[j]!=word2[j]){
                    graph[word1[j]].insert(word2[j]);
                    break;
                }
            }
            
        }
       
        unordered_map<char, int> vis;
        string ordering = "";
        for(auto letter: letters){
            if(dfs(vis,graph,letter,ordering)) return "";
        }
        
        reverse(ordering.begin(),ordering.end());
        return ordering;
        
        
    }
};