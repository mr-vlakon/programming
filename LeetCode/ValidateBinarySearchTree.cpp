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
};


int main() {
  
  
  
  return 0;  
}
