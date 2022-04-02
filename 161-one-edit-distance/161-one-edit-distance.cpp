class Solution {
public:
    
    
    
    
    bool isOneEditDistance(string s, string t) {
        
        int N = s.length();
        int M = t.length();
        
        if(abs(N-M)>=2) return false;
        if(N>M) return isOneEditDistance(t,s);
        
        bool LenEqual = (N==M)?true:false;
        
        if(s.substr(0,N)==t.substr(0,M)){
            
            if(LenEqual) return false;
            else return true;
            
        }
        
        for(int i=0;i<N;i++){
            
            if(s[i]!=t[i]){
                
                if(LenEqual){
                    
                    if(s.substr(i+1,N-i-1)==t.substr(i+1,M-i-1)) return true;
                    
                } 
                else{
                    
                    if(s.substr(i,N-i)==t.substr(i+1,M-i-1)) return true; //abcd abxcd
                    
                }
                
                return false;
            }
            
        
        }
        
        return true;
        
    }   
        
        
};