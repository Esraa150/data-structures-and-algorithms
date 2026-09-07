template <typename E>
class doublyLinkedList;

template <typename E>
class node {
    private:
        E data;
        node<E>* next;
        node<E>* prev;
        friend class doublyLinkedList<E>;
};

template <typename E>
class doublyLinkedList
{
    private:
        node<E>* head;
        node<E>* tail;
        int n;
    public:
        doublyLinkedList(): head(NULL), tail(NULL), n(0) {}
        ~doublyLinkedList() 
        {
            while(!empty()) 
                removeFront();
        }
        bool empty() const
        {
            return n==0;
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
            v->prev = NULL;
            if(head != NULL)
                head->prev = v;
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
            if(head != NULL)
                head->prev = NULL;
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
                v->prev = tail;
                tail->next = v;
                tail = v;
            }
            n++;

        }
        void removeBack()
        {
            if(tail == NULL)
                throw std::out_of_range("illegal index");
            node<E>* old = tail;
            tail = old->prev;
            if(tail != NULL)
                tail->next = NULL;
            delete old;
            n--;
            if(size()==0)
                tail = NULL;
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
            else if(x==n)
            {
                addBack(e);
                return;
            }
            node<E>* p = head;
            for(int i=0; i<x-1; i++)
            {
                p = p->next;
            }
            node<E>* v = new node<E>;
            v->data = e;
            node<E>* q = p->next;                           
            p->next = v;
            q->prev = v;
            v->next = q;
            v->prev = p;
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
