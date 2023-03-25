class Solution {
public:
    void binary(const int &days, const vector<int> &nums, int &left, int &right) {
        if (left > right) {
            return;
        }
        mid = (left + right) / 2;
        tmp = 0;
        cnt = 0;
        for (const auto &e: nums) {
            if (e > (mid + 1)) {
                cnt = 1000000000;
                break;
            }
            tmp += e;
            if (tmp > (mid + 1)) {
                ++cnt;
                tmp = e;
            }
        }
        if (tmp <= (mid + 1)) {
            ++cnt;
        }
        if (cnt >= days) {
            if (cnt == days) {
                answer = min(answer, mid + 1);
                right = mid - 1;
                binary(days, nums, left, right);
            } else {
                left = mid + 1;
                binary(days, nums, left, right);
            } 
        } else {
            answer = min(answer, mid + 1);
            right = mid - 1;
            binary(days, nums, left, right);
        }
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.cbegin(), weights.cend(), 0) - 1;
        int left = 0;
        binary(days, weights, left, sum);
        return answer;
    }
private:
    int cnt = 0;
    int mid = 0;
    int tmp = 0;
    int answer = 1000000001;
};

int main() {
  
  
  
  return 0;  
}
