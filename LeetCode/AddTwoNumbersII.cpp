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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = l1;
        
        ListNode* ptr1 = l1;
        ListNode* pptr1 = l1;
        ListNode* ptr2 = l2;        
        vector<int> v1;
        while(l1 != nullptr) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        reverse(v1.begin(), v1.end());
        
        vector<int> v2;        
        while(l2 != nullptr) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(v2.begin(), v2.end());

        int tmp = 0;
        int result = 1;
        int j = 0;
        vector<pair<int, ListNode*>> v;
        while(j < max(v1.size(), v2.size()))
        {
            if (ptr1 == nullptr) {
                ptr1 = ptr2;
            }
            result = tmp;
            if (j < v1.size()) 
                result += v1[j];
            if (j < v2.size()) 
                result += v2[j];
            if (result >= 10)
                tmp = result / 10;
            else 
                tmp = 0;
            if (result / 10 >= 1)
                v.push_back({result % 10 , ptr1});
            else
                v.push_back({result, ptr1});
            ptr1 = ptr1->next;
            ++j;
        }
        if (tmp > 0) {
            if (ptr1 == nullptr) {
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
            v.push_back({tmp, ptr1});
        }        
        reverse(v.begin(), v.end());
        if (v.size() != 0) {
            pptr1 = v[0].second;
        }
        ListNode *res = pptr1;
        decltype(v.size()) i = 0;
        while(i != v.size()) {
            if (i == v.size() - 1 ) {      
                *pptr1 = ListNode(v[i].first);
                break;
            } else {
                *pptr1 = ListNode(v[i].first, v[i+1].second);
                pptr1 = pptr1->next;
            }
            ++i;
        }
        return res;        
    }
};

int main() {
 
  return 0;
}
