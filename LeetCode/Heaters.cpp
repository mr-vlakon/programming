class Solution {
public:
    void binary(const vector<int> &houses, const vector<int> &heat, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        start1 = 0;
        start2 = 0;
        status = true;
        while (start1 != houses.size()) {
            while (start1 != houses.size() && start2 != heat.size() && 
                abs(houses[start1] - heat[start2]) > mid) {
                    ++start2;
                } 
            if (start2 == heat.size()) {
                status = false;
                break;
            }
            ++start1;
        }
        if (status) {
            answer = min(answer, mid);
            right = mid - 1;
            binary(houses, heat, left, right);
        } else {
            left = mid + 1;
            binary(houses, heat, left, right);
        }

    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int left = 0;
        int right = (houses.back() - houses[0]) + abs(heaters.back() - houses.back());
        binary(houses, heaters, left, right);
        return answer;
    }
private:
    bool status = false;
    int start1 = 0;
    int start2 = 0;
    int mid = 0;
    int answer = 2147483647;
};

int main() {
  
  
  
  return 0;  
}
