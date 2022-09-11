class Solution {
public:
    
    int base = 1337;
    
    int powMod(int a, int k){

        int ans = 1;
        for(int i=0;i<k;i++){
            ans = (ans%base) * (a%base) % base;
        }
        return ans;
    
    }
    
    
    int superPow(int a, vector<int>& b) {
        
        if(b.size()==0) return 1;
        int last_digit = b.back();
        b.pop_back();
        int ans = (powMod(superPow(a,b),10)%base) * (powMod(a,last_digit) % base) % base;
        return ans;
    
    }


};