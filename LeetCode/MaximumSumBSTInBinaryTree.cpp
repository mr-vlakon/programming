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
    bool recurse(TreeNode * &root, long long &leftMax, long long &rightMin) {
        if (root == nullptr) return true;
        if (root->val >= leftMax) return false;
        if (root->val <= rightMin) return false;
        long long prev = leftMax;
        leftMax = root->val;
        bool st1 = recurse(root->left, leftMax, rightMin);
        leftMax = prev;
        prev = rightMin;
        rightMin = root->val;
        bool st2 = recurse(root->right, leftMax, rightMin);
        rightMin = prev;
        return st1 && st2;
    }
    bool isValidBST(TreeNode* root) {
        long long leftMax = 2147483648;
        long long rightMin = -2147483649;
        return recurse(root, leftMax, rightMin);  
    }
    int sumSubTree(TreeNode * &root) {
        if (root == nullptr) return 0;
        it = um.find(root);
        if (it != um.cend()) {
            return um[root];
        }
        um[root] = sumSubTree(root->left) + sumSubTree(root->right) + root->val;
        return um[root];
    }
    void traverse(TreeNode * &root, int &flag) {
        if (root == nullptr) {
            return;
        }
        if (flag == 0 && isValidBST(root)) {
            it = um.find(root);
            if (it == um.cend())
                um[root] = sumSubTree(root);
            flag = 1;
            answer = max(answer, um[root]);
        } else if (flag == 1) {
            um[root] = sumSubTree(root);
            answer = max(answer, um[root]);
        }
        traverse(root->left, flag);
        traverse(root->right, flag);
        flag = 0;
    }

    int maxSumBST(TreeNode* root) {
        int flag = 0;
        traverse(root, flag);
        return answer;
    }
private:
    unordered_map<TreeNode*, int>::iterator it;
    unordered_map<TreeNode*, int> um;
    int answer = 0;
};

int main() {
  
  
  
  
  return 0;  
}
