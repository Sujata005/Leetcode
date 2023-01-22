class Solution(object):
    def wordPattern(self, pattern, s):

        s = s.split(' ')
        if  not len(s) == len(pattern):
		    return False
        return len(set(zip(pattern, s))) == len(set(s)) == len(set(pattern))
