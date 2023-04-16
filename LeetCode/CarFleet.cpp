class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i != position.size(); ++i) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), [] (pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        stack<pair<double, int>> st;
        st.push({v.back().first, v.back().second});
        double time = 0;
        double t = 0.0;
        double temp = 0;
        double tempPos = 0;
        pair<double, int> top;
        for (int i = v.size() - 2; i >= 0; --i) {
            tempPos = time * v[i].second + v[i].first;
            if (st.top().second < v[i].second) {
                top = st.top();
                t = (tempPos - top.first) / (top.second - v[i].second);
                temp = t * top.second + top.first;
                if (temp <= target) {
                    st.pop();
                    st.push({temp, top.second});
                    time += t;
                } else {
                    st.push({tempPos, v[i].second});
                }
            } else {
                st.push({tempPos, v[i].second});
            }
        }
        return st.size();
    }
};

int main() {
  
  
  
  return 0;  
}
