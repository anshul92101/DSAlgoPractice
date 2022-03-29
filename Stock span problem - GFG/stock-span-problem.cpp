// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    
    vector<int> getNGL(int price[], int n){
        
        stack<pair<int,int>> s;
        vector<int> index;
        for(int i=0;i<n;i++){
            
            if(s.empty()) index.push_back(-1);
            else{
                if(s.top().first > price[i]) index.push_back(s.top().second);
                else{
                    while(!s.empty() && s.top().first <= price[i]) s.pop();
                    if(s.empty()) index.push_back(-1);
                    else if(s.top().first > price[i]) index.push_back(s.top().second);
                }
            }
            pair<int,int> p = {price[i],i};
            s.push(p);
            
        }
        return index;
    }
    
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> index = getNGL(price, n);
       vector<int> ans;
       
       for(int i=0;i<n;i++){
           ans.push_back(i - index[i]);
       }
       
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends