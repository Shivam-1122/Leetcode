class Solution {
public:
    int maximumLengthSubstring(string s) {
        int arr[256] = {};
        int i = 0, ans = 0;

        for(int j = 0; j < s.size(); j++) {
            arr[s[j]]++;

            while(arr[s[j]] > 2) {
                arr[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};