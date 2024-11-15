class Solution
{
public:
    bool canTransform(string s, string e)
    {
        int i = 0, j = 0, p = s.size(), q = e.size();
        while (i < p || j < q)
        {
            
            while (s[i] == 'X')
                i++;
            while (e[j] == 'X')
                j++;

            if (s[i] != e[j])
                return false;
            if (s[i] == 'R' && i > j)
                return false;
            if (s[i] == 'L' && i < j)
                return false;
            i++, j++;
        }
        return true;
    }
};