class Solution {
public:
    
    int merge(vector<int>& nums, int low, int high){
        
        int mid = low + (high-low)/2;
        int i = low, j = mid+1;
        int temp[high-low+1];
        int k=0;
        int count =0;
        while(i<=mid && j<=high){
            
            if((long)nums[i]> (long) 2* nums[j]){
                count+= mid-i+1;
                j++;
            }else{
                i++;
            }
        }
        i=low;
        j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i<=mid) temp[k++] = nums[i++];
        while(j<=high) temp[k++] = nums[j++];
        
        for(int k=0;k<(high-low+1);k++){
            nums[low+k] = temp[k];
        }
        return count;
    }
    
    
    int mergeSort(vector<int>& nums, int low, int high){
        
        if(low>=high) return 0;
        int count = 0;
        int mid = low + (high-low)/2;
        count+= mergeSort(nums,low,mid);
        count+= mergeSort(nums,mid+1,high);
        count+= merge(nums,low,high);        
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        
        int low =0;
        int high = nums.size()-1;
        int sol = mergeSort(nums,low,high);
        return sol;
        
        
        
    }
};