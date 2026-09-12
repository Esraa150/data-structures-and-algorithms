template <typename E>
class ArrayQueue {
    private:
        int f;
        int r;
        int capacity;
        int n;
        E* data;
    public:
        ArrayQueue(): data(new E[100]), capacity(100), f(0), r(0), n(0) {}
        ~ArrayQueue()
        {
            delete[] data;
        }
        int size() 
        {
            return n;
        }
        bool empty()
        {
            return (n==0);
        }
        E& front()
        {
            if(empty()) throw std::out_of_range("queue empty");
            return data[f];
        }
        E& back()
        {
            if(empty()) throw std::out_of_range("queue empty");
            return data[(r-1+capacity)%capacity];
        }
        void dequeue()
        {
            if(empty()) throw std::out_of_range("queue empty");
            f = (f+1)%capacity;
            n--;
        }
        void enqueue(const E& e)
        {
            if(size() == capacity) throw std::out_of_range("queue full");
            data[r] = e;
            r = (r+1)%capacity;
            n++;
        }
};