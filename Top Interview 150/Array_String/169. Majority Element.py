class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        temp = {};
        for x in nums:
            temp[x] = temp.get(x, 0) + 1
        
        element = 0
        m = 0
        for i in temp:
            if(m < temp[i]):
                m = temp[i]
                element = i

        return element