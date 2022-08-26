 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<pair<int,ListNode*>> v;
        ListNode *ptr = head;
        while (head != nullptr) {
            v.push_back({head->val, head});
            head = head->next;
        }
        vector<int> l;
        for (const auto &e : v) {
            l.push_back(e.first);
        }
        vector<pair<int, ListNode*>> v2;
        for (decltype(v.size()) i = 0; i != v.size(); ++i) {
            if (count(l.begin(), l.end(), v[i].first) > 1) {        
            } else {
                v2.push_back({v[i].first,v[i].second});
            }
        }
        if (v2.size() != 0) {
            ptr = v2[0].second;
        } else {
            return nullptr;
        }
        ListNode *res = ptr;
        decltype(v2.size()) i = 0;
        while (i != v2.size()) {
            if (i == v2.size() - 1) {
                *ptr = ListNode(v2[i].first);
            } else {
                *ptr = ListNode(v2[i].first, v2[i + 1].second);
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
