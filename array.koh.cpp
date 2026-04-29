#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class order{
  private:
  string name;
  string details;
  int priority;

  public:
  order (string n, string d, int p){
    name = n;
    details = d;
    priority = p;
  }
  # hello po!
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
