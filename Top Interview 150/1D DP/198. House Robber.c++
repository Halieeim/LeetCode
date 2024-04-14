class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = (nums[i] + sum1) > sum2 ? nums[i] + sum1 : sum2;
            sum1 = sum2;
            sum2 = temp;
        }
        return sum2;
    }
};