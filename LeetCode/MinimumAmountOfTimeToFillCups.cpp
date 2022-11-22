class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (const auto &e: amount) {
            if (e != 0)
                pq.push(e);
        }
        int answer = 0;
        while (!pq.empty()) {
            ++answer;
            auto top = pq.top();
            pq.pop();
            if (pq.empty()) {
                --top;
                if (top != 0) {
                    pq.push(top);
                }
            } else {
                auto second = pq.top();
                --second;
                --top;
                pq.pop();
                if (top != 0) {
                    pq.push(top);
                }
                if (second != 0) {
                    pq.push(second);
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
