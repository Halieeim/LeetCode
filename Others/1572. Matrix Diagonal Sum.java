class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        int[][] copy = new int[mat.length][mat[0].length];
        for(int i = 0; i < mat.length; i++){
            copy[i][i] = mat[i][i];
            sum += mat[i][i];
        }
        int j = 0;
        for(int i = mat.length-1; i >= 0; i--){
            if(copy[j][i] == 0){
                System.out.println(copy[j][i]);
                sum += mat[j++][i];
            }
            else j++;
        }
        return sum;
    }
}