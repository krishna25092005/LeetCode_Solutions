class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;  // Map to store next greater elements
        stack<int> s;  // Monotonic decreasing stack
        
        // Step 1: Traverse nums2 and build the nextGreater map
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreater[s.top()] = num;  // num is the next greater element for s.top()
                s.pop();
            }
            s.push(num);
        }
        
        // For elements left in the stack, there is no next greater element
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }
        
        // Step 2: Build the result for nums1 using the nextGreater map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};
