class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vec;
        if(intervals.size() == 0){
            vec.push_back(newInterval);
            return vec;
        }

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vec.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(vec.back()[1] >= intervals[i][0]){
                vec.back()[1] = max(vec.back()[1], intervals[i][1]);
            }
            else{
                vec.push_back(intervals[i]);
            }
        }
        return vec;
    }
};