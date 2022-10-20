class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int small = size * 0.05;
        
        return accumulate(arr.cbegin() + small, arr.cend() - small, 0.0) / (size - 2 *small);
        
    }
};

int main() {
  
  
  return 0;  
}
