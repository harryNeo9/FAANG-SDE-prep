/*
Given Pointer/Reference to the head of the linked list, the task is 
to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should 
go in the first list while splitting.

N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5

N = 3
value[]  = {9,15,0}
Output: 0 9 15

N = 10
6 8 3 5 7 2 9 1 4 2

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


    Node* mergeSort(Node* head) {
        // your code here

    return head;
    }

    Node *middleInList(Node *head) //working fine only for even no of nodes.
    {
        Node *slow = nullptr, *fast = nullptr;
        slow = head;
        fast = head->next->next;
        while (fast != nullptr)
        {
            slow = slow->next;
            if(fast->next != nullptr)
                fast = fast->next->next;
        }
        return slow;
    }

     void printList(Node *head)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << "->" << tmp->data;
            tmp = tmp->next;
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
        cout << "Iterative print: ";printList(head);
        cout<<endl;
        cout<<"Middle in Linked List: \n";
        cout<<middleInList(head)->data<<endl;
    }