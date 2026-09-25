class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = binarySearch(0, nums.size()-1, target, nums);

        return ans;
    }

    int binarySearch(int beg, int end, int target, vector<int>& nums){
        if(beg > end){
            return -1;
        }

        int mid = (beg + end) /2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            return binarySearch(mid + 1,  end,  target,  nums);
        }
        else if(nums[mid] > target){
            return binarySearch( beg,  mid - 1,  target,  nums);
        }
        return -1;
    }
};
