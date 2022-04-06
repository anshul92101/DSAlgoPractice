class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target){
        
        long long int count = 0;
        int N = arr.size();        
        long long int BIGNUM = 1000000007;
        int newTarget;
        for(int i=0;i<N;i++){
            vector<int> mp(101);
            //newTarget = target - arr[i]; 
            for(int j = i+1;j<N; j++){
               if((target-arr[i]-arr[j])>=0 && (target-arr[i]-arr[j])<=100){
                      count = (count + mp[target-arr[j]-arr[i]])%BIGNUM;
               }
                mp[arr[j]]++;
                
            }    
        
        }
        return count%BIGNUM;
        
        
    }
};