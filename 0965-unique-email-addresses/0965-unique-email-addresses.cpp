class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (const string& email : emails) {
            string local, domain;
            int atPos = email.find('@');

            // Split into local and domain parts
            local = email.substr(0, atPos);
            domain = email.substr(atPos);

            // Process the local part
            string processedLocal;
            for (char c : local) {
                if (c == '+') break; // Ignore everything after '+'
                if (c != '.') processedLocal += c; // Ignore '.'
            }

            // Combine processed local and domain
            uniqueEmails.insert(processedLocal + domain);
        }

        return uniqueEmails.size();
    }
};
