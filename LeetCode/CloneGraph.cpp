/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        queue<Node*> q;
        q.push(node);
        unordered_map<int, vector<int>> um;
        vector<bool> visited(100, false);
        Node *top = nullptr;
        while (!q.empty()) 
        {
            top = q.front();
            q.pop();
            visited[top->val - 1] = true;
            for (const auto &e: top->neighbors) 
            {
                if (visited[e->val - 1] == false)
                {
                    um[top->val].push_back(e->val);
                    um[e->val].push_back(top->val);
                    q.push(e);
                }
            }
        }
        vector<Node*> v(visited.size(), nullptr);
        for (int i = 1; i <= visited.size(); ++i) {
            v[i -  1] = new Node(i);
        }
        for (const auto &e: um)
        {
            for (const auto &p: e.second) 
            {
                (v[e.first - 1]->neighbors).push_back(v[p - 1]);
            }
        }
        return v[0];
    }
};

int main() {
  
  
  
  
  return 0;  
}
