template <typename E>
class circularlyLinkedList;

template <typename E>
class node {
    private:
        E data;
        node<E>* next;
        friend class circularlyLinkedList<E>;
};

template <typename E>
class circularlyLinkedList
{
    private:
        node<E>* head;
        node<E>* tail;
        int n;
    public:
        circularlyLinkedList(): head(NULL), tail(NULL), n(0) {}
        ~circularlyLinkedList() 
        {
            while(!empty()) 
                removeFront();
        }
        bool empty() const
        {
            return (head == NULL && tail == NULL);
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
            tail->next = head;
            n++;
        }
        void removeFront() 
        {
            if(head == NULL)
                throw std::out_of_range("illegal index");
            node<E>* old = head;
            if(head == tail) 
            {
                head = NULL;
                tail = NULL;
            }
            else 
            {
                head = old->next;
                tail->next = head;
            }
            delete old;
            n--;
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
            tail->next = head;
            n++;

        }
        void removeBack()
        {
            if(head == NULL)
                throw std::out_of_range("illegal index");
            node<E>* x = head;
            if(head == tail)
            {
                node<E>* old = head;
                head = NULL;
                delete old;
                tail = NULL;
                n--;
                return;
            }
            while(x->next != tail)
            {
                x = x->next;
            }
            node<E>* old = tail;
            tail = x;
            tail->next = head;
            n--;
            delete old;
        }
        E& at(int x)
        {
            if(x<0 || x>=size())
                throw std::out_of_range("illegal index");
            node<E>* p = head;
            for(int i=0; i<x; i++)
                p = p->next;
            return p->data;
        }
        void insert(int x, const E& e)
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
            {
                tail = v;
                tail->next = head;
            }
            n++;
        }
        node<E>* find(const E& e){
            if(empty())
                throw std::out_of_range("element not found");
            node<E>* p = head;
            do
            {
                if(p->data == e)
                {
                    return p;
                }
                p = p->next;
            }
            while(p != head);
            throw std::out_of_range("element not found");
        }
};
