#include <iostream>
#include <pthread.h> 
#include <unistd.h>

using namespace std;

int donut_count = 0
void *factory_thread(void *arg) {
  while(true){
    donut_count++; 
    cout << "The Donuts from Factory: Produced " << donut_count << " Donuts\n";
    usleep(500000); // this sleeps for 0.5 seconds so 500k microseonds 
  }
  return NULL;
}

main(){
  pthread_t factory; 
  int status; 

  status = pthread_create(&factory, NULL, factory_thread, NULL);
  if (status != 0) {
    cerr << "Failed to create teh factory thread";
    return 1;
  }
  pthread_join(factory, NULL);
  return 0;
}
