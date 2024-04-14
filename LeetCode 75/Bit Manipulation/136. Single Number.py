class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        temp = {}
        n = 0
        for i in nums:
            temp[i] = temp.get(i,0) + 1
        
        for i in temp:
            print(temp[i])
            if temp[i] == 1:
                n = i
        return n