
    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(nullptr) {}
    } *head = nullptr, *tmp;

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int main()
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

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
                tmp = newnode;
            }
        }
        tmp = head;
        cout << "List:";
        while (tmp)
        {
            cout << "->" << tmp->data;
            tmp = tmp->next;
        }
        cout << endl;

        tmp = head;
        while (tmp != nullptr && tmp->next != nullptr)
        {
            swap(&tmp->data, &tmp->next->data);
            tmp = tmp->next->next;
        }

        tmp = head;
        cout << "After Swapping\n";
        cout << "List:";
        while (tmp)
        {
            cout << "->" << tmp->data;
            tmp = tmp->next;
        }
        cout << endl;

        return 0;
    }

    /*
        Display the pairwise swapped Linked List.
        TEST CASE 1
        INPUT
        5
        1 2 3 4 5
        OUTPUT
        List : ->2->1->4->3->5
        TEST CASE 2
        INPUT
        8
        6 8 3 5 7 2 9 1
        OUTPUT
        List : ->8->6->5->3->2->7->1->9

    */