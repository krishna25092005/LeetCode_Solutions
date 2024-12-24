class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int totalNumbers = 1 << n; // 2^n

        for (int i = 0; i < totalNumbers; ++i) {
            result.push_back(i ^ (i >> 1)); // Gray code formula
        }

        return result;
    }
};
