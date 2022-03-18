class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string a, string b){
        
        if(a.compare(b)==0) return true;      
        if(a.length()<=1) return false;
        string expr = a + " " + b;
        if(mp.find(expr)!= mp.end()) return mp[expr];
        
        bool flag =false;
        int n = a.length();
    
        for(int i=1;i<=n-1;i++){
            
            bool cond1 = (solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i), b.substr(0,n-i)));
            bool cond2 = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)); 
            
            if(cond1 || cond2){
                flag = true;
                break;
            }
            
    
        }
        mp[expr] = flag;
        return flag;
            
    }
    
    bool isScramble(string s1, string s2) {
        
        mp.clear();
        if(s1.length()!=s2.length()) return false;    
        bool ans = solve(s1,s2);
        return ans;
        
    }

};