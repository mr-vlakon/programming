class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int x = 0;
        int y = 0;
        for (int i = 0; i != asteroids.size(); ++i) {
            if (st.empty()) {
                st.push_back(asteroids[i]);
            } else if (signbit(st.back()) != signbit(asteroids[i]) && asteroids[i] < 0){
                x = asteroids[i];
                y = asteroids[i];
                while (!st.empty() && signbit(st.back()) != signbit(x)) {
                    if (abs(st.back()) > abs(x)) {
                        x = st.back();
                        y = INT_MIN;
                    } else if (abs(st.back()) < abs(x)){
                        st.pop_back();
                        
                    } else {
                        st.pop_back();
                        if (!st.empty()) {
                            x = st.back();
                        }
                        y = INT_MIN;
                    }
                }
                if (y != INT_MIN)
                    st.push_back(x);
            } else {
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};

int main() {
  
  
  
  return 0;  
}
