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
    
    /*
     - i can do inorder travel through the BST, as a result of that i recive the vector of sorted nodes value (in case the BST is legal)
    - in our case we recive the vector with one  two uncorrect position - we can fix that and then rebuild the tree;
    - lets take a look at the following: [1,2,3,4,5,6] = legal BST, [1,2,6,4,5,3];
    
    
    
    */
    
    
    void inorderTravel(vector<int>& values,TreeNode* root){
        
        if(root == nullptr)
            return;
        
        inorderTravel(values,root->left);
        
        values.push_back(root->val);
        
        inorderTravel(values,root->right);
    }
    
    void rebuildTree(vector<int>&values , TreeNode* root ,int& index){
        
        if(root == nullptr)
            return;
        
        rebuildTree(values,root->left,index);
        root->val = values[index];
        index++;
        rebuildTree(values,root->right,index);
    }
public:
    void recoverTree(TreeNode* root) {
        
        vector<int> values;
        inorderTravel(values,root);
        
        int uncorrectIndx1;
        int uncorrecIndx2;
        
        sort(values.begin(),values.end());
    
        swap(values[uncorrectIndx1],values[uncorrecIndx2]);
        
        int index = 0;
        rebuildTree(values,root,index);
        
    
    }
};