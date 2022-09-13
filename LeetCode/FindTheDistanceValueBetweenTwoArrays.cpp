class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (const auto &e: arr1) {
            bool status = true;
            for (const auto &p: arr2) {
                if(abs(p - e) <= d) {
                    status = false;
                    break;
                }
            }
            if (status)
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0; 
}
