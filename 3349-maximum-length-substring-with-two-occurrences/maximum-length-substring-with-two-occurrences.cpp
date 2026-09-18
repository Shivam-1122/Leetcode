class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            int arr[256]={};
            int count = 0;

            for(int j = i; j < s.size(); j++) {
                if(arr[s[j]] == 2)
                    break;

                arr[s[j]]++;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};