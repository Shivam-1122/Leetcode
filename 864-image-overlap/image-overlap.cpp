class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> arr;
        vector<vector<int>> arr2;

        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                if(img1[i][j])
                    arr.push_back({i,j});

                if(img2[i][j])
                    arr2.push_back({i,j});
            }
        }

        map<pair<int,int>, int> mp;
        int ans=0;

        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr2.size();j++){
                int k=arr[i][0]-arr2[j][0];
                int l=arr[i][1]-arr2[j][1];

                mp[{k,l}]++;
                ans=max(ans,mp[{k,l}]);
            }
        }

        return ans;
    }
};