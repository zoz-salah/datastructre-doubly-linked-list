#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(NULL), prev(NULL) { }

    void displayNode() 
    { 
        cout << data << " " << endl; 
    }
};

// Doubly Linked List class
class LinkedList
{
private:
    Node* head;
    Node* tail;   // <<=== NEW tail pointer

public:
    LinkedList() : head(NULL), tail(NULL) { }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertNode(int val)
    {
        Node* newnode = new Node(val);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode; // <<=== update tail
        }
        else
        {
            tail->next = newnode; // use tail directly
            newnode->prev = tail;
            tail = newnode;       // move tail
        }
    }

    void insertBeg(int val)
    {
        Node* newnode = new Node(val);
        newnode->next = head;

        if (head != NULL)
        {
            head->prev = newnode;
        }
        else
        {
            tail = newnode; // list was empty → both head & tail
        }

        head = newnode;
    }

    void deleteBeg()
    {
        if (head == NULL) 
        {
            cout << "no elements" << endl;
            return;
        }

        Node* firstnode = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL; // became empty
        }

        delete firstnode;
    }

    void deleteEnd()
    {
        if (head == NULL) 
        {
            cout << "no elements" << endl;
            return;
        }

        Node* ptr = tail; // use tail directly

        if (ptr->prev != NULL)
        {
            tail = ptr->prev;
            tail->next = NULL;
        }
        else
        {
            head = tail = NULL; // one element only
        }

        delete ptr;
    }

   

    bool searchNode(int key)
    {
        Node* current = head;
        while (current != NULL) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }

    void display()
    {
        if (head == NULL) {
            cout << "no elements" << endl;
            return;
        }
        Node* current = head;
        while (current != NULL) {
            current->displayNode();
            current = current->next;
        }
    }

    void traverseBackward()
    {
        Node* ptr = tail;   // <<=== Start directly from tail
        while (ptr != NULL) {
            cout << ptr->data << endl;
            ptr = ptr->prev;
        }
    }

};



int main()
{
    LinkedList list1;
    list1.insertNode(10);
    list1.insertNode(20);
    list1.insertNode(30);

    list1.traverseBackward();

    return 0;
}
