class Foo {
public:
    Foo() {
    }
    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lck(m);
        while (turn != 1) cv.wait(lck);
        turn = 2;
        printFirst();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lck(m);
        while (turn != 2) cv.wait(lck);
        turn = 3;
        printSecond();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck(m);
        while (turn != 3) cv.wait(lck);
        printThird();
    }
private:
    int turn = 1;
    std::condition_variable cv;
    mutex m;
};

  

int main() {
  
  
  
  return 0;  
}
