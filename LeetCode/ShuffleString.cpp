class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result;
        map<size_t, char> map;
        int i = 0;
        for (const auto &c: s) {
            map[indices[i]] = c;
            ++i;
        }
        for (const auto &e: map) {
            result.push_back(e.second);
        }
        
        return result;
    }
};

int main() {
  
  
  return 0;  
}
