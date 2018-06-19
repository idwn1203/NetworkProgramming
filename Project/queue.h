#ifndef __QUEUE_H__

#include <stdint.h>

#define QUEUE_SIZE 10

typedef int Data_t;

void push(Data_t* src, int n);
int pop(Data_t* dest, int n);


#endif __QUEUE_H__