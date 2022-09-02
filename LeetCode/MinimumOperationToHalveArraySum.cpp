class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double initial_sum = accumulate(nums.cbegin(), nums.cend(), 0.0);
        for (const auto &e: nums) {
            pq.push(static_cast<double>(e));
        }
        double sum = 0;
        int cnt = 0;
        double result = initial_sum;
        while(true) {
            ++cnt;
            double x = pq.top();
            pq.pop();
            pq.push(static_cast<double>(x/2));
            result = result - x / 2;
            if (result <= (initial_sum / 2.0))
                return cnt;
        }
        return 0;
    }
};

int main() {

  
  return 0;  
}
