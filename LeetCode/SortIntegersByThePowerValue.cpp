class Solution {
public:
    
    int power(int x) {
        int steps = 0;
        while(x != 1) {
            ++steps;
            if(x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3*x + 1;
            }
        }
        return steps;
    }    
    int getKth(int lo, int hi, int k) {  
        size_t size = hi - lo + 1;
        vector<pair<int,int>> v;
        for(size_t i = 0; i != size; ++i) {
            int tmp = power(lo);
            v.push_back({tmp,lo++});
        }
        sort(v.begin(), v.end(),
             [](const pair<int,int> &lhs, const pair<int,int> &rhs) {
           return lhs.second < rhs.second; 
        });        
        stable_sort(v.begin(), v.end(),
             [](const pair<int,int> &lhs, const pair<int,int> &rhs) {
           return lhs.first < rhs.first; 
        });
        return v[k - 1].second;
    }
};

int main() {
  
  return 0;  
}
