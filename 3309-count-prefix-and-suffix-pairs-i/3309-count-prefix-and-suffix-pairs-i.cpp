class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();

        // Iterate through all pairs of indices (i, j) such that i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }

        return count;
    }

private:
    // Function to check if str1 is both a prefix and a suffix of str2
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();

        // Check if str1 can be a prefix and a suffix of str2
        if (len1 > len2) return false;

        // Check prefix
        if (str2.substr(0, len1) != str1) return false;

        // Check suffix
        if (str2.substr(len2 - len1) != str1) return false;

        return true;
    }
};