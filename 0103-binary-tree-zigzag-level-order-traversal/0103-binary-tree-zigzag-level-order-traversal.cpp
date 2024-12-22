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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    // the soultion is kind of BFS travel throught the nodes, lets hold a dequeue to mannage insertain and  poping, then building out list
  
        if(root == nullptr)
            return {};
        
        queue<TreeNode*> currentQue;
        vector<vector<int>> result;
        bool rtl = true;
        result.push_back({root->val});
        currentQue.push(root);
                         
        while(currentQue.empty() == false){
            
            deque<int> layer;
            int queSize = currentQue.size();
            
            for(int i = 0 ; i < queSize ;i++){
                auto currentNode = currentQue.front();
                if(rtl){
                    
                    if(currentNode->left != nullptr){
                        layer.push_front(currentNode->left->val);
                        currentQue.push(currentNode->left);
                    }
                    if(currentNode->right != nullptr){
                        layer.push_front(currentNode->right->val);
                        currentQue.push(currentNode->right);
                    }  
                    
                }
                else{
                    if(currentNode->left != nullptr){
                        layer.push_back(currentNode->left->val);
                        currentQue.push(currentNode->left);
                    }
                    if(currentNode->right != nullptr){
                        layer.push_back(currentNode->right->val);
                        currentQue.push(currentNode->right);
                    } 
                }
               currentQue.pop();

            }
            if(layer.empty() == false)
                result.push_back(vector<int>(layer.begin(), layer.end()));
            rtl = !rtl;
            
        }
        return result;
    }
};