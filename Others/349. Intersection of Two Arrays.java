class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Convert array to a List
        List<Integer> list1 = Arrays.asList(Arrays.stream(nums1.length <= nums2.length ? nums1 : nums2).boxed().toArray(Integer[]::new));
        List<Integer> list2 = Arrays.asList(Arrays.stream(nums1.length > nums2.length ? nums1 : nums2).boxed().toArray(Integer[]::new));
        Set<Integer> set = new HashSet<>();
        for(int i: list1){
            if(list2.contains(i)){
                set.add(i);
            }
        }
        int[] arr = new int[set.size()];
        int j = 0;
        for(int i: set){
            arr[j++] = i;
        }
        return arr;
    }
}