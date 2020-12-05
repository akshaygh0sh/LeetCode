// O(nlogn) solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // If the size of the intervals vector is 1 or less, there is no need to merge
        // just return the vector
        if (intervals.size() <= 1) 
        {
            return intervals;
        }
        
        vector<vector<int>> ans;
        // Sort the vector by the first number in the interval, if the first interval number
        // is the same, then compare the second numbers
        sort(intervals.begin(), intervals.end());
        
        auto ix = 0U;
        while (ix < intervals.size() -1)
        {
            // If the first number of an interval is less than the first number of the following interval and the second number of the interval is greater than the first number of the following interval, the new interval is the lower first number to the higher second number
            if (intervals[ix][0] <= intervals[ix+1][0] && intervals[ix][1] >= intervals[ix+1][0])
            {
                // Changes the second interval to the proper, non overlapping interval and repeats the same process with this new second interval
                intervals[ix+1][0] = intervals[ix][0];
                intervals[ix+1][1] = max(intervals[ix][1], intervals[ix+1][1]);
            }
            else
            {
                // If the interval does not over lap with the next interval in the input vector, then add it to the final answer vector (which contains all the non-overlapping intervals)
                ans.push_back(intervals[ix]);
            }
            ix++;
        }
        // At the end of the while loop, the only interval remaining will be the last interval, which is guaranteed to be non overlapping (since the while loop changes the ix + 1 interval to a non-overlapping interval)
        
        // So, add it to the answer vector
        ans.push_back(intervals.back());
        return ans;
    }
};
