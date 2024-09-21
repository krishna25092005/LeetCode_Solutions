class Solution {
public:
    string removeDuplicates(string s)
{
    // Initialize an empty string to store the result without duplicates
    string ans;
    
    // Loop through each character in the input string 's'
    for (char ch : s)
    {
        // If the result string is not empty and the last character in 'ans' is the same as the current character
        if (!ans.empty() && ans[ans.size() - 1] == ch)
        {
            // Remove the last character from 'ans' to handle duplicate adjacent characters
            ans.pop_back();
        }
        else
        {
            // If the current character is not a duplicate, append it to 'ans'
            ans += ch;
        }
    }
    
    // Return the final result string without adjacent duplicates
    return ans;
}
};
