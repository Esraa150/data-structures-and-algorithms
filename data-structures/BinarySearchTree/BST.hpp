template <typename E>
class BST;

template <typename E>
class node {
    private:
        E data;
        node<E>* left;
        node<E>* right;
        friend class BST<E>;
};

template <typename E>
class BST {
    private:
        node<E>* Root;
        int n;
        void clear(node<E>* r)
        {
            if(r == NULL)
                return;
            clear(r->left);
            clear(r->right);
            delete r;
            n--;
        }
    public:
        BST(): Root(NULL), n(0) {}
        ~BST() 
        {
            clear();
        }
        void clear()
        {
            clear(Root);
            Root = NULL;
        }
        bool empty()
        {
            return (n==0);
        }
        int size()
        {
            return n;
        }
        node<E>* root()
        {
            return Root;
        }
        void insert(const E& e)
        {
            if(Root == NULL)
            {
                Root = new node<E>;
                Root->data = e;
                Root->left = NULL;
                Root->right = NULL;
                n++;
                return;
            }
            node<E>* curr = Root;
            while(true)
            {
                if(curr->data == e)
                    return;
                else if(curr->data > e)
                {
                    if(curr->left == NULL)
                    {
                        node<E>* x = new node<E>;
                        x->data = e;
                        curr->left = x;
                        x->left = NULL;
                        x->right = NULL;
                        n++;
                        return;
                    }
                    curr = curr->left;
                }
                else
                {
                    if(curr->right == NULL)
                    {
                        node<E>* x = new node<E>;
                        x->data = e;
                        curr->right = x;
                        x->left = NULL;
                        x->right = NULL;
                        n++;
                        return;
                    }
                    curr = curr->right;   
                }
            }
        }
        bool search(const E& e)
        {
            if(Root == NULL)
                return false;
            node<E>* curr = Root;
            while(curr != NULL)
            {
                if(curr->data == e)
                    return true;
                else if(curr->data > e)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;   
                }
            }
            return false;
        }
        E& findMin()
        {
            if(Root == NULL) 
                throw std::out_of_range("empty tree!");
            node<E>* x = Root;
            while(x->left != NULL)
                x = x->left;
            return x->data;
        }
        E& findMax()
        {
            if(Root == NULL) 
                throw std::out_of_range("empty tree!");
            node<E>* x = Root;
            while(x->right != NULL)
                x = x->right;
            return x->data;
        }
        void remove(const E& e)
        {
            node<E>* curr = Root;
            node<E>* parent = NULL;
            while(curr != NULL && curr->data != e)
            {

                parent = curr;
                if(curr->data > e)
                    curr = curr->left;
                else 
                    curr = curr->right;
            }
            if(curr == NULL)
                return;
            if(curr->right != NULL && curr->left != NULL)
            {
                node<E>* succParent = curr;
                node<E>* succ = curr->right;
                while(succ->left != NULL)
                {
                    succParent = succ;
                    succ = succ->left;
                }
                curr->data = succ->data;
                curr = succ;
                parent = succParent;
            }
            node<E>* child;
            if(curr->left != NULL)
                child = curr->left;
            else
                child = curr->right;
            
            if(parent == NULL)
                Root = child;
            else if(parent->left == curr)
                parent->left = child;
            else
                parent->right = child;
            delete curr;
            n--;
        }

        template <typename Func>
        void preOrder(node<E>* n, Func visit)
        {
            if(n==NULL)
                return;
            visit(n->data);
            preOrder(n->left, visit);
            preOrder(n->right, visit);
        }
        template <typename Func>
        void postOrder(node<E>* n, Func visit)
        {
            if(n==NULL)
                return;
            postOrder(n->left, visit);
            postOrder(n->right, visit);
            visit(n->data);
        }
        template <typename Func>
        void inOrder(node<E>* n, Func visit)
        {
            if(n==NULL)
                return;
            inOrder(n->left, visit);
            visit(n->data);
            inOrder(n->right, visit);
        }
};