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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return {};
        TreeNode *head = root;
        traversal(root);
        sort(v.begin(), v.end(),[] 
             (const pair<int, TreeNode*> &lhs, const pair<int, TreeNode*> &rhs) {
                return lhs.first < rhs.first; 
             });
        if (v.size() == 1) {
            return head;
        }
        head = v[0].second;
        TreeNode *res = head;
        decltype(v.size()) i = 0;
        while (i != v.size()) {
            if (i == v.size() - 1) {
                *head = TreeNode(v[i].first);
            } else {
                *head = TreeNode(v[i].first, nullptr ,v[i + 1].second);
                head = head->right;
            }
            ++i;
        }
        return res;       
    }
private:
    vector<pair<int, TreeNode*>> v;
    
};

int main() {

  return 0;
}
