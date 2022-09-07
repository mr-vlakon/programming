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
        v.push_back({root->val, root});
        traversal(root->left);
        traversal(root->right);
    }
    void flatten(TreeNode* root) {
        TreeNode *head = root;
        traversal(root);
        if (v.size() != 0) {
            head = v[0].second;
        }
        TreeNode *res = head;
        decltype(v.size()) i = 0;
        while (i != v.size()) {
            if (i == v.size() - 1) {
                *head = TreeNode(v[i].first);
            } else {
                *head = TreeNode(v[i].first, nullptr, v[i + 1].second);
                head = head->right;
            }
            ++i;
        }
        root = res;
    }
private:
    vector<pair<int,TreeNode*>> v;
};

int main() {
  
  
  return 0;  
}
