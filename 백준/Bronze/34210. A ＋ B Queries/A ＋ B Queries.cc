#include "aplusb.h"

std::vector<int> a, b;

void initialize(std::vector<int> A,std::vector<int> B)
{
	a.clear();
	a=A;

	b.clear();
	b=B;

	return;
}

int answer_question(int i,int j)
{
	return a[i]+b[j];
}