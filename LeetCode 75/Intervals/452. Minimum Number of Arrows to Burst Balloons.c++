class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> vec;
        sort(points.begin(), points.end());
        vec.push_back(points[0]);
        for(int i = 1; i < points.size(); i++){
            if(vec.back()[1] >= points[i][0]){
                vec.back()[1] = min(vec.back()[1], points[i][1]);
            }
            else{
                vec.push_back(points[i]);
            }
        }
        return vec.size();
    }
};