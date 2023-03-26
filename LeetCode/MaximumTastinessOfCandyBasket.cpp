class Solution {
public:
    void binary(const vector<int> &price, const int &k, int &left, int &right) {
        if (left > right) {
            return;
        }
        mid = (left + right) / 2;
        cnt = 0;
        for (int i = 0; i != price.size(); ++i) {
            if (lastTaken == 0) {
                lastTaken = price[i];
                ++cnt;
            } else if ((price[i] - lastTaken) >= (mid + 1)) {
                ++cnt;
                lastTaken = price[i];
            }
        }
        lastTaken = 0;
        if (cnt >= k) {
            answer = max(answer, (mid + 1));
            left = mid + 1;
            binary(price, k, left, right);
        } else {
            right = mid - 1;
            binary(price, k, left, right);
        }
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 0;
        int right = *max_element(price.cbegin(), price.cend()) + 1;
        binary(price, k, left, right);
        return answer;
    }
private:
    int lastTaken = 0;
    int mid = 0;
    int cnt = 0;
    int answer = 0;
};

int main() {
  
  
  
  return 0;  
}
