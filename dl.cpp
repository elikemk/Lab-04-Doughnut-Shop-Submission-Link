#include <iostream>
#include <pthread.h> 
#include <unistd.h>


//These are the global varibales

int donut_count = 0;
bool inventory_full = false;
int inventory_count = 0;

