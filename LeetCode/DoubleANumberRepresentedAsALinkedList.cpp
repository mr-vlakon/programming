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
    ListNode* doubleIt(ListNode* head) {
        vector<int> tmp;
        ListNode *t = head;
        while (t) {
            tmp.push_back(t->val);
            t = t->next;
        }
        reverse(tmp.begin(), tmp.end());
        int i = 0;
        int perenos = 0;
        while (i != tmp.size()) {
            tmp[i] *= 2;
            tmp[i] += perenos;
            if (tmp[i] > 9) {
                int temp = tmp[i];
                tmp[i] = tmp[i] % 10;
                perenos = temp / 10;
                
            } else {
                perenos = 0;
            }
            ++i;
        }
        if (perenos != 0) {
            int tt = tmp.back();
            tmp.push_back(perenos);
        }
        reverse(tmp.begin(), tmp.end());
        t = head;
        i = 0;
        ListNode *prev = t;
        while (t) {
            t->val = tmp[i];
            prev = t;
            t = t->next;
            ++i;
        }
        if (i != tmp.size()) {
            prev->next = new ListNode(tmp.back());
        }
        return head;
    }
};
