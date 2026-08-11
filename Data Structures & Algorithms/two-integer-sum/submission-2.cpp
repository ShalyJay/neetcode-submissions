class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> difs;
        vector<int> solution;

        for(int i = 0; i < nums.size(); i++){
            difs[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(difs.contains(target - nums[i]) && i != difs[target-nums[i]]){
                solution.push_back(i);
                solution.push_back(difs[target - nums[i]]);

                return solution;
            }
        }
    }
};
