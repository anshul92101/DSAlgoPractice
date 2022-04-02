class Solution {
public:
    bool isPalindrome(string s) {
        
        int count=0;
        if(s.length()==0) return true;
        for(int i=0;i<s.length();i++){
            
            if(s[i]>=65 && s[i]<=90) s[i] = s[i] + 32;
            if(s[i]>=97 && s[i]<=122 || s[i]>='0' && s[i]<='9') s[count++] = s[i];
            
        }
        s.resize(count);
       // cout<<"string is "<<s<<endl;
        int N = s.length();
        for(int i=0;i<N/2;i++){
            if(s[i]!=s[N-i-1]) return false;
        }
        
        return true;
    }
};