class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int ans = INT_MAX;
        int best = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(mp.find(sum - target) != mp.end()) {
                int start = mp[sum - target] + 1;
                int len = i - start + 1;

                if(start > 0 && dp[start - 1] != INT_MAX)
                    ans = min(ans, len + dp[start - 1]);

                best = min(best, len);
            }

            dp[i] = best;
            mp[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};