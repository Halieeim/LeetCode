class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        boolean[] marked = new boolean[nums.length + 1];

        for(int i = 0; i < nums.length; i++){
            if(nums[i] > 0 && nums[i] <= nums.length){
                marked[nums[i]] = true;
            }
        }
        for(int i = 1; i < marked.length; i++){
            if(!marked[i]) list.add(i);
        }
        return list;
    }
}