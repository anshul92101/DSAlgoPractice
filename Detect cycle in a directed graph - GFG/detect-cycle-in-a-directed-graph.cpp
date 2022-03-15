// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycle(int src, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
        
        vis[src] = 1;
        dfsvis[src] = 1;
        
        for(auto node: adj[src]){
            
            if(vis[node]==0){
                if(checkCycle(node,adj,vis,dfsvis)) return true;
            }
            else if(vis[node]==1 && dfsvis[node]==1) return true; 
        }
        
        dfsvis[src] = 0;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(checkCycle(i,adj,vis,dfsvis)) return true;
            }
        }
        return false;
        // code here
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends