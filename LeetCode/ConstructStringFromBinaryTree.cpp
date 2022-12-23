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
    void traverse(TreeNode *&root) {
        if (root == nullptr) {
            return;
        }
        result += to_string(root->val);
        if (root->right != nullptr || root->left != nullptr) {
            result.push_back('(');
            traverse(root->left);
            result.push_back(')');
        }
        if (root->right != nullptr) {
            result.push_back('(');
            traverse(root->right);
            result.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        result += to_string(root->val);
        if (root->left != nullptr || (root->right != nullptr)) {
            result.push_back('(');
            traverse(root->left);
            result.push_back(')');
        }
        if (root->right != nullptr) {
            result.push_back('(');
            traverse(root->right);
            result.push_back(')');
        }
        return result;
    }
private:
    string result;
};

int main() {
  
  
  
  return 0;  
}
