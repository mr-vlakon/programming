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
    void traverse(TreeNode * &root, vector<int> v) {
        if(root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            ++v[root->val];
            int cntNch = 0;
            for (const auto &e: v) {
                if (e % 2 == 1) {
                    ++cntNch;
                }
                if (cntNch > 1) {
                    break;
                }
            }
            if (cntNch <= 1) {
                ++answer;
            }
            return;
        }        
        ++v[root->val];
        traverse(root->left, v);
        traverse(root->right, v);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10, 0);
        traverse(root, v);
        return answer;
    }
private:
    int answer = 0;
 };

int main() {
  
  
  
  return 0;  
}
