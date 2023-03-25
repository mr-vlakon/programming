class Solution {
public:
    void binary(const int &trips, const vector<int> &nums, long long &left, long long &right) {
        if (left > right) {
            return;
        }
        mid = (left + right) / 2;
        tmp = 0;
        cnt = 0;
        for (int i = 0; i != nums.size(); ++i) {
            cnt += (mid + 1) / nums[i];
        }
        if (cnt >= trips) {
            right = mid - 1;
            answer = min(answer, mid + 1);
            binary(trips, nums, left, right);
        } else {
            left = mid + 1;
            binary(trips, nums, left, right);
        }
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxEl = *min_element(time.cbegin(), time.cend());
        long long sum = static_cast<long long>(totalTrips) * maxEl;
        long long left = 0;
        binary(totalTrips, time, left, sum);
        return answer;
    }
private:
    long long cnt = 0;
    long long mid = 0;
    long long tmp = 0;
    long long answer = 1000000000000000000;
};

int main() {
  
  
  
  return 0;  
}
