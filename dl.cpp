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


void *factory_thread(void *arg){
  while(true) 
    if (!inventory_full)
    {
      donut_count++;
      print_thread("F: Doughnut #" + to_string(donut_count) + " produced")
    
  }else {
      print_thread("F: The Production was Halted D:");
  }
}
 return NULL;
}

void *warehouse_thread(void *arg) {
  while (true) {
    if (dc >= 12) { // donut count 
      ic++; //inventory count
      dc -= 12;
      print_thread("W: Box #" + to_string(ic) + "ready");
      if (ic >= 10) {
        ic = true; 
        print_thread("W: ITS FULL!!!");e
      }
    }
  }
  return NULL;
}



main() {
  pthread_t factory, warehouse;
  int status;

  status = phtread_create(&factory, nullptr, factory_thread, nullptr);
  if (status != 0){
    cerr << "Faiiled " << endl;
    return 1;
  }

  status = pthread_create(&warehouse, nullpt, warehouse_thread, nullptr);
  if (status != 0) {
    cerr << "Failed to create warehouse thread" << endl;
    return 1;
  }

  while(true) {

int boxes2sell;
cout << "Number of boxes to sell"
cin >> boxes2sell;

if (boxes2sell < 0) break;
ic = boxes2sell;
print_thread("S: Thank you!" + to_string(boxes2sell);
if (inventory_full && ic < 10 ) {
  inventory_full = false;
  print_thread("Space no free, resuming...");
    else {
      print_thread("not enough space");
    
    }
}
pthread_cancel(factory);
pthread_cancel(warehouse);
pthread_join(factory, NULL);
pthread_join(warehouse, NULL);

return 0;

}
