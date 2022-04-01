class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int N = s.size();
        int mid = N/2;
        cout<<N<<" "<<mid<<endl;
        for(int i=0;i<mid;i++){
            char temp = s[i];
            s[i] = s[N-i-1];
            s[N-i-1] = temp;
        }
        
        
    }
};