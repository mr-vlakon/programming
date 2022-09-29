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
    void traversal(TreeNode *root, string s) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            s += to_string(root->val);
            result.push_back(s);
            return;
        }
        s += to_string(root->val) + "->";
        traversal(root->left, s);
        traversal(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        traversal(root, "");
        return result;
    }
private:
    vector<string> result;
};

int main() {
  
  return 0;  
}
