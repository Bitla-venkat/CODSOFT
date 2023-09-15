#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    time_t current_time = time(NULL);
	// Providing a seed value
	srand((unsigned) time(NULL));

	// Get a random number between 1 and 100
	int random = (rand()%100)+1;
    int done=0;
    int guess,attempts;
    attempts=0;
    cout<<"guess the number between 1 to 100"<<endl;
    while(done==0){
        cin>>guess;
        if(random<guess){
            cout<<"too high"<<endl;
        }
        if(random>guess){
            cout<<"too low"<<endl;
        }
        if(random==guess){
            cout<<"you guessed it correct"<<endl;
            done=1;
            cout<<"you guessed in "<<attempts+1<<" attempts"<<endl;
        }
        attempts++;
    }

	return 0;
}
