class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, size_t> um;
        for (const auto &e: barcodes) {
            ++um[e];
        }
        
        priority_queue<pair<size_t, int>> pq;
        for (const auto &e: um) {
            pq.push({e.second, e.first});
        }
        
        vector<int> answer;
        while (!pq.empty()) {
            pair<size_t, int> tmp1 = pq.top();
            --tmp1.first;
            answer.push_back(tmp1.second);

            pq.pop();
            if (pq.empty())
                break;
            
            pair<size_t, int> tmp2 = pq.top();
            
            answer.push_back(tmp2.second);
            --tmp2.first;
            
            pq.pop();
            
            if (tmp1.first != 0) {
                pq.push(tmp1);
            }
            if (tmp2.first != 0) {
                pq.push(tmp2);
            }            
        }
        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
