class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.cbegin(), stones.cend());
        while (pq.size() > 1) {
            auto top = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            auto diff = top - second;
            if (diff == 0) {
                
            } else {
                pq.push(diff);
            }            
        }
        if (pq.size() != 0)
            return pq.top();
        else 
            return 0;
    }
};

int main() {
  
  
  
  return 0;  
}
