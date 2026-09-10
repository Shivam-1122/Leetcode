class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int arr[101]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]=1;
        }
        int i;
        for(i=k;i<=100;i+=k) {
            if(arr[i]!=1)
                return i;
        }
        return i;
    }
};