class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int contentChildren = 0;
        
        // Use two pointers to assign cookies
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {  // Cookie j satisfies child i
                contentChildren++;
                i++;  // Move to the next child
            }
            j++;  // Move to the next cookie
        }
        
        return contentChildren;
    }
};
