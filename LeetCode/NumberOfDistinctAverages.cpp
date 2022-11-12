class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> us;
        deque<int> deq(nums.cbegin(), nums.cend());
        sort(deq.begin(), deq.end());
        while (deq.size() != 0) {
            auto min = deq[0];
            auto max = deq.back();
            us.insert(static_cast<double>(min + max) / 2.0);
            deq.erase(--deq.cend());
            deq.erase(deq.cbegin());
            
        }
        return us.size();
    }
};

int main() {
  
  
  return 0;  
}
