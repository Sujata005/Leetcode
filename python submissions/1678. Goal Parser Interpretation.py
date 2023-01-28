class Solution(object):
    def interpret(self, command):
        return command.replace('()','o').replace('(al)','al')
