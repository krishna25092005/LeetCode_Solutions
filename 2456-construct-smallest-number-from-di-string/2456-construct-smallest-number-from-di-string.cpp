class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;
        
        // Iterate through the pattern and process accordingly
        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1); // Push the next number in sequence
            
            // If it's an 'I' or we are at the end, start popping
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return result;
    }
};
