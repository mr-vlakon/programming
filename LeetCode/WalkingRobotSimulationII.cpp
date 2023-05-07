class Robot {
public:
    Robot(int width, int height) : h(height), w(width) {
        size = 2*(width - 1) + 2*(height - 1);
    }
    
    void step(int num) {
        n = (num) % (size);
        if (n == 0) {
            if (direction == 0 && posC == 0 && posR == 0) direction = 3;
            else if (direction == 1 && posC == (w - 1) && posR == 0) direction = 0;
            else if (direction == 2 && posC == (w - 1) && posR == (h - 1)) direction = 1;
            else if (direction == 3 && posC == 0 && posR == (h - 1)) direction = 2;
        }
        while (n) {
            if (direction == 0 && posC < (w - 1)) {
                ++posC;
                --n;
            } else if (direction == 0) {
                direction = 1;
            } else if (direction == 1 && posR < (h - 1)) {
                ++posR;
                --n;
            } else if (direction == 1) {
                direction = 2;
            } else if (direction == 2 && posC > 0) {
                --posC;
                --n;
            } else if (direction == 2) {
                direction = 3;
            } else if (direction == 3 && posR > 0) {
                --posR;
                --n;
            } else if (direction == 3) {
                direction = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {posC, posR};
    }
    
    string getDir() {
        if (direction == 0) {
            return "East";
        } else if (direction == 1) {
            return "North";
        } else if (direction == 2) {
            return "West";
        } else if (direction == 3) {
            return "South";
        }
        return "";
    }
private:
    int posR = 0;
    int posC = 0;
    int direction = 0;
    int h = 0;
    int w = 0;
    int size = 0;
    int n = 0;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
