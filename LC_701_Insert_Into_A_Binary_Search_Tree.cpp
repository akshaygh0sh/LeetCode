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
// O(logn) solution
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        // If the pointer is null, create a new node and return that node
        // If we eventually reach a null pointer through our traversal, a new node will
        // be created, returned, and linked to the node it came from (because of the root->right and root->left below)
        if (root == nullptr)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        
        // If the value to be inserted is less than the current root's value
        // then go to the left (basics of a BST)
        if (val < root->val)
        {
            root->left = insertIntoBST (root->left, val);
        }
        
        // If the value to be inserted is greater than the current root's value
        // then go to the right (basics of a BST)
        if (val > root->val)
        {
            root->right = insertIntoBST (root->right, val);
        }
        
        // If the value is equal, none of the previous 2 if statements will run
        // and we should just return the root, since duplicates are not allowed in a BST
        
        
        return root;
    }
};
