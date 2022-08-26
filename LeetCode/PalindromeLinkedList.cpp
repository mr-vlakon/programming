struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v1;
        while (head != nullptr) {
            v1.push_back(head->val);
            head = head->next;
        }
        vector<int> v2 = v1;
        reverse(v1.begin(), v1.end());
        if (v1 == v2) {
            return true;
        } else 
            return false;
        
    }
};

int main() {
  
  return 0; 
}
