    // { Driver Code Starts
    // C program to find n'th Node in linked list
    #include <stdio.h>
    #include <stdlib.h>
    #include<iostream>
    using namespace std;

    /* Link list Node */
    struct Node
    {
        int data;
        struct Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(data) , next(nullptr) {}
    };



    class Solution
    {
        public:
        void rearrangeEvenOdd(Node *head)
        {
        if(head == nullptr) return;
        
        Node *oh, *ot, *eh, *et;
        oh = ot = eh = et = nullptr;
        Node *tmp = head;
        bool is_odd = 1;
        
        
        while(tmp){
            if(is_odd){
                if(oh == nullptr){
                        oh = ot = tmp;
                }
                else{
                    ot -> next = tmp;
                    ot = tmp;
                }
                tmp = tmp->next;
                ot->next = nullptr;
            }else{
                    if(eh == nullptr){
                        eh = et = tmp;
                }
                else{
                    et -> next = tmp;
                    et = tmp;
                }
                tmp = tmp->next;
                et->next = nullptr;
            }
            is_odd = !is_odd;
        }
        ot->next= eh;
        }
    };


    // { Driver Code Starts.

    /* Driver program to test above function*/
    int main()
    {
        int T,i,n,l;

        cin>>T;

        while(T--)
        {
            struct Node *head = NULL;
            struct Node *temp = head;
            cin>>n;
            for(i=1; i<=n; i++)
            {
                cin>>l;

                if (head == NULL)
                {   
                    head = temp = new Node(l); 
                    
                }
                else
                {  temp->next = new Node(l);
                temp = temp->next;
                }
            }
            Solution ob;
            ob.rearrangeEvenOdd(head);
            while(head != NULL)
            {
                printf("%d ", head->data);
                head = head->next;
            }
            printf("\n");
        }
        return 0;
    }



    /*
    Input
    1
    4
    1 2 3 4
    */