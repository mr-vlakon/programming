class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v;
        int i = 1;
        while (i <= n) {
            if(n % i == 0) {
                v.push_back(i);
            }
            ++i;
        }
        sort(v.begin(), v.end());
        return (k <= v.size()) ? *(v.cbegin() + k - 1) : -1; 
        
    }
};

int main() {
  
  return 0;  
}
