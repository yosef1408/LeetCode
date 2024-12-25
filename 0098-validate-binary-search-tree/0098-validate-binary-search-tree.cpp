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


/*
    - Naive solution is to do inorder search maintain all the nodes result at array(vec);
    - iterate over the vector and check if it legal; space complexity = time complexity = O(1);
    
    - intresting qouestion, can we solve it at O(1) space complexity? No/Yes?.
    
    
            2
        1       3        ==> return (leftnode->val < currentVal && currentVal < rightNode->val) && aux(left...) && aux(right);
        
        i guess i can implement it using O(1) space complexity; by sending refrence bool variable and changing it if false detected;
                                ===> with out recusion.
                                
        LOL that dont. work okay i spent my time trying to optimize to O(1) lets write the Naive soultion :D

*/
class Solution {
    
    
bool isBSTLayer(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    if (root == nullptr)
        return true;

    // Check if the current node violates the min/max constraint
    if ((minNode != nullptr && root->val <= minNode->val) ||
        (maxNode != nullptr && root->val >= maxNode->val))
        return false;

    // Recur for left and right subtrees with updated constraints
    return isBSTLayer(root->left, minNode, root) &&
           isBSTLayer(root->right, root, maxNode);
}

    
public:
    bool isValidBST(TreeNode* root) {
        
        
        return isBSTLayer(root);
    }
};