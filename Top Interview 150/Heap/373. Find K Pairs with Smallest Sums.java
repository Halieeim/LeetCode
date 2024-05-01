class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a,b) -> (nums1[a[0]]+nums2[a[1]]) - (nums1[b[0]]+ nums2[b[1]]));
        for(int i = 0; i < Math.min(nums1.length,k); i++){
            minHeap.offer(new int[]{i,0});
        }
        List<List<Integer>> result = new ArrayList<>();
        for(int i = 0; i < k; i++){
            if(!minHeap.isEmpty()){
                int[] pair = minHeap.poll();
                List<Integer> sumList = new ArrayList<>();
                sumList.add(nums1[pair[0]]);
                sumList.add(nums2[pair[1]]);
                result.add(sumList);

                if(pair[1] < nums2.length-1){
                    minHeap.offer(new int[]{pair[0],pair[1]+1});
                }
            }
        }
        return result;
    }
}