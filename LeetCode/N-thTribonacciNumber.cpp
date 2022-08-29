class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(38);
        v[0] = 0;
        v[1] = 1;
        v[2] = 1;
        int i = 3;
        while (i <= n) {
            v[i] = v[i - 3] + v[i - 2] + v[i - 1]; 
            ++i;
        }
        return v[n];
    }
};

int main() {

  return 0;
}
