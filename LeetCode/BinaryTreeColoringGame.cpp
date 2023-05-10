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
    void traverse(TreeNode * &root, bool status, bool st) {
        if (root == nullptr) return;
        if (root->val == X) {
            status = true;
        }
        if (status) ++counter;
        if (st) ++counter1;
        cnt++;
        if (root->val != X) {
            traverse(root->left, status, st);
            traverse(root->right, status, st);
        } else {
            traverse(root->left, status, false);
            traverse(root->right, status, true);
        }
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        X = x;
        traverse(root, false, false);
        int tmpCnt3 = cnt - counter;
        int tmpCnt1 = counter1;
        int tmpCnt2 = counter - tmpCnt1 - 1;
        if (tmpCnt1 > (cnt - tmpCnt1)) {
            return true;
        }
        if (tmpCnt2 > (cnt - tmpCnt2)) {
            return true;
        }
        if (tmpCnt3 > (cnt - tmpCnt3) ) {
            return true;
        }
        return false;
    }
private:
    int counter = 0;
    int counter1 = 0;
    int X = 0;
    int cnt = 0;
};
/*
class Solution {
public:
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        if (root->val == X) root_ = root;
        cnt++;
        traverse(root->left);
        traverse(root->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        X = x;
        traverse(root);
        int allSums = cnt;
        cnt = 0;
        traverse(root_);
        secondCnt1 = cnt;
        cnt = 0;
        traverse(root_->left);
        int tmpCnt3 = allSums - secondCnt1;
        int tmpCnt1 = cnt;
        int tmpCnt2 = secondCnt1 - tmpCnt1 - 1;
        if (tmpCnt1 > (allSums - tmpCnt1)) {
            return true;
        }
        if (tmpCnt2 > (allSums - tmpCnt2)) {
            return true;
        }
        if (tmpCnt3 > (allSums - tmpCnt3) ) {
            return true;
        }
        return false;
    }
private:
    int X = 0;
    int cnt = 0;
    int secondCnt1 = 0;
    TreeNode *root_ = 0;
};
*/

int main() {
  
  
  
  return 0;  
}
