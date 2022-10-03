class Solution {
public:
    int commonFactors(int a, int b) {
        unordered_set<int> st;
        int i = 1;
        while (i <= a) {
            if (a % i == 0) {
                st.insert(i);
            }
            ++i;
        }
        
        i = 1;
        int cnt = 0;
        while (i <= b) {
            if (b % i == 0 && (st.find(i) != st.cend())) {
                ++cnt;
            }
            ++i;
        }
        return cnt;
    }
};

int main() {

  
  return 0;  
}
