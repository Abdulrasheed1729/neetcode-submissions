class Solution {
public:
    bool isValid(string s) {
       if (s.length() % 2 == 1) return false;
       unordered_map<char, char> closeToOpenMap = {
        {')', '('},
        {']', '['},
        {'}', '{'},
       };
       stack<char> charStack {};
       for (auto& c: s) {
        if (auto it = closeToOpenMap.find(c); it != closeToOpenMap.end()) {
            if (!charStack.empty() && charStack.top() == closeToOpenMap[c]) {
                charStack.pop();
            } else {
                return false;
            }
        } else {
            charStack.push(c);
        }
       }

       return charStack.empty();
    }
};
