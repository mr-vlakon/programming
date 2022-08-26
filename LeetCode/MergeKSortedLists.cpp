
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto beg = lists.begin();
        auto end = lists.end();
        if (beg == end) return nullptr;
        ListNode* ptr1;
        vector<pair<int, ListNode*>> v;
        while(beg != end) {
            ptr1 = *beg;
            while (ptr1 != nullptr) {
                v.push_back({ptr1->val, ptr1});
                ptr1 = ptr1->next;
            }
            ++beg;
        }
        sort(v.begin(), v.end());
        if (v.size() != 0) {
            ptr1 = v[0].second;
        } else {
            return nullptr;
        }
        ListNode *res = ptr1;
        decltype(v.size()) i = 0;
        while(i != v.size()) {
            if (i == v.size() - 1 ) {      
                *ptr1 = ListNode(v[i].first);
                break;
            } else {
                *ptr1 = ListNode(v[i].first, v[i+1].second);
                ptr1 = ptr1->next;
            }
            ++i;
        }     
        return res;
    }
};

int main() {
  
  return 0; 
}
