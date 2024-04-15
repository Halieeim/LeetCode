class Solution {
public:
    bool compareByColumn(const vector<int>& row1, const vector<int>& row2, int col) {
        return row1[col] < row2[col];
    }
    void swap(vector<int>& v1, vector<int>& v2){
        vector<int> t;
        t = v1;
        v1 = v2;
        v2 = t;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int sortColumn = 1;
        // sort(intervals.begin(), intervals.end(), )
        sort(intervals.begin(), intervals.end(), [this, sortColumn](const vector<int>& row1, const vector<int>& row2) {
            return compareByColumn(row1, row2, sortColumn);
        });
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i][1] > intervals[i+1][0]){
                count++;
                swap(intervals[i], intervals[i+1]);
            }
        }
        return count;
    }
};