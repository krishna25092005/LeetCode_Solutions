class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i)
        {
            string curr = words[i];
            string prev = ans.back();

            sort(curr.begin(), curr.end());
            sort(prev.begin(), prev.end());

            if (curr != prev)
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};