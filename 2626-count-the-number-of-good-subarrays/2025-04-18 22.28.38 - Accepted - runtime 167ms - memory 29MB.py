class Solution(object):
    def countGood(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        l = 0
        r = 0
        mp = dict()
        pair = 0
        subarray = 0
        while(r<len(nums)):
            mp[nums[r]] = mp.get(nums[r], 0) +1
            pair+=mp[nums[r]]-1
            while(pair>=k):
                subarray += len(nums) - r
                pair -=mp[nums[l]]-1
                mp[nums[l]]-=1
                l+=1
            r+=1
        return subarray