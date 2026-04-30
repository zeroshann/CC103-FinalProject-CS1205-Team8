#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Order{
  string customerName;
  string orderName;
  int priority;

  public:
  order (string n, string d, int p){
    name = n;
    details = d;
    priority = p;
  }
  # hello po!
cout << "akin ka na lang <<endl;
*\ eto  dhiq
  string getName(){return name};
  string getDetails(){return details};
  int getPriority(){return priority};
  
  void display(){
    cout <<name << "-" << details << endl;
  }
  #di ko na negegets ang github AHAAHA, parang nadami ang mga branch
  //  nalilito na ako sa github HAHHAH lala

};
struct Compare {
  bool operator()(order a, order b){
    return a.getPriority() < b.getPriority();
  }
};

int main(){

  return 0;
}
