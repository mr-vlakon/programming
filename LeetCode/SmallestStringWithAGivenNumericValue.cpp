class Solution {
public:
    string getSmallestString(int n, int k) {
        string result;
        while (result.size() != n) {
            int x = k - (n - result.size());
            if (x > 25) {
                x = 25;
            }
            result.push_back(x + 'a');
            k -= x + 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
  
  
  return 0;  
}
