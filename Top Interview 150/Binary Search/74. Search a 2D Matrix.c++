class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = m*n;
        if(s == 1){
            if(matrix[0][0] == target) return true;
            else return false;
        }
        int start = 0, end = s-1;
        while(start <= end){
            int mid = (end + start)/2;
            if(matrix[mid / m][mid % m] == target) return true;
            else if(matrix[mid / m][mid % m] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return false;
    }
};