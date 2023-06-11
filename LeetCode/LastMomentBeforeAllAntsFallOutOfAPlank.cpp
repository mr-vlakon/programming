class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxL = 0;
        if (left.size() != 0)
            maxL = *max_element(left.cbegin(), left.cend());
        int maxR = n;
        if (right.size() != 0)
            maxR = *min_element(right.cbegin(), right.cend());
        return max(n - maxR, maxL);
    }
};

int main() {
  
  
  return 0;  
}
