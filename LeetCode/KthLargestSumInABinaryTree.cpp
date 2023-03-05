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
    void traverse(TreeNode * &root, int i) {
        if (root == nullptr) return;
        v[i].push_back(root->val);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int size = depth(root);
        v.resize(size);
        traverse(root, 0);
        long long s = 0;
        for (const auto &e: v) {
            s = accumulate(e.cbegin(), e.cend(), 0LL);
            sum.push_back(s);
        }
        sort(sum.rbegin(), sum.rend());
        if ((k - 1) >= sum.size()) {
            return -1;
        }
        return sum[k - 1];
    }
private:
    vector<long long> sum;
    vector<vector<int>> v;
};

int main() {
  
  
  
  return 0;  
}
