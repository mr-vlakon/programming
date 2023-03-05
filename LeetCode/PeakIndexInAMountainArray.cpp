class Solution {
public:
    void recursive(const vector<int> &num, int &start, int &end, int &mid) {
        if (mid > 0 && mid < (num.size() - 1) && num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) {
            answer = mid;
            return;
        }
        if (mid == 0 && num[mid] > num[mid + 1]) {
            answer = mid;
            return;
        }
        if (mid == (num.size() - 1) && num[mid] > num[mid - 1]) {
            answer = mid;
            return;
        }
        if (start >= end) {
            return;
        }
        if ((mid + 1) < num.size() && num[mid] < num[mid + 1]) {
            start = mid + 1;
            mid = (start + end) / 2;
            recursive(num, start, end, mid);
        } else if ((mid - 1) >= 0 && num[mid] < num[mid - 1]) {
            end = mid - 1;
            mid = (start + end) / 2;
            recursive(num, start, end, mid);
        }
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 1) {
            return 0;
        }
        int start = 0;
        int end = arr.size() - 1;
        int mid = arr.size() / 2;
        recursive(arr, start, end, mid);
        return answer;
    }
private:
    int answer = 0;
};
/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto it = max_element(arr.cbegin(), arr.cend());
        return it - arr.cbegin();
    }
};
*/

int main() {
  
  return 0;  
}
