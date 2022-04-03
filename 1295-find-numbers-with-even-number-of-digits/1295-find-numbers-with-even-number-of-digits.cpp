class Solution {
public:
    
    bool hasEvenDigits(int num){
        
        int count=0;
        if(num==0) return false;
        while(num!=0){
            num=num/10;
            count++;
        }
        if(count%2==0) return true;
        else return false;
        
    }
    
    
    int findNumbers(vector<int>& nums) {
        
        int N = nums.size();
        int count=0;
        for(int i=0;i<N;i++){
            
            if(hasEvenDigits(nums[i])) count++;
            
            
        }
    
        return count;
    
    
    
    
    }
};