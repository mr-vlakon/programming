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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i != nums.size(); ++i) {
            us.insert(nums[i]);
        }
        int cnt = 0;
        int tmp1 = 0;
        auto it1 = us.find(1);
        while (head) {
            it1 = us.find(head->val);
            if (it1 != us.cend()) {
                ++tmp1;
            } else if (tmp1 != 0) {
                ++cnt;
                tmp1 = 0;
            }
            head = head->next;
        }
        if (tmp1 != 0) {
            ++cnt;
        }        
        return cnt;
  }
};

int main() {
  
  
  
  return 0;  
}
