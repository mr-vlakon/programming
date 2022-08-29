class Solution {
public:
    string frequencySort(string s) {
        map<char, int> map;
        for (const auto &c: s)
            map[c]++;
        vector<pair<char,int>> v(map.cbegin(), map.cend());   
        sort(v.begin(), v.end(), [](const pair<char, int> &lhs, const pair<char, int> &rhs) {
           return lhs.second > rhs.second; 
        });
        string s1;
        for(const auto &e: v) {
            int cnt = e.second;
            while (cnt--) {
                s1.push_back(e.first);
            }
        }
        return s1;  
    }
};

int main() {
  
  return 0;  
}
