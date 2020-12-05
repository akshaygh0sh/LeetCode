// O(n) solution
// Essentially utilizing counting sort
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        // Find the size that the "hash table vector" has to be, find the element with the
        // biggest absolute value (either the first or last element since input is sorted)
        int hashSize = 0;
        if (abs(A[0]) > abs(A.back()))
        {
            hashSize = abs(A[0]);
        }
        else
        {
            hashSize = abs(A.back());
        }
        
        // Create a vector with that size + 1 (0 to the max abs val)
        vector <int> nums (hashSize + 1, 0);
        // For each element in the input, increase the count of that element in the vector
        // by one (basic counting sort)
        for (auto ix : A)
        {
            if (ix < 0)
            {
                nums[-ix]++;
            }
            else
            {
                nums[ix]++;
            }
        }
        // Once the count of all the elements are recorded, make the output vector/array
        vector<int> returnVec;
        // Iterate through the vector/array "hash table", and for each element with a non-zero
        // count n, add the square of that index n times to the output vector
        for (auto ix = 0; ix < nums.size(); ix ++)
        {
            if (nums[ix] != 0)
            {
                for (auto count = 0; count < nums[ix]; count++)
                {
                    returnVec.push_back(ix*ix);
                }
            }
        }
        // After all the operations are finished, the output will be a sorted vector of the
        // squares of the original input.
        return returnVec;
    }
};
