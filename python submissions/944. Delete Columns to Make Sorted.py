class Solution(object):
    def minDeletionSize(self, strs):
        return sum(col != sorted(col) for col in map(list, zip(*strs)))
