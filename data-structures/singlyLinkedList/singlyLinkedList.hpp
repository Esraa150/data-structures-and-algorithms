template <typename E>
class singlyLinkedList;

template <typename E>
class node {
    private:
        E data;
        node<E>* next;
        friend class singlyLinkedList<E>;
};

template <typename E>
class singlyLinkedList
{
    private:
        node<E>* head;
        node<E>* tail;
        int n;
    public:
        singlyLinkedList(): head(NULL), tail(NULL), n(0) {}
        ~singlyLinkedList() 
        {
            while(!empty()) 
                removeFront();
        }
        bool empty() const
        {
            return head == NULL;
        }
        int size() const 
        {
            return n;
        }
        void clear()
        {
            while(!empty())
                removeFront();
        }
        E& front() 
        {
            if(head == NULL)
                throw std::out_of_range("illegal index");
            return head->data;
        }
        E& back()
        {
            if(empty())
                throw std::out_of_range("illegal index");
            return tail->data;
        }
        void addFront(const E& e)
        {
            node<E>* v = new node<E>;
            v->data = e;
            v->next = head;
            head = v;
            if(tail == NULL)
                tail = v;
            n++;
        }
        void removeFront() 
        {
            if(head == NULL)
                throw std::out_of_range("illegal index");
            node<E>* old = head;
            head = old->next;
            delete old;
            n--;
            if(size()==0)
                tail = NULL;
        }
        void addBack(const E& e)
        {
            node<E>* v = new node<E>;
            v->data = e;
            v->next = NULL;
            if(empty())
            {
                head = v;
                tail = v;
            }
            else
            {
                tail->next = v;
                tail = v;
            }
            n++;

        }
        void removeBack()
        {
            if(head == NULL)
                throw std::out_of_range("illegal index");
            node<E>* x = head;
            if(head->next == NULL)
            {
                node<E>* old = head;
                head = NULL;
                delete old;
                tail = NULL;
                n--;
                return;
            }
            node<E>* y = head->next;
                while(y->next != NULL)
                {
                    y = y->next;
                    x = x->next;
                }
                x->next = NULL;
                tail = x;
                n--;
                delete y;
        }
        E& at(int x)
        {
            if(x<0)
                throw std::out_of_range("illegal index");
            int c = 0;
            node<E>* p = head;
            while(p != NULL)
            {
                if(c == x)
                    return p->data;
                c++;
                p = p->next;
            }
            throw std::out_of_range("illegal index");
        }
        void insert(int x, E& e)
        {
            if(x<0 || x>size())
                throw std::out_of_range("illegal index");
            if(x==0)
            {
                addFront(e);
                return;
            }
            node<E>* p = head;
            for(int i=0; i<x-1; i++)
            {
                p = p->next;
            }
            node<E>* v = new node<E>;
            v->data = e;
            v->next = p->next;
            p->next = v;
            if(x == n)
                tail = v;
            n++;
        }
        node<E>* find(const E& e){
            node<E>* p = head;
            while(p != NULL)
            {
                if(p->data == e)
                {
                    return p;
                }
                p = p->next;
            }
            throw std::out_of_range("element not found");
        }
};
