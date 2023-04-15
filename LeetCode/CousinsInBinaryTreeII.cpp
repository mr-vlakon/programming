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
    int depth(TreeNode * &root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    void traverse(TreeNode * &root, int i, TreeNode * &par) {
        if (root == nullptr) return;
        v[i].push_back({{root->val, par}, root});
        traverse(root->left, i + 1, root);
        traverse(root->right, i + 1, root);
    }   
    TreeNode* replaceValueInTree(TreeNode* root) {
        int dep = depth(root);
        v.resize(dep, {});
        TreeNode *par = nullptr;
        traverse(root, 0, par);
        vector<long long> sums;
        sums.push_back(0);
        long long tmp = 0;
        for (int i = 1; i != v.size(); ++i) {
            tmp = 0;
            for (const auto &e: v[i]) {
                tmp += e.first.first;
            }
            sums.push_back(tmp);
        }
        tmp = 0;
        (*v[0][0].second).val = 0;
        for (int i = 1; i != v.size(); ++i) {
            for (int j = 0; j != v[i].size(); ++j) {
                tmp = sums[i];
                tmp -= v[i][j].first.first;
                if ((j + 1) < v[i].size()) {
                    if (v[i][j].first.second == v[i][j + 1].first.second) {
                        tmp -= v[i][j + 1].first.first;
                    }
                }
                if ((j - 1) >= 0) {
                    if (v[i][j].first.second == v[i][j - 1].first.second) {
                        tmp -= v[i][j - 1].first.first;
                    }
                }
                (*v[i][j].second).val = tmp;
            }
        }
        return root;
    }
private:
    vector<vector<pair<pair<int, TreeNode*>, TreeNode*>>> v;
};

int main() {
  
  
  return 0;  
}
