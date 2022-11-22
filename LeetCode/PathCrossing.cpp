class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        st.insert({0,0});
        pair<int, int> prev = {0, 0};
        for (const auto &e: path) {
            if (e == 'N') {
                prev.second++;
            }
            if (e == 'E') {
                prev.first++;
            }
            if (e == 'W') {
                prev.first--;
            }
            if (e == 'S') {
                prev.second--;
            }
            auto it = st.insert(prev);
            if (it.second == false)
                return true;
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
