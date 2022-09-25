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
    void trv(TreeNode *root, int i) {
        if (root == nullptr) {
            v.push_back(i);
            return;
        }
        trv(root->left, i + 1);
        trv(root->right, i + 1);
    }
    
    void traverse(TreeNode *root, int i) {
        if (root == nullptr) return;
        result[i].push_back(root->val);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    
    int maxLevelSum(TreeNode* root) {
        int i = 0;
        trv(root, i);
        int x = *max_element(v.cbegin(), v.cend());
        result.resize(x);
        traverse(root, i);
        int index = 1;
        int answer = 1;
        int max = accumulate(result[0].cbegin(), result[0].cend(), 0);
        for (const auto &e: result) {
            int sum = accumulate(e.cbegin(), e.cend(), 0);
            if (sum > max) {
                max = sum;
                answer = index;
            }
            ++index;
        }
        return answer;
    }
private:
    vector<vector<int>> result;
    vector<int> v;
    
};

int main() {

  
  
  return 0;  
}
