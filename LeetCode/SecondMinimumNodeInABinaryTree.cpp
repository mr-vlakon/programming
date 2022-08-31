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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        traversal(root);
        sort(v.begin(), v.end());
        auto p = unique(v.begin(), v.end());
        v.erase(p, v.end());
        if (v.size() == 1) return -1;
        return *(v.begin() + 1);  
    }
private:
    vector<int> v;
};

int main() {
  
  return 0;  
}
