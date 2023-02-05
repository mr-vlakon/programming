class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long answer = 0;
        priority_queue<long long> pq(gifts.cbegin(), gifts.cend());
        int i = 0;
        while (i < k) {
            auto top = pq.top();
            pq.pop();
            pq.push(floor(sqrt(top)));
            ++i;
        }
        while (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }        
        return answer;
        
    }
};

int main() {
  
  
  return 0;  
}
