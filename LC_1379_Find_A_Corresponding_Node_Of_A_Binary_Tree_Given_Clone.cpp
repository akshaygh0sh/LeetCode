/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n) solution
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        // Once the target is found, return it
        if (original == target)
        {
            return cloned;
        }
        else
        {
            TreeNode* ans = nullptr;
            // If the answer is not yet found (it is a nullptr)
            // and there is a left child, move to the left
            if (original->left != nullptr && ans == nullptr)
            {
                // Traverse both trees synchronously
                ans = getTargetCopy (original->left, cloned->left, target);
            }
            
            // If the answer is not yet found (it is a nullptr)
            // and there is a right child, move to the right
            if (original->right != nullptr && ans == nullptr)
            {
                // Traverse both trees synchronously
                ans = getTargetCopy (original->right, cloned->right, target);
            }
            return ans;
        }
    }
    
};
