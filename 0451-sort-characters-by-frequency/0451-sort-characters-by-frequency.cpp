class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequencies of each character
        unordered_map<char, int> frequencyMap;
        for (char c : s) {
            frequencyMap[c]++;
        }

        // Step 2: Store characters and their frequencies in a vector of pairs
        vector<pair<int, char>> freqVec;
        for (auto& it : frequencyMap) {
            freqVec.push_back({it.second, it.first});
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](pair<int, char>& a, pair<int, char>& b) {
            return a.first > b.first;
        });

        // Step 4: Build the result string
        string result;
        for (auto& it : freqVec) {
            result.append(it.first, it.second);
        }

        return result;
    }
};