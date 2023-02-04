class Solution(object):
    def toGoatLatin(self, sentence):
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        result, suffix = "", ""
        for word in sentence.split():
            suffix += 'a'
            if not word[0] in vowels:
                word = word[1:] + word[0]
            result += word + "ma" + suffix + ' '
        return result[:-1]
