class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 2) return {0,1};
        map<int, int> diff_map;
        for (int i = 0; i < nums.size(); i++) {
            diff_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (diff_map.contains(diff) && diff_map[diff] != i) return {i, diff_map[diff]};
        }
        return {};
        
    }
};
