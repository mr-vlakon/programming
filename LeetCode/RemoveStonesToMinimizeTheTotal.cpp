class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.cbegin(), piles.cend());
        while (k) {
            int tmp = pq.top();
            tmp = tmp - pq.top() / 2;
            pq.pop();
            pq.push(tmp);
            --k;
        }
        int cnt = 0;
        while (!pq.empty()) {
            cnt += pq.top();
            pq.pop();
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
