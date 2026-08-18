class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> arr(51,0);
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int x:nums){
                arr[x]++;
            }
            for(int i=nums.size()-1;i>=0;i--){
                if(arr[nums[i]]==1)
                    return nums[i];
            }
            return -1;
        }
        else if(k==nums.size()){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        else{
            for(int x:nums){
                arr[x]++;
            }
            if((arr[nums[0]]==1) && (arr[nums[nums.size()-1]]==1))
                return max(nums[0],nums[nums.size()-1]);
            else if(arr[nums[0]]==1)
                return nums[0];
            else if(arr[nums[nums.size()-1]]==1)
                return nums[nums.size()-1];
            else
                return -1;
        }
        return -1;
    }
};