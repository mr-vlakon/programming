class Foo {
public:
    Foo() {
    }
    void first(function<void()> printFirst) {
        if (tmp == 0) {
            m.lock();
            tmp = 1;
            printFirst();
            m.unlock();
        } else {
            first(printFirst);
        }
        
    }

    void second(function<void()> printSecond) {
            if(tmp == 1) {
                m.lock();
                tmp = 2;
                printSecond();
                m.unlock();
            } else {
                second(printSecond);
            }            
    }

    void third(function<void()> printThird) {
            if(tmp == 2) {
                m.lock();
                tmp = 0;
                printThird();
                m.unlock();
            } else {
                third(printThird);
            }
    }
private:
    int tmp = 0;
    std::mutex m;
};

  

int main() {
  
  
  
  return 0;  
}
