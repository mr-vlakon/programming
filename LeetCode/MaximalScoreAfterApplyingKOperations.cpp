class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.cbegin(), nums.cend());
        int i = 0;
        long long score = 0;
        while (i != k) {
            auto top = pq.top();
            pq.pop();
            score += top;
            top = ceil((static_cast<double>(top) / 3.0));
            pq.push(top);
            ++i;
        }
        return score;
    }
};

int main() {
  
  
  
  return 0;  
}
