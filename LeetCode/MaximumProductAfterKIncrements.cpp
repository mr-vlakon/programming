class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.cbegin(), nums.cend());
        while(k) {
            auto x = pq.top();
            pq.pop();
            pq.push(x + 1);
            --k;
        }
        unsigned long long result = 1;
        unsigned int m = 1000000007;
        while(!pq.empty()) {
            result *= pq.top();
            pq.pop();
            result = result % m;
        }
        return result;
    }
};

int main() {
  
  return 0;  
}
