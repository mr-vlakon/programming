class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int cnt = count(suits.cbegin(), suits.cend(), suits[0]);
        if (cnt == suits.size())
            return "Flush";
        unordered_map<int, size_t> um;
        for (const auto &e: ranks) {
            ++um[e];
        }
        
        for (const auto &e: um) {
            if (e.second >= 3) {
                return "Three of a Kind";
            }
        }
        
        for (const auto &e: um) {
            if (e.second == 2) {
                return "Pair";
            }
        }
        return "High Card";
        
    }
};

int main() {
  
  
  
  return 0;  
}
