class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0], currsum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            currsum= max(nums[i], currsum+nums[i]);
            maxSum= max(maxSum, currsum);
        }
        return maxSum;
    }
};