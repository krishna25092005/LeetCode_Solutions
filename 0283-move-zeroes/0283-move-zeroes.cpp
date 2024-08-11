#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        // Move non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }
        // Fill the rest of the array with zeros
        while (insertPos < nums.size()) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};
