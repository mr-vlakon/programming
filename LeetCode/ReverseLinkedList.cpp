 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<pair<int,ListNode*> > v;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            v.push_back({ptr->val, ptr});
            ptr = ptr->next;
        }
        reverse(v.begin(),v.end());
        if (v.size() != 0) {
            ptr = v[0].second;
        }
        ListNode *res = ptr;
        decltype(v.size()) i = 0;
        while(i != v.size()) {
            if (i == v.size() - 1 ) {      
                *ptr = ListNode(v[i].first);
                break;
            } else {
                *ptr = ListNode(v[i].first, v[i+1].second);
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
