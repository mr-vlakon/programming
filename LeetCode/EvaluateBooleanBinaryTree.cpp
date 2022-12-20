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
    void traverse(TreeNode *& root) {
        if (root == nullptr) return;
        if ((root->left != nullptr) && (root->right != nullptr) && (root->left->val == 1 || root->left->val == 0) && 
        (root->right->val == 1 || root->right->val == 0)) {
            status = true;
            if (root->val == 3) {
                root->val = root->left->val && root->right->val;
                root->left = nullptr;
                root->right = nullptr;
            } else if (root->val == 2) {
                root->val = root->left->val || root->right->val;
                root->left = nullptr;
                root->right = nullptr;
            }
            return;
        }
        traverse(root->left);
        traverse(root->right);
    }
    bool evaluateTree(TreeNode* root) {
        while(true) {
            traverse(root);
            if (status == false) {
                break;
            }
            status = false;
        }
        return root->val;
    }
private:
    bool status = false;
};

int main() {
  
  
  
  return 0;  
}
