class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int n1 = num1.size();
        int n2 = num2.size();
        if(n1>n2) return addStrings(num2,num1);
        
        string ans="";
        int carry =0,sum=0;
        int diff = n2-n1;
        for(int i=n1-1;i>=0;i--){
            
            sum = num1[i] -'0' + num2[i+diff]-'0' + carry;
            carry=sum/10;
            sum=sum%10;
            
            ans.push_back(sum+'0');
        }
        
        for(int i=n2-n1-1;i>=0;i--){
            
            sum = num2[i] -'0' + carry;
            carry=sum/10;
            sum=sum%10;
            
            ans.push_back(sum+'0');
        }
        if(carry>0){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};