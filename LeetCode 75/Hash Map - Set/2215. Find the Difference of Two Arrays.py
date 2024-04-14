class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        result = []
        arr1 = []
        arr2 = []
        for i in nums1:
            if i not in nums2:
                arr1.append(i)

        for i in nums2:
            if i not in nums1:
                arr2.append(i)

        arr1 = set(arr1)
        arr2 = set(arr2)
        result.append(arr1)
        result.append(arr2)
        return result