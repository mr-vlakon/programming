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
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        ++um[root->val];
        traverse(root->left);
        traverse(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        vector<pair<size_t, int>> tmp;
        traverse(root);
        for (const auto &e: um) {
            tmp.push_back({e.second, e.first});
        }
        sort(tmp.begin(), tmp.end(), 
             [=](const pair<size_t, int> &lhs, const pair<size_t, int> &rhs) {
                return lhs.first > rhs.first; 
             });
        vector<int> answer;
        int cnt = tmp[0].first;
        for (const auto &e: tmp) {
            if (e.first == cnt) {
                answer.push_back(e.second);
            } else {
                break;
            }
        }
        return answer;
    }
    
private:
    unordered_map<int, size_t> um;
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
