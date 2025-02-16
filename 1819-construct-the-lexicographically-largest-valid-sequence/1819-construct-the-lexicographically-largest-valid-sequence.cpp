class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size, 0);
        vector<bool> used(n + 1, false);
        
        function<bool(int)> backtrack = [&](int index) {
            if (index == size) return true;
            if (result[index] != 0) return backtrack(index + 1);
            
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue;
                
                if (num == 1) {
                    result[index] = 1;
                    used[1] = true;
                    if (backtrack(index + 1)) return true;
                    result[index] = 0;
                    used[1] = false;
                } else {
                    int secondIndex = index + num;
                    if (secondIndex < size && result[secondIndex] == 0) {
                        result[index] = result[secondIndex] = num;
                        used[num] = true;
                        if (backtrack(index + 1)) return true;
                        result[index] = result[secondIndex] = 0;
                        used[num] = false;
                    }
                }
            }
            return false;
        };
        
        backtrack(0);
        return result;
    }
};
