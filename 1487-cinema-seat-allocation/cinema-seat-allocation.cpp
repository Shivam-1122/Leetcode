class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int count2 = 2*n;
        set<int> rows;
        for(auto x:reservedSeats)
            rows.insert(x[0]);

        for(int x:rows) {
            vector<int> arr(11, 1);

            for(int j = 0; j < reservedSeats.size(); j++) {
                if(reservedSeats[j][0] == x) {
                    arr[reservedSeats[j][1]] = 0;
                }
            }

            bool left = arr[2] && arr[3] && arr[4] && arr[5];
            bool middle = arr[4] && arr[5] && arr[6] && arr[7];
            bool right = arr[6] && arr[7] && arr[8] && arr[9];
            count2-=2;

            if(left && right)
                count2 += 2;
            else if(left || middle || right)
                count2 += 1;
        }

        return count2;
    }
};