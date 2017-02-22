#include "CHistogramPokus.h"

CHistogramPokus::CHistogramPokus()
{
	probability = 0.5; 
}

CHistogramPokus::CHistogramPokus(int orderi,float gaini,int length)
{
	probability = 0.5; 
}

CHistogramPokus::~CHistogramPokus()
{
}

void CHistogramPokus::build(unsigned int* times, unsigned char* signal, int length, int orderi)
{
	int positive = 0;
	for (int i = 0;i<length;i++) positive += signal[i];
	probability = (float)(positive)/length;
}

float CHistogramPokus::estimate(int time, int maxOrder)
{
	return probability;
}

int CHistogramPokus::load(FILE* file)
{
	int ret =0;
	ret+=fread(&probability,sizeof(float),1,file);
	return ret;
}

int CHistogramPokus::save(FILE* file,bool lossy)
{
	fwrite(&probability,sizeof(float),1,file);
	return 0;
}



