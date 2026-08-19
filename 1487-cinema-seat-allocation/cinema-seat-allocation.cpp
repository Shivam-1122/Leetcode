class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for(auto x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        int ans = 2 * n;

        for(auto x : mp) {
            vector<int> arr(11, 1);

            for(int seat : x.second) {
                arr[seat] = 0;
            }

            bool left = arr[2] && arr[3] && arr[4] && arr[5];
            bool middle = arr[4] && arr[5] && arr[6] && arr[7];
            bool right = arr[6] && arr[7] && arr[8] && arr[9];

            ans -= 2;

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};