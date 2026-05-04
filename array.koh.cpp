#include <iostream>
using namespace std;

#define MAX 100

struct Order {
    string customerName;
    string orderName;
    int priority;
};

struct Queue {
    Order arr[MAX];
    int front = 0;
    int rear = -1;

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(Order o) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        arr[++rear] = o;
    }

    Order dequeue() {
        return arr[front++];
    }
};

struct Stack {
    Order arr[MAX];
    int top = -1;

    bool isEmpty() {
        return top == -1;
    }

    void push(Order o) {
        if (top == MAX - 1) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = o;
    }

    Order pop() {
        return arr[top--];
    }
};

struct PriorityQueue {
    Order arr[MAX];
    int size = 0;

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void enqueue(Order o) {
        if (isFull()) {
            cout << "Priority Queue full!\n";
            return;
        }

        arr[size++] = o;

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j].priority < arr[j + 1].priority) {
                    Order temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    Order dequeue() {
        return arr[--size]; // highest priority at front after sorting
    }

    Order peek() {
        return arr[0];
    }
};

Queue normalQueue;
PriorityQueue priorityQueueOrders;
Stack undoStack;

bool isDuplicate(string name, string order) {
    // Check normal queue
    for (int i = normalQueue.front; i <= normalQueue.rear; i++) {
        if (normalQueue.arr[i].customerName == name &&
            normalQueue.arr[i].orderName == order)
            return true;
    }

    // Check priority queue
    for (int i = 0; i < priorityQueueOrders.size; i++) {
        if (priorityQueueOrders.arr[i].customerName == name &&
            priorityQueueOrders.arr[i].orderName == order)
            return true;
    }

    return false;
}

void addOrder() {
    Order o;

    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, o.customerName);

    cout << "Enter Order: ";
    getline(cin, o.orderName);

    cout << "Enter Priority (1 = Normal, 2 = Priority): ";
    cin >> o.priority;

    if (isDuplicate(o.customerName, o.orderName)) {
        cout << "Duplicate order detected! Not added.\n";
        return;
    }

    if (o.priority == 2) {
        priorityQueueOrders.enqueue(o);
    } else {
        normalQueue.enqueue(o);
    }

    cout << "Order added successfully!\n";
}

void processOrder() {
    if (!priorityQueueOrders.isEmpty()) {
        Order o = priorityQueueOrders.dequeue();
        undoStack.push(o);

        cout << "Processing PRIORITY order of "
             << o.customerName << " (" << o.orderName << ")\n";
    }
    else if (!normalQueue.isEmpty()) {
        Order o = normalQueue.dequeue();
        undoStack.push(o);

        cout << "Processing NORMAL order of "
             << o.customerName << " (" << o.orderName << ")\n";
    }
    else {
        cout << "No orders available.\n";
    }
}

// ================= UNDO =================
void undoOrder() {
    if (undoStack.isEmpty()) {
        cout << "Nothing to undo.\n";
        return;
    }

    Order o = undoStack.pop();

    if (o.priority == 2)
        priorityQueueOrders.enqueue(o);
    else
        normalQueue.enqueue(o);

    cout << "Undo successful!\n";
}

// ================= DISPLAY =================
void displayOrders() {
    cout << "\n--- PRIORITY ORDERS ---\n";
    for (int i = 0; i < priorityQueueOrders.size; i++) {
        cout << priorityQueueOrders.arr[i].customerName
             << " - " << priorityQueueOrders.arr[i].orderName << endl;
    }

    cout << "\n--- NORMAL ORDERS ---\n";
    for (int i = normalQueue.front; i <= normalQueue.rear; i++) {
        cout << normalQueue.arr[i].customerName
             << " - " << normalQueue.arr[i].orderName << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n==== QUICKSERVE SYSTEM ====\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Undo\n";
        cout << "4. Display Orders\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addOrder(); break;
            case 2: processOrder(); break;
            case 3: undoOrder(); break;
            case 4: displayOrders(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
