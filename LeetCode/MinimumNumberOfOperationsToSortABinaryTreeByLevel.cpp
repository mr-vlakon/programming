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
    int height(TreeNode *root) {
        if (root == nullptr) return 0;
        int lhs = height(root->left);
        int rhs = height(root->right);
        return lhs > rhs ? lhs + 1 : rhs + 1;
    }
    
    void traverse(TreeNode *root, int i) {
        if (root == nullptr) return;
        v[i].push_back(root->val);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    
    int minimumOperations(TreeNode* root) {
        int hgt = height(root);
        v.resize(hgt);
        traverse(root, 0);   
        vector<vector<int>> tmp = v;
        int i = 0;
        int answer = 0;
        for (auto &e: v) {
            sort(tmp[i].begin(), tmp[i].end());
            unordered_map<int, size_t> um;
            for (int k = 0; k != e.size(); ++k) {
                um[v[i][k]] = k;
            }
            for (int j = 0; j != e.size(); ++j) {
                if (v[i][j] != tmp[i][j]) {
                    ++answer;
                    int temporary = v[i][j];    
                    swap(v[i][j], v[i][um[tmp[i][j]]]);    
                    um[temporary] = um[tmp[i][j]];
                    um[tmp[i][j]] = j;
                }
            }
            ++i;
        }
        return answer;
    }
private:
    vector<vector<int>> v;
};

int main() {
  
  
  
  return 0;  
}
