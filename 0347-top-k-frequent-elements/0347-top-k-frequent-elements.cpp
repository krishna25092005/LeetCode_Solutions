class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto &[num, freq] : freq)
        {
            minHeap.push({freq, num});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> ans;
        while (!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};