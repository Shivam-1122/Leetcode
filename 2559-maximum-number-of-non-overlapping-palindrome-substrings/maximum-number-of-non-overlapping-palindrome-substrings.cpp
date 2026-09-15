class Solution {
public:
    int maxPalindromes(string s, int k) {
        int count = 0;
        int i = 0;

        while(i < s.size()) {
            bool found = false;

            if(i + k <= s.size()) {
                string s2 = s.substr(i, k);

                if(s2 == string(s2.rbegin(), s2.rend())) {
                    count++;
                    i += k;
                    found = true;
                }
            }

            if(!found && i + k + 1 <= s.size()) {
                string s2 = s.substr(i, k + 1);

                if(s2 == string(s2.rbegin(), s2.rend())) {
                    count++;
                    i += k + 1;
                    found = true;
                }
            }

            if(!found)
                i++;
        }

        return count;
    }
};