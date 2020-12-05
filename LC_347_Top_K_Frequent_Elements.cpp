#include <algorithm>
// O(nlogk) solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // Use a min heap to keep track of the k most frequent elements
        vector<int> heap;
        // Use an unordered map to keep track of the frequencies of each element
        // Traverse the whole input vector to get the frequencies of each element
        // O(n) space and time complexity
        unordered_map<int, int> countMap;
        for (auto ix: nums)
        {
            countMap[ix]++;
        }
        
        // Write a lamba function that compares the frequencies of the element
        // (using the hash table/unordered map) as the comparator for the heap
        auto compare = [&] (int a, int b)
        {
            return (countMap[a] > countMap[b]); 
        };
        
        // Traverse the input vector once more and put every element into the
        // min heap (but restrict the size of the min heap to k)
        for (auto it = countMap.begin(); it != countMap.end(); ++it)
        {
            heap.push_back(it->first);
            push_heap (heap.begin(), heap.end(), compare);
            // If the size of the heap is more than k, pop off the minimum element
            // which will be the top/head of the min heap
            if (heap.size() > k)
            {
                pop_heap(heap.begin(), heap.end(), compare);
                heap.pop_back();
            }     
        }
        // After you have iterated through the whole vector/array, the maximum k elements (by frequency) will be in the min heap, and you can return 
        return heap;
    }
};
