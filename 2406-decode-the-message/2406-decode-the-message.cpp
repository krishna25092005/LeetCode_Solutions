class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        
        unordered_map<char, char> mp;
        char currentChar = 'a';

        for (char ch : key)
        {
            if (ch != ' ' && mp.find(ch) == mp.end())
            {
                mp[ch] = currentChar;
                currentChar++;
            }
        }

        string decodedMessage;
        for (char ch : message)
        {
            if (ch == ' ')
            {
                decodedMessage += ' ';
            }
            else
            {
                decodedMessage += mp[ch];
            }
        }

        return decodedMessage;
    }
};
