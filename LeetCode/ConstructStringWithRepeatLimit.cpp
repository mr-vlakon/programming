class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, size_t> um;
        for (const auto &e: s) {
            ++um[e];
        }
        priority_queue<pair<char, size_t>> pq;
        for (const auto &e: um) {
            pq.push({e.first, e.second});
        }
        
        string res;
        char prev = '&';
        int cnt = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (prev != top.first) {
                cnt = 0;
            }
            if (cnt == repeatLimit && !pq.empty()) {
                auto sec = pq.top();
                pq.pop();
                res += sec.first;
                --sec.second;
                if (sec.second != 0)
                    pq.push(sec);
                prev = sec.first;
                cnt = 0;
            
            } else if (cnt != repeatLimit){
                res += top.first;
                --top.second;
                prev = top.first;
                ++cnt;
            } else if (cnt == repeatLimit) {
                break;
            }
            if (top.second != 0)
                pq.push(top);
            
        }
        
        return res;        
    }
};

int main() {
  
  
  return 0;  
}
