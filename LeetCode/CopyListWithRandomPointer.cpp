/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<int> v;
        Node *tt = head;
        unordered_map<Node*, int> revInd;
        int i = 0;
        while (head) {
            revInd[head] = i;
            ++i;
            v.push_back(head->val);
            head = head->next;
        }
        if (v.size() == 0) {
            return nullptr;
        }
        unordered_map<int, int> rand;
        i = 0;
        while (tt) {
            if (tt->random != nullptr) {
                rand[i] = revInd[tt->random];
            } else {
                rand[i] = -1;
            }
            ++i;
            tt = tt->next;
        }
        unordered_map<int, Node*> un;
        i = 0;
        Node *newList = new Node(v[0], nullptr, nullptr);
        un[i] = newList;
        ++i;
        Node *top = newList;
        for (int k = 1; k != v.size(); ++k) {
            newList->next = new Node(v[k], nullptr, nullptr);
            newList = newList->next;
            un[i] = newList;
            ++i;
        }
        Node *t = top;
        for (int k = 0; k != v.size(); ++k) {
            if (rand[k] != -1) {
                t->random = un[rand[k]];
            } else { 
                t->random = nullptr;
            }
            t = t->next;  
        }
        return top;
    }
};

int main() {
  
  
  
  
  return 0;  
}
