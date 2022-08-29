class Solution {
public:
    vector<int> f(int n) {
        vector<int> result;
        while(n) {
            int tmp = n % 10;
            result.push_back(tmp);
            n /=10;
        }
        return result;
    }
    int addDigits(int num) {
        vector<int> result;
        int tmp = num;
        if (num < 10) return num;
        while(1) {
            auto v = f(tmp);       
            int curr = 0;
            for (const auto &e : v) {
                curr += e;
            }
            if (curr < 10 ) return curr;
            tmp = curr;
        }
        return 0;    
    }
};

int main() {
  
  return 0;  
}
