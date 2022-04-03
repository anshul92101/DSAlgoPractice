class Solution {
public:
    
    void processDescending(vector<int>& nums){
        
        int N = nums.size();
        for(int i=0;i<N/2;i++){
            
            swap(nums[i],nums[N-i-1]);
        
        }
        
        
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int N = nums.size();
        int ind1 = -1, ind2;
        for(int i=N-1;i>=1;i--){
            
            if(nums[i]>nums[i-1]){
                ind1 = i-1;
                break;
            }
            
        }
       // cout<<"ind1 "<<ind1<<endl;
        if(ind1==-1){
            processDescending(nums);
            return;
        }
        
        for(int i=N-1;i>ind1;i--){
            
            if(nums[i]>nums[ind1]){
                ind2 = i;
                break;
            }
            
        }
       // cout<<nums[ind1]<<" "<<nums[ind2]<<endl;
        swap(nums[ind1],nums[ind2]);
        if(ind1+1>=N) return;
        else reverse(nums.begin()+(ind1+1), nums.end());
        
    }
};