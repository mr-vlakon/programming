/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traverse(Node * &root, int i) {
        if (root == nullptr) return;
        if ((root->children).size() == 0) {
            return;
        }
        for (auto &e: root->children) {
            traverse(e, e->val);
            v.push_back(e->val);
        }
    }
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        traverse(root, root->val);
        v.push_back(root->val);
        return v;
    }
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
