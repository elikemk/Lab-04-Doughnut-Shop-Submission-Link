#include <iostream>
#include <pthread.h> 
#include <unistd.h>

using namespace std;

//These are the global varibales
//3 threads that communicate through a set of global variables.  These variables will include an integer doughnut counter (donut_count), a boolean inventory status flag (inventory_full), and an integer inventory count (inventory_count):

int donut_count = 0;
bool inventory_full = false;
int inventory_count = 0;


//Only the factory thread should ever change the value of donut_count.
//  Only the warehouse thread should ever change the value of the inventory_full flag. 
//Both the warehouse and the sales thread will need to change the value of inventory_count 

void *factory_thread(void *arg);
void *warehouse_thread(void *arg);

void print_thread(const string& message) {
    cout << message << endl;
}

void *factory_thread(void *arg){
  while(true){
    if (!inventory_full)
    {
      donut_count++;
      print_thread("F: Doughnut #" + to_string(donut_count) + " produced");
      usleep(500000);
    
  }else {
    print_thread("F: The Production was Halted D:");
  }
}
 return NULL;
}

void *warehouse_thread(void *arg) {
  while (true) {
    if (donut_count >= 12) { // donut count 
      inventory_count++; //inventory count
      donut_count -= 12;
      print_thread("W: Box #" + to_string(inventory_count) + " is ready");
      if (inventory_count >= 10) {
        inventory_count = true; 
        print_thread("W: ITS FULL!!!");
      }
    }
    usleep(100000);
  }
  return NULL;
}



int main() {
  pthread_t factory, warehouse;
  int status;

 	status = pthread_create(&factory, NULL, factory_thread, NULL);
  if (status != 0){
    cerr << "Faiiled Factory " << endl;
    return 1;
  }

status = pthread_create(&warehouse, NULL, warehouse_thread, NULL);
  if (status != 0){
    cerr << "Failed Warehouse  " << endl;
    return 1;
  }

while(true) {

int boxes2sell;
cout << "Number of boxes to sell (and negative to quite): ";
cin >> boxes2sell;
if (boxes2sell <= inventory_count) {
    inventory_count -= boxes2sell;
    print_thread("S: Thank you! we sold " + to_string(boxes2sell) + " boxes");
    if (inventory_full && inventory_count < 10) {
        inventory_full = false;
        print_thread("Space now free, resuming...");
    }
} else {
    print_thread("Not enough inventory");
}}

pthread_cancel(factory);
pthread_cancel(warehouse);
pthread_join(factory, NULL);
pthread_join(warehouse, NULL);


return 0;

}
