class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (auto &e: timePoints) {
            int xhb = stoi(string{e.cbegin(), e.cbegin() + 2});
            int xmb = stoi(string{e.cbegin() + 3, e.cend()});
            int startx = xhb * 60 + xmb;
            v.push_back(startx);
        }

        sort(v.begin(), v.end());
        int min = 1000000;
        int max = -10000;
        for (int i = 0; i != v.size() - 1; ++i) {
                if (abs(v[i] - v[i + 1]) < min) {
                    min = abs(v[i + 1] - v[i]);
                }
                if (abs(v[i] - v[i + 1]) > max) {
                    max = abs(v[i + 1] - v[i]);
                }
                if (abs(v[i] - v.back()) < min) {
                    min = abs(v[i] - v.back());
                }
                if (abs(v[i] - v.back()) > max) {
                    max = abs(v[i] - v.back());
                }
        }
        
        if (min >= 720) {
            min = 1440 - min;
        }
        
        if (max >= 720) {
            max = 1440 - max;
        }
        return max > min ? min : max;
        
    }
};

int main() {
  
  
  
  return 0;  
}
