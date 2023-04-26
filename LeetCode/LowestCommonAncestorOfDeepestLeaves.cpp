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
 
    void recurse(TreeNode *&root, vector<pair<TreeNode*, int>> &v, int i) {
        if (root == nullptr) {    
            return;
        }
        if (i == (dep - 1)) {
            ++cnt;
            v.push_back({root, i});
            for (const auto &e: v) {
                um[e.first].first = e.second;
                um[e.first].second++;
            }
            v.pop_back();
            return;
        }
        v.push_back({root, i});
        recurse(root->left, v, i + 1);
        recurse(root->right, v, i + 1);
        v.pop_back();
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dep = depth(root);
        vector<pair<TreeNode*, int>> v;
        recurse(root, v, 0);
        int maxV = -1;
        for (const auto &e: um) {
            if (e.second.second == cnt && e.second.first > maxV) {
                maxV = e.second.first;
                ans = e.first; 
            }
        }
        return ans; 
    }
private:
    TreeNode *ans = nullptr;
    int dep = 0;
    int cnt = 0;
    unordered_map<TreeNode*, pair<int, int>> um;
};

int main() {
  
  
  
  
  return 0;  
}
