
#include "Random.h"

Random::Random() {


}
float Random::randomFloat(){
	return (float)(rand()) / (float)(RAND_MAX);
}
float Random::random(int a, int b){
	if(a > b)
		return random(b,a);
	if(a == b)
		return a;

	return (float)randomInt(a,b) + randomFloat();
}

int Random::randomInt(int a, int b){
	if(a > b)
		return randomInt(b,a);
	if(a == b)
		return a;

	return a + (rand() %(b-a));
}



