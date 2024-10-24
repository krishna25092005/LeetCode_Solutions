class Solution
{
public:
    void backtrack(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &combination, int start)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                combination.push_back(candidates[i]);

                backtrack(candidates, target - candidates[i], result, combination, i);

                combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;

        backtrack(candidates, target, result, combination, 0);

        return result;
    }
};
