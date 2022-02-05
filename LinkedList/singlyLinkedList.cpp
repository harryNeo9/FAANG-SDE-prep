    /*
            Program to create a Singly Linked List DS and perfom the following operations:
            1. Print List - Iterative & Recursive - O(n)
            2. Count Nodes - Iterative & Recursive 
            3. Sum Nodes - Recurisve
            4. Max element in Linked List - Recursive
            5. Searching - Iterative & Recursive 
            6. Improved Search with move to head - Iterative
            7. Insert node after a given index
            8. Delete node at a given index and return its data.
            9. Check List is sorted
            -----------------------------
            10. Merge Sort for Linked List
            10. Remove Duplicates from a sorted Linked List


        */
    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(nullptr) {}
    };

    Node *head = nullptr;

    void printList(Node *head)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << "->" << tmp->data;
            tmp = tmp->next;
        }
    }

    void recursivePrintList(Node *p)
    {
        if (p == nullptr)
            return;
        else
        {
            cout << "->" << p->data;
            recursivePrintList(p->next);
        }
    }

    int countNodes(Node *head)
    {
        int count = 0;
        Node *tmp = head;
        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    int recursiveCountNodes(Node *p)
    {
        if (p == nullptr)
            return 0;
        else
            return recursiveCountNodes(p->next) + 1;
    }

    int recursiveSumNodes(Node *p)
    {
        if (p == nullptr)
            return 0;
        else
            return recursiveSumNodes(p->next) + (p->data);
    }

    int recursiveMaxEleList(Node *p)
    {
        int x = 0;
        if (p == nullptr)
            return INT_MIN;
        else
        {
            x = recursiveMaxEleList(p->next);
            return x > p->data ? x : p->data;
        }
    }

    Node *searchList(int key, Node *head)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->data == key)
                return tmp;
            tmp = tmp->next;
        }
        return nullptr;
    }

    Node *recursiveSearchList(int key, Node *p)
    {
        if (p == nullptr)
            return nullptr;
        if (p->data == key)
            return p;
        return recursiveSearchList(key, p->next);
    }

    Node *searchListWithMoveToHead(int key, Node *p){

        Node *q;
        while(p != nullptr){
            if(p->data == key){
                q->next = p->next;
                p->next = head;
                head = p;
                return p;
            }
            q = p;
            p = p->next;
        }
        return nullptr;
    }

    void insertNode(int index, int data)
    {
        if(index > countNodes(head)) return;
    
        Node *newnode = new Node(data);
        if (index == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *tmp = head;
            while (index > 1)
            {
                tmp = tmp->next;
                index--;
            }
            newnode->next = tmp->next;
            tmp->next = newnode;
        }
    }

    int deleteNode(int index)
    {
        if (index > countNodes(head)) return -1;
        int key;
        if (index == 1)
        {
            Node *tmp = head;
            head = head->next;
            tmp->next = nullptr;
            key = tmp->data;
            delete tmp;
            return key;
        }
        else
        {
            Node *p = head, *q = nullptr;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            p->next = nullptr;
            key = p->data;
            delete p;
            return key;
        }
    }

    bool isSortedList(Node *head){
        int x = INT_MIN;
        Node *tmp = head;
        while( tmp != nullptr){
            if(tmp-> data < x) return false;
            x = tmp->data;
            tmp = tmp->next;
        }
        return true;
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
        cout << "\nRecursive print: ";recursivePrintList(head);
        cout<<endl;
        cout << "\n(Iterative)Size of List : " << countNodes(head) << " Nodes\n";
        cout << "(Recursive)Size of List : " << recursiveCountNodes(head) << " Nodes\n";
        cout << "(Recursive)Sum of List : " << recursiveSumNodes(head)<<endl;
        cout << "(Recursive)Max element in List : " << recursiveMaxEleList(head)<<endl;

        cout << "(Iterative)Searching in List for 11 : ";
        if(searchList(11,head) == nullptr) cout<<"Search failure\n";
        else cout<<"Search success\n";
        cout << "(Recursive)Searching in List for 7 : ";
        if(recursiveSearchList(7,head) == nullptr) cout<<"Search failure\n";
        else cout<<"Search success\n";
        cout << "(Iterative)Searching(with move to head) in List for 9 : ";
        if(searchListWithMoveToHead(9,head) == nullptr) cout<<"Search failure\n";
        else cout<<"Search success\n";
        cout << "Iterative print: ";printList(head);
        cout<< "\nInserting 10 at index 7 \n"; insertNode(7,13);
        cout << "Iterative print: ";printList(head);
        cout<<" \nDeleting node at index 9 \n"; 
        cout<<"Node "<<deleteNode(9)<<" has been successfully deleted!\n";
        cout << "Iterative print: ";printList(head);
        cout<<"\nChecking list is sorted!\n"; 
        if(isSortedList(head) == 1) cout<<"Sorted!\n";
        else cout<<"Not sorted!\n";


        
        

        return 0;
    }

/*
----------------------------------------------
Input:
8
6 8 3 5 7 2 9 1
-----------------------------------------------
Output:

Iterative print: ->6->8->3->5->7->2->9->1
Recursive print: ->6->8->3->5->7->2->9->1

(Iterative)Size of List : 8 Nodes
(Recursive)Size of List : 8 Nodes
(Recursive)Sum of List : 41
(Recursive)Max element in List : 9
(Iterative)Searching in List for 11 : Search failure
(Recursive)Searching in List for 7 : Search success
(Iterative)Searching(with move to head) in List for 9 : Search success
Iterative print: ->9->6->8->3->5->7->2->1
Inserting 10 at index 7 
Iterative print: ->9->6->8->3->5->7->2->13->1 
Deleting node at index 9 
Node 1 has been successfully deleted!
Iterative print: ->9->6->8->3->5->7->2->13
Checking list is sorted!
Not sorted!

*/