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
    Solution(ListNode* head) {
        ListNode *ptr = head;
        while (ptr != nullptr) {
            v.push_back({ptr->val, ptr});
            ptr = ptr->next;
        }
        
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
        head = res;
    }
    
    int getRandom() {
        if (v.size() == 1)
            return v[0].first;
        i = rand() % v.size();
        return v[i].first;
    }
private:
    vector<pair<int,ListNode*> > v;
    static int i;
};
int Solution::i = 1;

int main() {
  
 return 0; 
}
