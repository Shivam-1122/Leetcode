class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> arr;
            arr.insert(nums[i]);

            sum += arr.size() * arr.size();

            for (int j = i + 1; j < nums.size(); j++) {
                arr.insert(nums[j]);
                sum += arr.size() * arr.size();
            }
        }

        return sum;
    }
};