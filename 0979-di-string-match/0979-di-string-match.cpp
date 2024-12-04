class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0, high = n;
        vector<int> result;

        for (char c : s) {
            if (c == 'I') {
                result.push_back(low++);
            } else { // c == 'D'
                result.push_back(high--);
            }
        }
        
        // Add the remaining number
        result.push_back(low); // low and high will be equal here

        return result;
    }
};
