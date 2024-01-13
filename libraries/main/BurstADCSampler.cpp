#include "BurstADCSampler.h"


// create lists for each pin and rapidly collect data from each pin
// and save data into seperate file
void BurstADCSampler::sample(){
	for ( int i = 0; i < 10; i++){
		update();
	}
	save();
}

// for each pin
// create new node, read data from pin, add to the list
void BurstADCSampler::update(){
	for ( int i = 0; i < NUM_PINS; i++){
		node* curr = new node;
		curr->data = i;
		curr->next = headarray[i];
		headarray[i] = curr;
	}
}

// for debugging
// dump each list into serial
void BurstADCSampler::print(){
	for ( int i = 0; i < NUM_PINS; ++i){
		node* curr = headarray[i];
		while(curr != nullptr){
			Serial.print(curr->data);
			curr = curr->next;
		}
		printf("\n");
	}
}

// save data into seperate file
void BurstADCSampler::save(){

}
