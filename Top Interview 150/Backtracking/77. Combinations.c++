class Solution {
public:
    void generateCombs(vector<vector<int>>& combs, int start, vector<int>& current, int k, int n){
        if(current.size() == k){
            combs.push_back(current);
            return;
        }
        for(int i = start; i <= n; i++){
            current.push_back(i);
            generateCombs(combs, i+1, current, k, n);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> combs;
        generateCombs(combs, 1, current, k, n);
        return combs;
    }
};