class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int max = 0, count = 0;
        map<int,int> table;
        for(int i = 0; i < nums.size(); i++){
            table[nums[i]] = nums[i];
        }
        for(auto pair = table.begin(); pair != table.end();){
            auto current = pair;
            pair++;
            if(pair == table.end()){
                max = max > count ? max : count;
                break;
            }
            if(current->first == pair->first - 1){
                count++;
            }
            else if (current->first != pair->first - 1){
                max = max > count ? max : count;
                count = 0;
            }
        }
        return max+1;
    }
};