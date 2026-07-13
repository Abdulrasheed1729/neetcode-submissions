class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> res = std::move(arr);
        int max = res[res.size() - 1];
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] >= max) {
                int tmp = res[i];
                res[i] = max;
                max = tmp;
            } else {
                res[i] = max;
            }
        }
        res[res.size() - 1] = -1;

        return res;
    }
};