class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<size_t>> um;
        size_t ind = 0;
        for (const auto &e: cards) {
            um[e].push_back(ind);
            ++ind;
        }
        int min = 10000000;
        for (const auto &e: um) {
            for (decltype(e.second.size()) i = 1; i != e.second.size(); ++i) {
                if ( e.second[i] - e.second[i - 1] + 1 < min)
                    min = e.second[i] - e.second[i - 1] + 1;
            }
        }
        return min == 10000000 ? -1 : min;
        
    }
};

int main() {
  
  
  
  return 0;  
}
