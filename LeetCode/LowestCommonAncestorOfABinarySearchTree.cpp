/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void traverse(TreeNode * &root, vector<TreeNode *> x) {
        if (root == nullptr) return;
        if (root == pp) {
            x.push_back(root);
            v1 = x;
        }
        if (root == qq) {
            x.push_back(root);
            v2 = x;
        }
        x.push_back(root);
        traverse(root->left, x);
        traverse(root->right, x);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pp = p;
        qq = q;
        traverse(root, {});
        
        TreeNode * answer;
        for (const auto &e: v1) {
            auto it = find(v2.cbegin(), v2.cend(), e);
            if (it != v2.cend())
                answer = *it;
        }
        return answer;
    }
private:
    vector<TreeNode *> v1;
    vector<TreeNode *> v2;
    TreeNode *pp;
    TreeNode *qq;
};

int main() {
  
  
  return 0;  
}
