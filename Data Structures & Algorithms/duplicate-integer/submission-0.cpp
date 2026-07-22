class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       set<int> val_set; 
       for (auto num: nums)
       {
        if (val_set.contains(num)) return true;
        val_set.insert(num);
       }

       return false;
    }
};