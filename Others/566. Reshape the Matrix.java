class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        if(mat.length * mat[0].length != r*c) return mat;
        int[][] newMatrix = new int[r][c];
        int idx = 0, w = mat[0].length;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                newMatrix[i][j] = mat[idx/w][idx%w];
                idx++;
            }
        }
        return newMatrix;
    }
}