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
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    void create(TreeNode * &root) {
        if (root == nullptr) return;
        auto it = find_if(res.cbegin(), res.cend(),[=](const pair<int, int>  &x) {
            return x.first == root->val;  
        });
        root->val = it->second;
        create(root->left);
        create(root->right);
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        sort(v.begin(), v.end());
        int sum = accumulate(v.cbegin(), v.cend(), 0);
        for (const auto &e: v) {
            res.push_back({e, sum});
            sum -= e;
        }
        create(root);
        return root;
        
    }
private:
    vector<pair<int, int>> res;
    vector<int> v;
};

int main() {  


  return 0;
}
