class FooBar {
private:
    int n;
    int turn = 1;
    std::condition_variable cv;
    mutex m;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lck(m);
        for (int i = 0; i < n; i++) {
            while (turn != 1) cv.wait(lck);
        	turn = 2;
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> lck(m);
        for (int i = 0; i < n; i++) {
            while (turn != 2) cv.wait(lck);
            turn = 1;
            // printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            cv.notify_one();
        }
    }
};

int main() {
  
  
  
  return 0;  
}
