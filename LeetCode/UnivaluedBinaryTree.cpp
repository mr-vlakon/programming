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
    void traversal(TreeNode *root) {
        if (root == nullptr) return;
        v.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) return true;
        TreeNode *head = root;
        traversal(root);
        unordered_map<int, size_t> um;
        for (const auto &e: v) {
            ++um[e];
        }
        return um.size() == 1;
    }
private:
    vector<int> v;
};

int main() {
  
  return 0; 
}
