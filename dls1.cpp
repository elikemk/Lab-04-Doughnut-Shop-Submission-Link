#include <iostream>
#include <pthread.h> 
#include <unistd.h>

using namespace std;

int donut_count = 0;
void *factory_thread(void *arg) {
  while(true){
    donut_count++; 
    usleep(500000); // this sleeps for 0.5 seconds so 500k microseonds 
  }
  return NULL;
}

int main(){


  pthread_t factory; 
  int status; 

  status = pthread_create(&factory, NULL, factory_thread, NULL);
  if (status != 0) {
    cerr << "Failed to create teh factory thread" << status << endl;
    return 1;
  }

  while(true){
    cout << "This is the Main Total Produced = " << donut_count << endl;
    usleep(100000);
  }
  pthread_join(factory, NULL);
  return 0;
}
