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
    void height(Node * root, int i) {
        if (root == nullptr) return;
        if ((root->children).size() == 0) {
            v.push_back(i);
            return;
        }
        for (auto &e: root->children) {
            height(e, i + 1);
        }
    }
    
    int maxDepth(Node* root) {
        height(root, 1);
        if (v.size() != 0)
            return *max_element(v.cbegin(), v.cend());
        else
            return 0;
    }
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
