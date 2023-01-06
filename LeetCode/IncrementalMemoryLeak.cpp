class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int start = 1;
        priority_queue<pair<int, int>> pq;
        pq.push({memory1, 2});
        pq.push({memory2, 1});
        while (!pq.empty() && (pq.top().first >= start)) {
            auto top1 = pq.top();
            pq.pop();
            if (top1.first >= start) {
                top1.first -= start;
                if (top1.second == 2) {
                    memory1 -= start;
                } else {
                    memory2 -= start;
                }
                ++start;
                if (top1.first >= start) {
                    pq.push(top1);
                }
            } else {
                break;
            }
        }
        return {start, memory1, memory2};
    }
};

int main() {
  
  
  
  return 0;  
}
