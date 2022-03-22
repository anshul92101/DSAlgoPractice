// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_set<int> cache;
        unordered_map<int,int> mp;
        int pageFault = 0;
        
        for(int i=0;i<N;i++){
            
            if(cache.size()<C){
                
                if(cache.find(pages[i])==cache.end()){
                    pageFault++;
                    cache.insert(pages[i]);
                }
                mp[pages[i]]=i;
            }
            
            else{
            
                if(cache.find(pages[i])==cache.end()){
                    
                    pageFault++;
                    int lru=INT_MAX;
                    int value;
                    
                    for(auto page: cache){
                        
                        if(mp[page]<lru){
                            lru = mp[page];
                            value = page;
                        }
                    }
                    cache.erase(value);
                    cache.insert(pages[i]);
                    mp[pages[i]];
                }
                mp[pages[i]]=i;
            }
    
        }
        
        return pageFault;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends