class Solution {
    public int countSoldiers(int[] arr){
        int sum = 0;
        for(int i = 0; i < arr.length; i++){
            sum += arr[i];
        }
        return sum;
    }
    public int[] kWeakestRows(int[][] mat, int k) {
        List<Pair<Integer, Integer>> rows = new ArrayList<>();
        for (int i = 0; i < mat.length; i++) {
            int soldierCount = countSoldiers(mat[i]);
            rows.add(new Pair<>(i, soldierCount));
        }
        Collections.sort(rows, new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
                // If soldier counts are different, sort based on soldier counts
                if (!p1.getValue().equals(p2.getValue())) {
                    return p1.getValue() - p2.getValue();
                }
                // If soldier counts are the same, sort based on row indices
                return p1.getKey() - p2.getKey();
            }
        });
        int[] res = new int[k];
        for(int i = 0; i < k; i++){
            res[i] = rows.get(i).getKey();
        }
        return res;
    }
}