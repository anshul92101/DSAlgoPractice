class Solution {
public:
    
    int partition(vector<int>& nums, int low, int high){
        
        int pivot = nums[high];
        int i=low;
        int pIndex =low;
        while(i<high){
            
            if(nums[i]<pivot) i++;
            else{
                swap(nums[i++], nums[pIndex++]);
            }
            
        }
        swap(nums[pIndex], nums[high]);

        return pIndex;
        
    }
    
    int quickSelect(vector<int>& nums,int low, int high, int rank){
        
        if(low==high) return nums[low];
        int pIndex = partition(nums,low,high);
        
        if(pIndex==rank) return nums[pIndex];
        else if(pIndex<rank) return quickSelect(nums,pIndex+1,high, rank);
        else return quickSelect(nums,low,pIndex-1,rank);
        
        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int N = nums.size();
        int ans = quickSelect(nums,0,N-1,k-1);
        return ans;
        
    }
};