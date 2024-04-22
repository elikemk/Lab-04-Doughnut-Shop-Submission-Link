#include <iostream>
#include <pthread.h> 
#include <unistd.h>


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

