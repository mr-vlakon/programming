class Solution {
public:
    void binary(const vector<int> &bloomDay, const int &m, const int &k, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        cnt = 0;
        tmp = 0;
        for (int i = 0; i != bloomDay.size(); ++i) {
            if (bloomDay[i] <= (mid + 1)) {
                ++cnt;
            } else {
                cnt = 0;
            }
            if (cnt >= k) {
                ++tmp;
                cnt = 0;
            }
        }
        if (tmp >= m) {
            answer = min(answer, (mid + 1));
            right = mid - 1;
            binary(bloomDay, m, k, left, right);
        } else {
            left = mid + 1;
            binary(bloomDay, m, k, left, right);
        }
 
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int right = *max_element(bloomDay.cbegin(), bloomDay.cend()) + 1;
        int left = 0;
        binary(bloomDay, m, k, left, right);
        if (answer == 1000000001) return -1;
        return answer;
    }
private:
    int tmp = 0;
    int cnt = 0;
    int mid = 0;
    int answer = 1000000001;
};

int main() {
  
  
  
  return 0;  
}
