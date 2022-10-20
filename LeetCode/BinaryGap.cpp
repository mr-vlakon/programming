class Solution {
public:
    int binaryGap(int n) {
        string res;
        while(n) {
            res += to_string(n % 2);
            n /= 2;
        }
        
        int max = 0;
        int dist = 0;
        for (decltype(res.size()) i = 0; i != res.size(); ++i) {
            if (res[i] == '1') {
                auto it = find(res.cbegin() + i + 1, res.cend(), '1');
                if (it != res.cend()) {
                    dist = it - (res.cbegin() + i);
                    if (dist > max)
                        max = dist;
                }
            }
        }
        return max;   
    }
};

int main() {
  
  
  return 0;  
}
