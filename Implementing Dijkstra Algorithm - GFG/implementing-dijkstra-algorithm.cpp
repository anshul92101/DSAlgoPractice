// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int min(vector<int>& dist, vector<int>& vis){
        
        int minDistance = INT_MAX;
        int minNode;
        for(int u=0;u<dist.size();u++){
            if(!vis[u] && dist[u]<minDistance) {
                minDistance = dist[u];
                minNode = u;
            }
        }
        return minNode;
        
    }
        
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {   
        vector<int> dist(V,INT_MAX);
        dist[S] =0;
        vector<int> visited(V,0);
        
        for(int count=0;count<V;count++){
            
            int u = min(dist,visited);
            visited[u] = 1;
            
            for(auto p: adj[u]){
                
                int v = p[0], w = p[1];
                if((!visited[v]) && (dist[u] + w<dist[v])){
                    dist[v] = dist[u] + w;
                }
                
            }
            
        }
        
        return dist;
        // Code here
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends