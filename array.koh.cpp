#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Order{
  string customerName;
  string orderName;
  int priority;

  public:
  Order (string cn, string on, int p){
    customerName = cn;
    orderName = on;
    priority = p;
  }
  string getCustomerName(){return customerName};
  string getOrderName(){return orderName};
  int getPriority(){return priority};
  
  void display(){
    cout <<customerName << "-" << orderName  << endl;
  }

    bool operator<(const Order& other) const {
        return priority < other.priority;
    }
};
struct Compare {
  bool operator()(Order a, Order b){
    return a.getPriority() < b.getPriority();
  }
};

queue<Order> normalQueue;
priority_queue<Order> priorityQueueOrders;
stack<Order> undoStack;

void addOrder() {
    Order o;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, o.customerName);

    cout << "Enter Order: ";
    getline(cin, o.orderName);

    cout << "Enter Urgency (1 = Normal, 2 = Priority): ";
    cin >> o.priority;

    if (o.priority == 2) {
        priorityQueueOrders.push(o);
    } else {
        normalQueue.push(o);
    }

    cout << "Order added successfully!\n";
}

void processOrder() {
    if (!priorityQueueOrders.empty()) {
        Order o = priorityQueueOrders.top();
        priorityQueueOrders.pop();
        undoStack.push(o);

        cout << "Processing PRIORITY order of " << o.customerName
             << " (" << o.orderName << ")\n";
    }
    else if (!normalQueue.empty()) {
        Order o = normalQueue.front();
        normalQueue.pop();
        undoStack.push(o);

        cout << "Processing NORMAL order of " << o.customerName
             << " (" << o.orderName << ")\n";
    }
    else {
        cout << "No orders to process.\n";
    }
}
void undoOrder() {
    if (undoStack.empty()) {
        cout << "Nothing to undo.\n";
        return;
    }

    Order o = undoStack.top();
    undoStack.pop();

    if (o.priority == 2) {
        priorityQueueOrders.push(o);
    } else {
        normalQueue.push(o);
    }

    cout << "Undo successful! Order returned.\n";
}

void displayOrders() {
    cout << "\n--- PRIORITY ORDERS ---\n";
    priority_queue<Order> tempPQ = priorityQueueOrders;

    while (!tempPQ.empty()) {
        Order o = tempPQ.top();
        tempPQ.pop();
        cout << o.customerName << " - " << o.orderName << endl;
    }

    cout << "\n--- NORMAL ORDERS ---\n";
    queue<Order> tempQ = normalQueue;

    while (!tempQ.empty()) {
        Order o = tempQ.front();
        tempQ.pop();
        cout << o.customerName << " - " << o.orderName << endl;
    }
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n==== FAST FOOD ORDER SYSTEM ====\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Undo Last Order\n";
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
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
