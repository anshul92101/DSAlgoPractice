def findPermutation(pos, numsLength, nums, res):
        
        if(pos==numsLength):
            res.append(nums[:])
        else:
            for idx in range(pos,numsLength):
                nums[pos], nums[idx] = nums[idx], nums[pos]
                findPermutation(pos+1,numsLength,nums,res)
                nums[pos], nums[idx] = nums[idx], nums[pos]

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        pos=0
        numsLength = len(nums)        
        findPermutation(pos,numsLength,nums,res)
        return res