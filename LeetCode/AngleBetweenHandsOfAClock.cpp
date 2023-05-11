class Solution {
public:
    double angleClock(int hour, int minutes) {
        double d = minutes / 60.0;
        hour %= 12;
        double h = hour;
        h += d;
        double minV = minutes;
        minV /= 5.0;
        double ans = (abs(h - minV) / 12.0) * 360.0;
        if (ans > 180.0 - 0.01) return 360.0 - ans;
        return ans;
    }
};
/*
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double d = minutes / 60.0;
        hour %= 12;
        double h = hour;
        h += d;
        double minV = minutes;
        minV /= 5.0;
        double diff = abs(h - (minV));
        double x = abs(h - static_cast<double>(minutes));
        double ans = (diff / 12.0) * 360.0;
        if (ans > 180.0 - 0.01) return 360.0 - ans;
        return ans;
    }
};
*/
int main() {
  
  
    
  return 0;  
}
