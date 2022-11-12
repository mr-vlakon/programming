class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> um;
        for (int i = 0; i != s.size(); ++i) {
            um[s[i]].push_back(i);
        }
        
        int max = -1; 
        for (const auto &e: um) {
            if (e.second.size() >= 2) {
                int tmp = e.second.back() - e.second[0] - 1;
                if (tmp > max)
                    max = tmp;
            }
        }
        return max;
    }
};

int main() {
  
    
  return 0;  
}
