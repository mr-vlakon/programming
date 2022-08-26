 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
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
        auto t = count(l.cbegin(), l.cend(), val);
        while (t) {
            auto it = find_if(v.cbegin(), v.cend(), [=](const pair<int,ListNode*> &lhs) {
               return lhs.first == val; 
            });
            if (it == v.cend()) {
                break;
            } else
                v.erase(it);
            --t;
        }
        
        if (v.size() != 0) {
            ptr = v[0].second;
        } else {
            return nullptr;
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
