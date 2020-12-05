// O(n) solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        // Uses Kadane's algorithm
        int maxSum = INT_MIN;
        int sum = 0;
        for (auto ix : nums)
        {
            sum = max((sum + ix), ix);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
