#include <Romi32U4.h>
#include "ultrasonic.h"

int SAMPLE_COUNT = 7;

// helper for selection sort
void swap(float *xp, float *yp)
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// implementation of selection sort
void selectionSort(float arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

float filter(float arr[]) {
    int n = SAMPLE_COUNT;
	  selectionSort(arr, n);
    int middle = (n / 2);
    return (arr[middle]);
}

void Ultrasonic::init(void){
    pinMode(trig_pin, OUTPUT); //specifies the function of trig_pin
    pinMode(echo_pin, INPUT);  //specifies the function of echo_pin
}

float Ultrasonic::readData(void) {
  float values[SAMPLE_COUNT];

  for (int i = 0; i < SAMPLE_COUNT; i++) {
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    float distance = (pulseIn(echo_pin, HIGH) / 58);  //converts the pulse length to cm

    values[i] = distance;
  }

  return filter(values);   // returns distance in cm
}

//print out the measurement from the ultrasonic
void Ultrasonic::printData(void){
  Serial.println(readData());
}
