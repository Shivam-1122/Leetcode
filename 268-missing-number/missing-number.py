class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        nums.sort()
        x=0
        for i in nums:
            if i==x:
                x+=1
        return x
        