class Solution {
public:
    int countLargestGroup(int n) {
        int i = 1;
        unordered_map<size_t, size_t> um;
        while (i <= n) {
            int x = i;
            int sumDig = 0;
            int cnt = 0;
            while (x) {
                int tmp = x % 10;
                sumDig += tmp;
                ++cnt;
                x /= 10;
            }
            ++um[sumDig];
            
            ++i;
        }
        int max = 0;
        for (const auto &e : um)  {
            if (e.second > max) 
                max = e.second;
        }
        int cnt = 0;
        for (const auto &e: um) {
            if (e.second == max)
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
 
  return 0;
}
