
template <typename Elem>
class ArrayVector {
    private:
        int capacity;
        int n;
        Elem* A;
    public:
        ArrayVector(): capacity(100), n(0), A(new Elem[100]) 
        { 

        }
        ~ArrayVector()
        {
            delete[] A;
        }

        int size() const
        {
            return n;
        }
        bool empty() const
        {
            return (size()==0);
        }
        Elem& operator[](int i)
        {
            return A[i];
        }
        Elem& at(int i) 
        {
            if(i<0 || i>=n)
                throw std::out_of_range("illegal index");
            return A[i];
        }
        Elem& front() 
        {
            if(n==0)
                throw std::out_of_range("illegal index");
            return A[0];
        }
        Elem& back() 
        {
            if(n==0)
                throw std::out_of_range("illegal index");
            return A[n-1];
        }
        void reserve(int N)
        {
            if(capacity>=N) return;
            Elem* B = new Elem[N];
            for(int j=0; j<n; j++)
                B[j] = A[j];
            if(A != NULL) delete[] A;
            A = B;
            capacity = N;
        }
        void push_back(const Elem& e)
        {
            if(n==capacity)
                reserve(2*capacity);
            A[n] = e;
            n++;
        }
        void pop_back() 
        {
            if(n==0)
                throw std::out_of_range("illegal index");
            n--;
        }
        void clear() 
        {
            n=0;
        }
        void insert(int i, const Elem& e)
        {
            if(i<0 || i>n)
                throw std::out_of_range("illegal index");
            if(n>=capacity)
                reserve(2*capacity);
            for(int j=n-1; j>=i; j--)
                A[j+1] = A[j];
            A[i] = e;
            n++;
        }
        void erase(int i) 
        {
            if(i<0 || i>=n)
                throw std::out_of_range("illegal index");
            for(int j=i+1; j<n; j++)
                A[j-1] = A[j];
            n--;
        }
};
