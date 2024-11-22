class Solution {

public:
    string countAndSay(int n,string res="1") {
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int c = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1]))c++,i++;
                cur += to_string(c) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
