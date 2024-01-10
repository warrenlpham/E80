#ifndef __BURSTADCSAMPLER_h__
#define __BURSTADCSAMPLER_h__

#include <Arduino.h>
#include "Pinouts.h"

#define NUM_PINS 9


struct node{
	int data;
	struct node* next_node;
}typedef node;

class BurstADCSampler
{
public:
	BurstADCSampler(void);
	void sample(void);

private:
	node* dataArray[NUM_PINS];
	void update(void);	
	void save(void);	
};


#endif




