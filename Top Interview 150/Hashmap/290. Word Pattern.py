class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        d = {}
        j = 0
        words = s.split(" ")
        for i in pattern:
            if i not in d and j < len(words):
                d[i] = words[j]
            j += 1

        newS = ""
        for i in words:
            for key, value in d.items():
                if value == i:
                    newS += key

        if newS == pattern:
            return True
        return False