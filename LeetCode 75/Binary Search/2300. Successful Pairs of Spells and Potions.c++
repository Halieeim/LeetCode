class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            int count = 0;
            int low = 0, high = potions.size() - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if((long long)spells[i] * potions[mid] >= success){
                    high = mid - 1;
                    count = potions.size() - mid;
                }
                else{
                    low = mid + 1;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};