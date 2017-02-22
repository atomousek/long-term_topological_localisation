#ifndef CHISTOGRAMPOKUS_H
#define CHISTOGRAMPOKUS_H

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include "CFrelement.h"

#define MAX_ADAPTIVE_ORDER 5

using namespace std;

class CHistogramPokus: public CFrelement
{
	public:
		CHistogramPokus();
		CHistogramPokus(int orderi,float gaini,int length);
		~CHistogramPokus();
		void build(unsigned int* times, unsigned char* signal, int lenght, int orderi);
		float estimate(int time, int maxOrder);
		int save(FILE* file, bool lossy = false);
		int load(FILE* file);
		float probability;
};

#endif
		
