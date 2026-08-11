class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> numsMap;

        for(int i : nums){
            if(numsMap.contains(i)){
                return true;
            }
            numsMap[i] = true;
        }
        return false;
    }
};