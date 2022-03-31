class Solution {
public:
    unordered_map<int, int> mp;
    int integerBreak(int n) {
        
        if(n==1||n==2) return 1;
        if(mp.find(n)!=mp.end()) return mp[n];
        int maxProduct = INT_MIN;
        
        for(int i=1;i<n;i++){
            
            int ans = i*max(integerBreak(n-i),n-i);
            if(ans>maxProduct) maxProduct = ans;
            
        }
        
        return mp[n] = maxProduct;
        
    }
};