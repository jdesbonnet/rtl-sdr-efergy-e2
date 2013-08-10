int main (int argc, char **argv) {
	float RC = 1.0/(CUTOFF*2*3.14);
	float dt = 1.0/SAMPLE_RATE;
	float alpha = RC/(RC + dt);
	float filteredArray[numSamples];
	filteredArray[0] = data.recordedSamples[0];
    for (i = 1; i<numSamples; i++){
        filteredArray[i] = alpha * (filteredArray[i-1] + data.recordedSamples[i] - data.recordedSamples[i-1]);
    }
    data.recordedSamples = filteredArray;


