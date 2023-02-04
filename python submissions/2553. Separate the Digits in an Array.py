class Solution(object):
    def separateDigits(self, nums):
        res=[]
        for x in nums:
            for j in str(x):
                res.append(int(j))
        return res
