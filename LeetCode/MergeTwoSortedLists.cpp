
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        vector<pair<int, ListNode*>> v;
        while(list1 != nullptr) {
            v.push_back({list1->val, list1});
            list1 = list1->next;
        }
        while(list2 != nullptr) {
            v.push_back({list2->val, list2});
            list2 = list2->next;
        }
        sort(v.begin(), v.end(), [](const pair<int,ListNode*> &lhs,
                                    const pair<int,ListNode*> &rhs) {
            return lhs.first < rhs.first;    
        }    
        );
        if (v.size() != 0) {
            ptr1 = v[0].second;
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
