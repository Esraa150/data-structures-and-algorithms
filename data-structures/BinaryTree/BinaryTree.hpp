template <typename E>
class BinaryTree;

template <typename E>
class node {
    private:
        E data;
        node<E>* left;
        node<E>* right;
        node<E>* par;
        friend class BinaryTree<E>;
};

template <typename E>
class BinaryTree {
    private:
        node<E>* Root;
        int n;
    public:
        BinaryTree(): Root(NULL), n(0) {}
        ~BinaryTree() 
        {
            clear(Root);
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
        node<E>* leftChild(node<E>* e)
        {
            return e->left;
        }
        node<E>* rightChild(node<E>* e)
        {
            return e->right;
        }
        node<E>* parent(node<E>* e)
        {
            return e->par;
        }
        E& element(node<E>* p)
        {
            return p->data;
        }
        void addRoot(const E& e)
        {
            if(Root != NULL) 
                throw std::out_of_range("no need to add a root");
            Root = new node<E>;
            Root->data = e;
            Root->left = NULL;
            Root->right = NULL;
            Root->par = NULL;
            n++;
        }
        void addLeft(node<E>* p, const E& e)
        {
            if(p->left != NULL)
                throw std::out_of_range("p already has a left child");
            node<E>* x = new node<E>;
            x->data = e;
            x->left = NULL;
            x->right = NULL;
            x->par = p;
            p->left = x;
            n++;
        }
        void addRight(node<E>* p, const E& e)
        {
            if(p->right != NULL)
                throw std::out_of_range("p already has a right child");
            node<E>* x = new node<E>;
            x->data = e;
            x->left = NULL;
            x->right = NULL;
            x->par = p;
            p->right = x;
            n++;
        }
        void removeExternal(node<E>* p)
        {
            if(p == Root)
            {
                delete p;
                Root = NULL;
                n--;
                return;
            }
            if(p->right == NULL && p->left == NULL)
            {
                node<E>* x = p->par;
                if(x->left == p)
                {
                    x->left = NULL;
                }
                else if(x->right == p)
                {
                    x->right = NULL;
                }
                delete p;
                n--;
            }
            else   
                throw std::out_of_range("node is not external");
        }
        void clear(node<E>* p)
        {
            if(p==NULL)
                return;
            clear(p->left);
            clear(p->right);
            removeExternal(p);
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