class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, size_t> um;
        for (const auto &e: arr) {
            ++um[e];
        }
        
        deque<pair<int, size_t>> deq;
        for (const auto &e: um) {
            deq.push_back({e.first, e.second});
        }
        
        sort(deq.begin(), deq.end(), 
             [](const pair<int, size_t> &lhs, const pair<int, size_t> &rhs) {
                return lhs.second < rhs.second; 
             });
        while (k) {
            if (k >= deq.front().second) {
                k -= deq.front().second;
                deq.erase(deq.cbegin());
            } else {
                k = 0;
                break;
            }            
        }
        return deq.size();
    }
};

int main() {
  
  
  return 0;  
}
