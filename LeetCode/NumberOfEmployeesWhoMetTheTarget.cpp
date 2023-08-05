class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return count_if(hours.cbegin(), hours.cend(), [&](const int &x) {
            return x >= target;
        });
    }
};

int main() {


  return 0;
}
