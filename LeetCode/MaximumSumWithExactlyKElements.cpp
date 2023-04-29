class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (const auto &e: nums) {
            pq.push(e);
        }
        int i = 0;
        int top = 0;
        int score = 0;
        while (i < k) {
            top = pq.top();
            pq.pop();
            score += top;
            pq.push(top + 1);
            ++i;
        }
        return score;
    }
};

int main() {
  
  
  
  return 0;  
}
