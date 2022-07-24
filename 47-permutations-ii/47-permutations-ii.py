
def findPermutation(res,nums,numsLength,pos):

    if(pos==numsLength):
        res.append(nums[:])
    else:
        posMap = set()
        for idx in range(pos,numsLength):
            if nums[idx] in posMap: continue
            posMap.add(nums[idx])
            nums[idx], nums[pos] = nums[pos],nums[idx]
            findPermutation(res,nums,numsLength,pos+1)
            nums[idx], nums[pos] = nums[pos],nums[idx]


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        numsLength = len(nums)
        pos = 0
        res = []
        findPermutation(res,nums,numsLength,pos)
        return res