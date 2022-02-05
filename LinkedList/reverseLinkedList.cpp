/*


*/  
    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(nullptr) {}
    }*head = nullptr;


     void printList(Node *head)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << "->" << tmp->data;
            tmp = tmp->next;
        }
    }

    void reverseList()  // 3 sliding pointer technique
    {
        Node *p = head, *q = nullptr, *r = nullptr;
        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
    }

    void recursiveReverseLise(Node *p, Node *q)
    {
        if (p != nullptr)
        {
            recursiveReverseLise(p, p->next);
            p->next = q;
        }
        else
        {
            head = q;
        }
    }

    int main()
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        Node *tmp;

        int n;
        cin >> n;
        int value;
        while (n--)
        {
            cin >> value;
            Node *newnode = new Node(value);
            if (head == nullptr)
            {
                head = newnode;
                tmp = newnode;
            }
            else
            {
                tmp->next = newnode;
                tmp = tmp->next;
            }
        }
        cout << "Linked List: ";printList(head);
        cout<<endl;
        reverseList();
        cout << "(Iterative) Reversed Linked List: ";printList(head);
        cout<<endl;
        cout << "(Recursive) Reversed Linked List: ";printList(head);
        cout<<endl;
    }