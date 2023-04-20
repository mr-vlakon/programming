class Solution {
public:
    void binary(const long long &num, long long &left, long long &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        tmp = 0;
        middle_ = ((mid % 2) == 0) ? mid : (mid - 1);
        end = middle_/2;
        firstSum = (middle_ - end + 1)*(middle_ + end) - end;
        s = (end*(end + 1)) / 2;
        tmp = (end + 1)*firstSum - s*(middle_ + 1);
        tmp *= 2;
        tmp -= end*(end + 1);
        if (tmp < num) {
            left = mid + 1;
            binary(num, left, right);
        } else {
            answer = min(mid, answer);
            right = mid - 1;
            binary(num, left, right);
        }
    }
    long long minimumPerimeter(long long neededApples) {
        tmp = 0;
        long long left = 2;
        long long right = 503968;
        binary(neededApples, left, right);
        return answer * 4;
    }
private:
    long long s = 0;
    long long firstSum = 0;
    long long middle_ = 0;
    long long end = 0;
    long long mid = 0;
    long long answer = 1000000000000000;
    long long tmp = 0; 
};
