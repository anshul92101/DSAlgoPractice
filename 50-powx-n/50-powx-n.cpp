class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        long long int nonNegativeN = n;
        if(n<0) nonNegativeN *= -1;
        double ans = 1.0;
        while(nonNegativeN>0){
            
            if(nonNegativeN%2==1){
                ans = ans * x;
                nonNegativeN--;
            }
            else{
                x = x*x;
                nonNegativeN/=2;
            }
        }
        if(n>0) return (double)ans;
        else return (double)1.0/(double)ans;
    }
};