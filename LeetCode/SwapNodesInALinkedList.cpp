
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<pair<int,ListNode*>> v;
        ListNode *ptr = head;
        if (head == nullptr) return nullptr;
        while (head != nullptr) {
            v.push_back({head->val, head});
            head = head->next;
        }
        if (v.size() == 0) return nullptr;
        //if (k > v.size() / 2) return nullptr;
        if (v.size() != 1) {
            swap(v[k - 1], v[v.size() - k ]);
        }
        if (v.size() != 0) {
            ptr = v[0].second;
        }
        ListNode *res = ptr;
        decltype(v.size()) i = 0;
        while (i != v.size()) {
            if (i == v.size() - 1) {
                *ptr = ListNode(v[i].first);
            } else {
                *ptr = ListNode(v[i].first, v[i + 1].second);
                ptr = ptr->next;
            }
            ++i;
        }
        return res;              
    }
};

int main() {

  return 0; 
}
