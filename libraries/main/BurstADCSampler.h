#ifndef __BURSTADCSAMPLER_h__
#define __BURSTADCSAMPLER_h__

#include <Arduino.h>
#include "Pinouts.h"

#define NUM_PINS 9


struct node{
	int data;
	struct node* next;
}typedef node;

class BurstADCSampler
{
public:
	void sample(void);
	void print(void);

private:
	node* headarray[NUM_PINS];

	//helper func
	void update(void);
	void save(void);	
};


#endif
