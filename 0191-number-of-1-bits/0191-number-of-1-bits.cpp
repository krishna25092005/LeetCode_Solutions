class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0) {
        // Checking last bit
        if(n&1) {
            count++;
        }
        n= n>>1;
    }
    return count;
}
};