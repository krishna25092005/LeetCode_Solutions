class Solution {
public:
    int strStr(string haystack, string needle) {
    
    int found = haystack.find(needle);
    
    if (found==string::npos) {
        return -1;
    }

    return found;
}
};