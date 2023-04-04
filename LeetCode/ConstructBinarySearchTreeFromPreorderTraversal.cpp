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
    void recurse(TreeNode * &root, stack<int> &st, int maxV) {
        if (st.empty()) {
            return;
        }
        root = new TreeNode(st.top());
        st.pop();
        if (st.empty()) {
            return; 
        }
        if (root->val > st.top() &&  maxV  > st.top()) {
            recurse(root->left, st, min(maxV, root->val));
        }
        if (st.empty()) {
            return; 
        }
        if (root->val < st.top() &&  maxV  > st.top()) {
            recurse(root->right, st, max(maxV, root->val));
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<int> st;
        for (int i = preorder.size() - 1; i >= 0; --i) {
            st.push(preorder[i]);
        }
        TreeNode *root = nullptr;
        int maxV = 10000000;
        recurse(root, st, maxV);
        return root;
    }
};

int main() {
  
  
  
  return 0;  
}
