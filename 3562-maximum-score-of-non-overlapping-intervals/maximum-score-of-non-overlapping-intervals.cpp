class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int,4>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1]) return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<int> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; i++)
            prev[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin();

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> path(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 4; j++) {

                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];

                long long val = a[i - 1][2] + dp[prev[i - 1]][j - 1];

                vector<int> cur = path[prev[i - 1]][j - 1];
                cur.push_back(a[i - 1][3]);
                sort(cur.begin(), cur.end());

                if (val > dp[i][j] ||
                    (val == dp[i][j] && cur < path[i][j])) {
                    dp[i][j] = val;
                    path[i][j] = cur;
                }
            }
        }

        return path[n][4];
    }
};