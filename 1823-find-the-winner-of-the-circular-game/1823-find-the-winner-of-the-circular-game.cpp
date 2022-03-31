class Solution {
public:
    
    void solve(vector<int> &circle, int index,int k, int &ans ){
        
        int n = circle.size();
        if(circle.size()==1){
            ans = circle[0];
            return;
        }
        index = (index + k)%n;
        circle.erase(circle.begin() + index);
        solve(circle,index,k,ans);
        
        
        
    }
    int findTheWinner(int n, int k) {
        
        vector<int> circle;
        for(int i=1;i<=n;i++) circle.push_back(i);
        k--;
        int ans = -1;
        int index = 0;
       
        solve(circle,index,k,ans);
        return ans;
    }
};