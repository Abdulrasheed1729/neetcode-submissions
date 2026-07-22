class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()) return false;
       unordered_map<char, int> smap, tmap;

       // populate smap
       for (auto& c: s) {
        if(!smap.contains(c)) {
            smap[c] = 1;
        } else {
            smap[c]++;
        }
       }

       // populate tmap
       for (auto& c: t) {
        if(!tmap.contains(c)) {
            tmap[c] = 1;
        } else {
            tmap[c]++;
        }
       }

       for (auto& [k,v] : smap) {
            if (tmap[k] != v) return false;
       }

       return true;
    }
};
