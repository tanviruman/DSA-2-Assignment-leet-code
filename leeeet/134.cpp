class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int curr_tank = 0;
        int start_index = 0;
        for(int i = 0; i< gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            curr_tank += gas[i] - cost[i];
            if(curr_tank < 0){
                start_index = i + 1;
                curr_tank = 0;
            }
        }
        if(total_gas < total_cost) return -1;
        return start_index;
        
    }
};