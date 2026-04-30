#include <iostream>
#include <stack>
#include <queue>
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

};
struct Compare {
  bool operator()(Order a, Order b){
    return a.getPriority() < b.getPriority();
  }
};

int main(){

  return 0;
}
