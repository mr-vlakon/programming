class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                m.lock();
                cnt = 1;
        	// printFoo() outputs "foo". Do not change or remove this line.
        	    printFoo();
                m.unlock();
            } else {
                --i;
            }
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            if (cnt == 1) {
                m.lock();
                cnt = 0;
        	// printBar() outputs "bar". Do not change or remove this line.
        	    printBar();
                m.unlock(); 
            } else {
                --i;
            }
        }
    }
private:
    int cnt = 0;
    mutex m;
};

int main() {
  
  
  
  return 0;  
}
