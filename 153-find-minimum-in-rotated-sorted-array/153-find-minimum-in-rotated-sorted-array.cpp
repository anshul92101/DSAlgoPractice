class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int N = nums.size();
        int low = 0 ;
        int high = N-1;
        while(low<=high){
            
            if(nums[low]<=nums[high]) return nums[low];
            int mid = (low+high)/2;
            int next = (mid+1)%N;
            int prev = (mid-1+N)%N;
            if(nums[mid]<=nums[next] && nums[mid] <=nums[prev]) return nums[mid];
            else if(nums[mid]<=nums[high]) high = mid-1;
            else if(nums[mid]>=nums[low]) low = mid+1;
            
        }
        return -1;
    }
};