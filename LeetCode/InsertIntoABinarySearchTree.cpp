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
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        if (root->val > val_ && root->left == nullptr) {
            root->left = new TreeNode(val_);
            return;
        } else if (root->val < val_ && root->right == nullptr) {
            root->right = new TreeNode(val_);
            return;
        }
        if (root->val > val_)
            traverse(root->left);
        if (root->val < val_)
            traverse(root->right); 
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        val_ = val;
        if (root == nullptr) return new TreeNode(val);
        if (val > root->val) {
            if (root->right == nullptr) {
                root->right = new TreeNode(val_);
            } else
                traverse(root->right);
        } else {
            if (root->left == nullptr) {
                root->left = new TreeNode(val_);
            } else
                traverse(root->left);
        }
        return root;
    }
private:
    int val_ = 0;
};

int main() {
  
  
  
  return 0;  
}
