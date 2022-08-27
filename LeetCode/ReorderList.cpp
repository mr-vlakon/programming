struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<pair<int,ListNode*>> v;
        ListNode *ptr = head;
        while (head != nullptr) {
            v.push_back({head->val, head});
            head = head->next;
        }
        
        vector<pair<int,ListNode*>> v2;
        if (v.size() != 0) {
            v2.push_back(v[0]);
        } else
            return;
        if (v.size() > 1) {
            v2.push_back(v[v.size() - 1]);
            for (decltype(v.size()) i = 2; i != v.size(); ++i) {
                if (i % 2 == 0) {
                    v2.push_back(v[i/2]);
                } else {
                    v2.push_back(v[v.size() - i/2 - 1]);
                }
            }
        }
        if (v2.size() != 0) {
            ptr = v2[0].second;
        } else {
            return;
        }
        ListNode *res = ptr;
        decltype(v2.size()) i = 0;
        while (i != v2.size()) {
            if (i == v2.size() - 1) {
                *ptr = ListNode(v2[i].first);
            } else {
                *ptr = ListNode(v2[i].first, v[i + 1].second);
                ptr = ptr->next;
            }
            ++i;
        }
        return;            
    }
};

int main() {
  
  return 0;  
}
