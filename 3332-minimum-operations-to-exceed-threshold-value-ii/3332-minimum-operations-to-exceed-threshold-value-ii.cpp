class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;
        
        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            
            if (digitSumMap.find(digitSum) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[digitSum] + num);
                digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
            } else {
                digitSumMap[digitSum] = num;
            }
        }
        
        return maxSum;
    }
    
    int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
    int operations = 0;
    
    while (minHeap.size() > 1 && minHeap.top() < k) {
        long long x = minHeap.top(); minHeap.pop();
        long long y = minHeap.top(); minHeap.pop();
        minHeap.push(min(x, y) * 2LL + max(x, y));  // Use 2LL to ensure long long multiplication
        operations++;
    }
    
    return minHeap.top() >= k ? operations : -1;
}
};