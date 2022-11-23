class H2O {
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lck(m);
        while (tmp != 0) cv.wait(lck);
        ++cnt;
        releaseHydrogen();
        if (cnt >= 2) {
            cnt = 0;
            tmp = 1;
            cv.notify_all();
        }
    } 

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lck(m);
        while (tmp != 1) cv.wait(lck);
        cnt = 0;
        tmp = 0;
        releaseOxygen();
        cv.notify_all();
    }
private:
    int cnt = 0;
    int tmp = 0;
    std::condition_variable cv;
    mutex m;
};

int main() {
  
  
  
  
  return 0;  
}
