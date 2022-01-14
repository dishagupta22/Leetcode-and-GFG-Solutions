class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        int presum=0, count=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            presum+=nums[i];
            if(presum==k)
                count++;
            if(hm.find(presum-k)!=hm.end())
               count+=hm[presum-k];
            hm[presum]++;
        }
        return count;
    }
};