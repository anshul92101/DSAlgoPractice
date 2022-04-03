class Solution {
public:

    int reverse(int x) {
        
        int res=0;
        int newRes =0;
        while(x!=0){
            int lastDigit = x%10;
             if(res>INT_MAX/10|| res==INT_MAX/10 && lastDigit>INT_MAX%10) return 0;
            if(res<INT_MIN/10|| res==INT_MIN/10 && lastDigit<INT_MIN%10) return 0;
            newRes= res*10 + lastDigit;
            x/=10; 
           
            res = newRes;
                 
        }
        
        return res;
        
    }
};