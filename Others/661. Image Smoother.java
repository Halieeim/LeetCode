class Solution {
    public int[][] imageSmoother(int[][] img) {
        int[][] mat = new int[img.length][img[0].length];
        
        for(int i = 0; i < img.length; i++){
            for(int j = 0; j < img[i].length; j++){
                int sum = img[i][j];
                int count = 1;
                if(i-1 >= 0){
                    sum += img[i-1][j];
                    count++;
                }
                if(i+1 < img.length){
                    sum += img[i+1][j];
                    count++;
                }
                if(j-1 >= 0){
                    sum += img[i][j-1];
                    count++;
                }
                if(j+1 < img[i].length){
                    sum += img[i][j+1];
                    count++;
                }
                if(i-1 >= 0 && j-1 >= 0){
                    sum += img[i-1][j-1];
                    count++;
                }
                if(i-1 >= 0 && j+1 < img[i].length){
                    sum += img[i-1][j+1];
                    count++;
                }
                if(i+1 < img.length && j-1 >= 0){
                    sum += img[i+1][j-1];
                    count++;
                }
                if(i+1 < img.length && j+1 < img[i].length){
                    sum += img[i+1][j+1];
                    count++;
                }
                mat[i][j] = sum/count;
            }
        }
        return mat;
    }
}