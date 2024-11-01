class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> ans;
        string curr;

        backtrack(digits, mp, 0, curr, ans);

        return ans;
    }

private:
    void backtrack(string digits, unordered_map<char, string>& mp, int idx, string curr, vector<string>& ans) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        char digit = digits[idx];
        string letters = mp[digit];

        for (char letter : letters) {
            curr.push_back(letter); 
            backtrack(digits, mp, idx + 1, curr, ans);
            curr.pop_back();
        }
    }
};
