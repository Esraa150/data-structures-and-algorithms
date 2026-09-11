template <typename E>
class ArrayStack {
    private:
        E* s;
        int capacity;
        int t;
    public:
        ArrayStack(): s(new E[100]), capacity(100), t(-1) {}
        ~ArrayStack()
        {
             delete[] s;
        }
        void reserve(int N)
        {
            if(capacity>=N) return;
            E* B = new E[N];
            for(int j=0; j<=t; j++)
                B[j] = s[j];
            delete[] s;
            s = B;
            capacity = N;
        }
        int size() const
        {
            return t+1;
        }
        bool empty() const
        {
            return (t<0);
        }
        E& top()
        {
            if(empty()) throw std::out_of_range("top of empty stack");
            return s[t];
        }
        void push(const E& e)
        {
            if(size() == capacity)
                reserve(2*capacity);
            t++;
            s[t] = e;
        }
        void pop()
        {
            if(empty()) throw std::out_of_range("pop from empty stack");
            t--;
        }
};
