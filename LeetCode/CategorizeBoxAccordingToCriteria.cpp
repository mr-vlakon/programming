class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool statusBulky = false;
        long long length_ = length;
        long long width_ = width;
        long long height_ = height;
        
        if (length >= 10000 || width >= 10000 || height >= 10000) {
            statusBulky = true;
        }
        if ((length_ * width_ * height_) >= 1000000000) {
            statusBulky = true;
        }
        bool statusHeavy = false;
        if (mass >= 100) {
            statusHeavy = true;
        }
        
        if (statusBulky && statusHeavy) {
            return "Both";
        }
        if ((statusBulky == false) && (statusHeavy == false))
            return "Neither";
        if (statusBulky) {
            return "Bulky";
        }
        if (statusHeavy) {
            return "Heavy";
        }
        return "";
    }
};

int main() {
  
  
  
  
  return 0;  
}
