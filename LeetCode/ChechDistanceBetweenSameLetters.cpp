class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, vector<int>> um;
        int index = 0;
        for (const auto &e : s) {
            um[e].push_back(index);
            ++index;
        }
        for (const auto &e: um) {
            if((abs(e.second[0] - e.second[1]) - 1) != distance[e.first - '0' - 49])
                return false;
        }        
        return true;
    }
};

int main() {
  
  
  return 0;  
}
