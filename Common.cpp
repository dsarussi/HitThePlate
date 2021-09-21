#include "Common.h"

#include <stdlib.h>
//global functions:
int random(int num)
{
	//you need to put the next line before the random call:
	//srand( (unsigned)time( NULL ) );
	return int(float(rand())/RAND_MAX*num);
}

float Pie()
{
	return (float)3.14159;
}