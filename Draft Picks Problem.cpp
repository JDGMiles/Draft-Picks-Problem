#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  srand (time(NULL)); // initialize random seed
	bool card[360]; // tracks 360 cards; 1 is a piece of Power 9, 0 is not
	int n=1000; // number of trials
	int makepower=0; // used for setting a card to Power 9
  int powercount=0; // used for counting power in a booster
  int getspowercases=0;

	for(int i=0; i<n; i++){
		for(int j=0; j<360; j++){card[j]=0;} // wipes all cards
		for(int j=0; j<9; j++){ // sets 9 random cards as the Power 9
			makepower = rand() % 360;
			if(card[makepower]==1){j--;}
			else{card[makepower]=1;}
		}
    for(int j=0; j<24; j++){ // goes through each booster
      for(int k=0; k<15; k++){ // goes through each card in a booster
        if(card[15*j+k]==1){powercount++;} // checks if a piece of Power 9 and counts if so
      }
      if(powercount>j/3){getspowercases++; j=24;} // checks if booster contains enough Power to guarantee I get one in the draft
      powercount=0; // resets powercount for next booster
    }
	}

	cout << "Trials: " << n << " Successful: " << getspowercases << " Estimated Probability: " << float(getspowercases)/n;

	return 0;
}
