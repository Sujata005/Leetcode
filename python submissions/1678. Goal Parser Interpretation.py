class Solution(object):
    def interpret(self, command):
        #easy
        return command.replace('()','o').replace('(al)','al')
