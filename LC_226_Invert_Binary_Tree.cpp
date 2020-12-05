/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        // If the root pointer is null, return a null pointer
        if (root == nullptr)
        {
            return root;
        }
        
        // Constantly go to the left until you reach the eventual null pointer
        invertTree (root->left);
        // Once you have reached the bottom left, swap the left and right
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        // Make the switch and then continue the process on the right, which, now that you 
        // switched the left and right, is now actually the left.
        invertTree(root->left);
        return root;
    }
};
