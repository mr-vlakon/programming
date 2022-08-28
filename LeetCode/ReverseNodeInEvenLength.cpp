/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<pair<int,ListNode*>> v;
        ListNode *ptr = head;
        while (head != nullptr) {
            v.push_back({head->val, head});
            head = head->next;
        }

        if(v.size() == 0) return nullptr;
        
        auto group_len = 1;
        auto it = v.begin();
        if (v.size() == 2) {
                                    
        } else {
            while(it <= v.end()) {
                if (it + group_len >= v.end()) {
                    if ((v.end() - it) % 2 == 0) {
                        reverse(it, v.end());
                    }
                    break;
                }
                if (group_len % 2 == 1) {
                    
                } else {
                    reverse(it, it + group_len);
                }
                    it = it + group_len;
                    group_len += 1;
                }
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
