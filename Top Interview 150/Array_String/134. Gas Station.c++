class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int pos = 0, total = 0, sum = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                total += sum;
                sum = 0;
                pos = i + 1;
            }
        }
        total += sum;
        return total >= 0 ? pos : -1;
    }
};