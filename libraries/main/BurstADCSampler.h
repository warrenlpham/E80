#ifndef __BURSTADCSAMPLER_h__
#define __BURSTADCSAMPLER_h__

#include <Arduino.h>
#include "Pinouts.h"
#include <SPI.h>
#include <SD.h>
#include <stdio.h>

#define NUM_PINS 9

// should be no more than 3500 samples
// which samples for around .5 seconds
#define NUM_SAMPLES 3500


struct node{
	int data;
	struct node* next;
}typedef node;

class BurstADCSampler
{
public:
	void sample(void);
	void print(void);
	void init(void);

	int lastExecutionTime = -1;

private:
	node* headarray[NUM_PINS] = {NULL};

	//helper func
	void update(void);
	void timestamp(void);
	void save(void);
	void cleanup(void);
	void namefile(void);

	String basename = "datalog";
	String filename = "";
	const int TIME_INDEX = 0;
	const int pinMap[NUM_PINS] =  {21,14,15,16,17,24,25,26,27};


};


#endif
