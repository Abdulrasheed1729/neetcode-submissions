class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        size_t N = nums.size();
        std::vector<int> ans(2 * N, 0);
        for(int i = 0; i < N; i++) {
            ans[i] = nums[i];
            ans[i + N] = nums[i];
        }

        return ans;
    }
};