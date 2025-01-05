class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0); // Difference array to store shifts

        // Step 1: Apply the shifts to the difference array
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                delta[start] += 1;
                delta[end + 1] -= 1;
            } else {
                delta[start] -= 1;
                delta[end + 1] += 1;
            }
        }

        // Step 2: Compute the prefix sum for net shifts
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += delta[i];
            // Normalize netShift to stay within [0, 25]
            netShift = (netShift % 26 + 26) % 26;

            // Step 3: Apply the shift to the character
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};
