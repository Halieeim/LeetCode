class Solution {
public:
    void generatePerms(vector<int>& nums, vector<vector<int>>& perms, vector<bool>& used, vector<int>& current){
        if(current.size() == nums.size()){
            perms.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                current.push_back(nums[i]);
                generatePerms(nums, perms, used, current);
                current.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        generatePerms(nums, perms, used, current);
        return perms;
    }
};