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
    void traverse(TreeNode * &root, int row , int col) {
        if (root == nullptr) return;
        um[col].push_back({row, root->val});
        traverse(root->left, row + 1, col - 1);
        traverse(root->right, row + 1, col + 1);        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        for (auto &e: um) {
            sort(e.second.begin(), e.second.end(), [=]
                 (const pair<int, int> &lhs, const pair<int, int> &rhs) {
                     return lhs.second < rhs.second;
                 });

            stable_sort(e.second.begin(), e.second.end(), [=]
                 (const pair<int, int> &lhs, const pair<int, int> &rhs) {
                     return lhs.first < rhs.first;
                 });
            vector<int> tmp;
            for (const auto &p: e.second) {
                tmp.push_back(p.second);
            }
            res.push_back(tmp);
        }
        return res;
    }
    
private:
    map<int, vector<pair<int, int>>> um;
    vector<vector<int>> res;    
};

int main() {
  
  
  return 0;  
}
