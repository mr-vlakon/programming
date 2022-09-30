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
    bool isTheSame(TreeNode * &l, TreeNode * &r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr && r != nullptr) return false;
        if (l != nullptr && r == nullptr) return false;
        if (l->val != r->val) return false;
        return isTheSame(l->left, r->left) && isTheSame(l->right, r->right);
    }
    
    bool traverse(TreeNode * &root, TreeNode * &sub) {
        if (root == nullptr) return false;
        if (isTheSame(root->left, sub) || isTheSame(root->right, sub)) return true;
        return traverse(root->left, sub) || traverse(root->right, sub);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isTheSame(root, subRoot)) return true;
        return traverse(root, subRoot);
    }
};

int main() {
  
  
  return 0;  
}
