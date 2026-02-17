#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // If head node needs to be deleted
        if (temp->data == val) {
            head = temp->next;
            if (head != NULL)
                head->prev = NULL;

            delete temp;
            return;
        }

        // Search for the value
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found\n";
            return;
        }

        // Adjust links
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    // Display list
    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }

        cout << "DLL: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    dll.display();

    dll.deleteByValue(20);
    dll.display();

    dll.deleteByValue(10);
    dll.display();

    return 0;
}
