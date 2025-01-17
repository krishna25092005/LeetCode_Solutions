class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int x = 0;
        
        // Compute the XOR of all elements in derived
        for (int num : derived) {
            x ^= num;
        }
        
        // If the XOR of all derived elements is 0, then a valid binary array exists
        return x == 0;
    }
};
