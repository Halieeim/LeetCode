class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        PriorityQueue<Integer> left = new PriorityQueue<>();
        PriorityQueue<Integer> right = new PriorityQueue<>();
        int l = 0, r = costs.length - 1;
        long cost = 0;
        while(k-- > 0){
            while(left.size() < candidates && l <= r){
                left.add(costs[l++]);
            }
            while(right.size() < candidates && r >= l){
                right.add(costs[r--]);
            }
            int leftMin = left.size() > 0 ? left.peek() : Integer.MAX_VALUE;
            int rightMin = right.size() > 0 ? right.peek() : Integer.MAX_VALUE;
            if(leftMin <= rightMin){
                cost += left.poll();
            }
            else cost += right.poll();
        }
        return cost;
    }
}