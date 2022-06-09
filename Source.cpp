#include <iostream>

using namespace std;

class BinTree
{
private:
    struct Node
    {
        char data;
        Node* leftchild;
        Node* rightchild;

        Node(char data)
        {
            this->data = data;
            leftchild = nullptr;
            rightchild = nullptr;
        }
    };

    Node* head;

    void Label(Node* n)
    {
        cout << n->data << " ";
    }

    void PreOrder(Node* root)
    {
        if (root != nullptr)
        {
            Label(root);
            if (root->leftchild != nullptr)
                PreOrder(root->leftchild);
            if (root->rightchild != nullptr)
                PreOrder(root->rightchild);
        }
    }

    void InOrder(Node* current)
    {
        if (current != nullptr)
        {
            if (current->leftchild != nullptr)
                InOrder(current->leftchild);
            Label(current);
            if (current->rightchild != nullptr)
                InOrder(current->rightchild);
        }
    }

    void PostOrder(Node* current)
    {
        if (current != nullptr)
        {
            if (current->leftchild != nullptr)
                PostOrder(current->leftchild);
            if (current->rightchild != nullptr)
                PostOrder(current->rightchild);
            Label(current);
        }
    }
public:
    BinTree()
    {
        head = nullptr;
    }

    void input()
    {
        head = new Node('*');
        Node* cur = head;
        cur->leftchild = new Node('+');
        cur->rightchild = new Node('/');
        cur = cur->leftchild;
        cur->leftchild = new Node('a');
        cur->rightchild = new Node('b');
        cur = head->rightchild;
        cur->leftchild = new Node('+');
        cur->rightchild = new Node('-');
        Node* cur2 = cur->rightchild;
        cur = cur->leftchild;
        cur->leftchild = new Node('a');
        cur->rightchild = new Node('c');
        cur2->leftchild = new Node('b');
        cur2->rightchild = new Node('c');
    }

    void PreOrder()
    {
        PreOrder(head);
        cout << endl;
    }

    void InOrder()
    {
        InOrder(head);
        cout << endl;
    }

    void PostOrder()
    {
        PostOrder(head);
        cout << endl;
    }
};

int main()
{
    BinTree bt;

    bt.input();

    cout << "PreOrder - ";
    bt.PreOrder();

    cout << "InOrder - ";
    bt.InOrder();

    cout << "PostOrder - ";
    bt.PostOrder();

    return 0;
}
