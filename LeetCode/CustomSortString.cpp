class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, size_t> um;
        for (const auto &e: s) {
            ++um[e];
        }
        string represent;
        string answer;
        unordered_set<char> us(order.cbegin(), order.cend());
        for (const auto &e: s) {
            auto it = us.find(e);
            if (it == us.cend()) {
                represent.push_back(e);
            }
        }
        
        for (const auto &e: order) {
            auto it = um.find(e);
            if (it != um.cend()) {
                answer += string(it->second, e);  
            }
        }
        answer += represent;
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
