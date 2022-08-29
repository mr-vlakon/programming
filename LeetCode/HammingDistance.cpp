class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> v1(32);
        int i = 0;
        while(x) {
            v1[i++] = x % 2;
            x /=2;
        }
        vector<int> v2(32);
        int j = 0;
        while(y) {
            v2[j++] = y % 2;
            y /=2;
        }
        int cnt = 0;
        for (decltype(v1.size()) k = 0; k != v1.size(); ++k) {
            if (v1[k] != v2[k])
                ++cnt;
        }
        return cnt;       
    }
};

int main() {
  
  return 0; 
}
