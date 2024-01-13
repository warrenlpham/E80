#include "BurstADCSampler.h"


// create lists for each pin and rapidly collect data from each pin
// and save data into seperate file
void BurstADCSampler::sample(){
	for ( int i = 0; i < 50; i++){
		update();
	}
	save();
}

// for each pin
// create new node, read data from pin, add to the list
void BurstADCSampler::update(){
	timestamp();
	for ( int i = 1; i < NUM_PINS; i++){
		node* curr = new node;
		curr->data = analogRead(pinMap[i]);
		curr->next = headarray[i];
		headarray[i] = curr;
	}
}

// update the TIME_INDEX list with current time
void BurstADCSampler::timestamp(){
	node* time_node = new node;
	time_node->data = micros();
	time_node->next = headarray[TIME_INDEX];
	headarray[TIME_INDEX] = time_node;
}


// save data into seperate file
void BurstADCSampler::save(){

}

// for debugging
// dump each list into serial
void BurstADCSampler::print(){
	for ( int i = 0; i < NUM_PINS; i++){
		node* curr = headarray[i];
		while(curr != nullptr){
			Serial.print(curr->data);
			Serial.print(",");
			curr = curr->next;
		}
		printf("\n");
	}
}

