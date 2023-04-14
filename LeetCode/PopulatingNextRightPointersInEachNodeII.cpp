/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int height(Node * &root) {
        if (root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void traverse(Node * &root, int i) {
        if (root == nullptr) return;
        v[i].push_back(root);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    Node* connect(Node* root) {
        v.resize(height(root), {});
        traverse(root, 0);
        for (const auto &e: v) {
            for (int j = 0; j != e.size(); ++j) {
                if (j != (e.size() - 1)) {
                    (*e[j]).next = e[j + 1];
                }
            }
        }
        return root;
    }
private:
    vector<vector<Node*>> v;
};
