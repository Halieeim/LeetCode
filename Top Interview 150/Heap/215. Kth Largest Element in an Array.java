class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int i: nums){
            q.offer(i);
        }
        int i = 0;
        while(i++ != nums.length - k){
            q.poll();
        }
        return q.poll();
    }
}