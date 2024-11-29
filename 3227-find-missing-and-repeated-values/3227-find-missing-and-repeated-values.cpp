class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>st;
        int n = grid.size();
        int a, b;
        int expSum = 0, actualSum = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                actualSum += grid[i][j];

                if(st.find(grid[i][j])!=st.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                st.insert(grid[i][j]);
            }
        }
        
        expSum = (n*n) * (n*n + 1)/2;
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};