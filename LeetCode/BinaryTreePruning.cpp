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
    bool consist1(TreeNode *root) {
        if (root == nullptr) return false;
        if (root->val == 1) return true;
        return consist1(root->left) || consist1(root->right);
    }
    
    void traversal(TreeNode* &root) {
        if (root == nullptr) return;
        if ((root != nullptr) && (root->val == 0) && (!consist1(root))) {
            root = nullptr;
            return;
        }
        
        if ((root->left != nullptr) && (root->left->val == 0) && (!consist1(root->left)))         {
                root->left = nullptr;
        }
            
        if ((root->right != nullptr) && 
            (root->right->val == 0) && (!consist1(root->right))) {
            root->right = nullptr;
        }
        traversal(root->left);
        traversal(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};

int main() {
  
  
  return 0;  
}
