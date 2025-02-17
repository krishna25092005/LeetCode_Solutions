class Solution {
public:
    int dfs(std::unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, cnt] : freq) {
            if (cnt > 0) {
                count++;
                freq[ch]--;
                
                count += dfs(freq);
                
                freq[ch]++;
            }
        }
        return count;
    }

    int numTilePossibilities(std::string tiles) {
        std::unordered_map<char, int> freq;
        for (char ch : tiles) {
            freq[ch]++;
        }
        return dfs(freq);
    }
};
