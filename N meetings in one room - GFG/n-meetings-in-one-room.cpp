// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int> a, pair<int,int> b){
        
        if(a.second==b.second) return a.first < b.first;
        else return a.second < b.second;
    }
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meeting;
        
        for(int i=0;i<n;i++) meeting.push_back({start[i],end[i]});
        int i=0,j=1,count=1;
        sort(meeting.begin(),meeting.end(),comp);
        while(j<n){
            
            if(meeting[i].second<meeting[j].first){
                
                count++;
                i=j;
                j++;
            }
            else j++;
            
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends