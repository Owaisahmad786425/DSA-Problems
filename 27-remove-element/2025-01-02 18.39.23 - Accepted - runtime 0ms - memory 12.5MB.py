class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k=0
        for i in nums:
            if i!=val:
                k+=1
        start=0
        j = 0
        while(start<k):
            if nums[j] !=val:
                # x, y = y, x
                a = nums[start]
                nums[start] = nums[j]
                nums[j] = a
                start+=1
            j+=1
        return k