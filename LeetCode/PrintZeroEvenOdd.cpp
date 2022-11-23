class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }
    
    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        if (n == 1) {
            std::unique_lock<std::mutex> lck(m);
            while (tmp != 0) cv.wait(lck);
            tmp = 1;
            printNumber(0);
            cv.notify_all();
        } else {
            int nn = n % 2 == 0 ? n : n - 1;
            int ch = n % 2 == 1 ? n : n - 1;
            while (ev <= n) {
                std::unique_lock<std::mutex> lck(m);
                while (tmp != 0) cv.wait(lck);
                if (prev == 1) {
                    tmp = 1;
                    prev = 2;
                } else {
                    tmp = 2;
                    prev = 1;
                }
                if (!(od > ch && ev > nn))
                    printNumber(0);
                cv.notify_all();
            } 
        }
    }

    void even(function<void(int)> printNumber) {
            int nn = (n % 2 == 0) ? n : n - 1;
            while (ev <= nn) {
                std::unique_lock<std::mutex> lck(m);
                while (tmp != 2) cv.wait(lck);
                tmp = 0;
                printNumber(ev);
                ev += 2;
                cv.notify_all();
            }
    }

    void odd(function<void(int)> printNumber) {
            int nn = (n % 2 == 1) ? n : n - 1;
            while (od <= nn) {
                std::unique_lock<std::mutex> lck(m);
                while (tmp != 1) cv.wait(lck);
                tmp = 0;
                printNumber(od);
                od += 2;
                cv.notify_all();
            } 
    }
private:
    mutex m;
    int ev = 2;
    int od = 1; 
    std::condition_variable cv;
    int prev = 1;
    int tmp = 0;
};

int main() {
  
  
  
  return 0;  
}
