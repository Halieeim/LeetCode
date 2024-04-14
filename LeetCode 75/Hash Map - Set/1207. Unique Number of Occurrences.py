class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        x = {}
        for i in arr:
            x[i] = x.get(i, 0) + 1
        a = list(x.values())
        res = set(a)
        if(len(res) == len(a)):
            return True
        return False