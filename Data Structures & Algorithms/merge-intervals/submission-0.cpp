class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) return intervals;
    
    // sort intervals by the start time
    sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
    
    // initialise the mergedList
    vector<vector<int>> mergedList = { intervals[0] };
    
    for (size_t i = 1; i < intervals.size(); i++) {
        auto interval = intervals[i];
        auto& mergedListLastElement = mergedList.back();
        if (interval[0] <= mergedListLastElement[1]) {
            mergedListLastElement = {mergedListLastElement[0], max(interval[1], mergedListLastElement[1])};
        } else {
            mergedList.push_back(interval);
        }
    }
    
    return mergedList;
    }
};
