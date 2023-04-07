class Solution {
public:
    void binary(const vector<int> &arr, const int &target, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        sum = 0;
        for (int i = 0; i != arr.size(); ++i) {
            if (arr[i] > mid) {
                sum += mid;
            } else {
                sum += arr[i];
            }
        }
        if (abs(sum - target) < diff) {
            answer = mid;
            diff = abs(sum - target);
        }
        if (sum >= target) {
            right = mid - 1;
            binary(arr, target, left, right);
        } else {
            left = mid + 1;
            binary(arr, target, left, right);
        }
    }
    int findBestValue(vector<int>& arr, int target) {
        int left = 0;
        int right = *max_element(arr.cbegin(), arr.cend()) + 1;
        diff = 100000000;
        binary(arr, target, left, right);
        return answer;
    }
private:
    int sum = 0;
    int mid = 0;
    int diff = 0;
    int answer = 0;
};

int main() {
  
  
  
  return 0;  
}
