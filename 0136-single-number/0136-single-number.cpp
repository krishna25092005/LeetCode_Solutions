class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique=0;
        for(auto it : nums) {
            unique^=it;
        }
        return unique;
    }
};