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
    void deapth(TreeNode* &root, int i) {
        if (root == nullptr) {
            dep.push_back(i);
            return;
        }
        deapth(root->left, i + 1);
        deapth(root->right, i + 1);
    }
    
    void trv(TreeNode* &root, int i) {
        if (root == nullptr) return;
        v[i].push_back({root, root->val});
        trv(root->left, i + 1);
        trv(root->right, i + 1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        deapth(root, 0);
        int max = *max_element(dep.cbegin(), dep.cend());
        v.resize(max);
        trv(root, 0);
        for (decltype(v.size()) i = 0; i != v.size(); ++i) {
            if (i % 2 == 1) {
                int j = 0;
                while (j != v[i].size() / 2) {
                    int tmp = v[i][j].second; 
                    v[i][j].second = v[i][v[i].size() - j - 1].second;
                    v[i][j].first->val = v[i][j].second;
                    v[i][v[i].size() - j - 1].first->val = tmp;
                    ++j;
                }
            }
        }
        return root;   
    }
private:
    vector<int> dep;
    vector<vector<pair<TreeNode*, int>>> v;
};

int main() {
 
  return 0;
}
