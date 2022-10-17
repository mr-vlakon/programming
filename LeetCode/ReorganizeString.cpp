class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, size_t> um;
        for (const auto &e: s) {
            ++um[e];
        }
        
        priority_queue<pair<size_t, char>> pq;
        
        for (const auto &e: um) {
            pq.push({e.second, e.first});
        }
        
        string res;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            --top.first;
            res += top.second;
            if (pq.empty() && top.first != 0) return "";
            if (pq.empty()) break;
            auto second = pq.top();
            pq.pop();
            --second.first;
            res += second.second;
            if (top.first != 0) {
                pq.push(top);
            }
            if (second.first != 0) {
                pq.push(second);
            }
            
        }
        
        return res;
    }
};

int main() {
  
  
  return 0;  
}
