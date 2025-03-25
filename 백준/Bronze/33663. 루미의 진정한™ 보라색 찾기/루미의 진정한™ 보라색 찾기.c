#include<stdio.h>

int main(void)
{
	int h_lo, h_hi, s_lo, s_hi, v_lo, v_hi, R, G, B, M, m;
	double H, S, V;

	scanf("%d%d", &h_lo, &h_hi);
	scanf("%d%d", &s_lo, &s_hi);
	scanf("%d%d", &v_lo, &v_hi);
	scanf("%d%d%d", &R, &G, &B);

	M=R<G?G:R;
	M=M<B?B:M;

	m=R<G?R:G;
	m=m<B?m:B;

	V=(double)M;

	if(V<v_lo || v_hi<V)
	{
		printf("Lumi will not like it.");
		return 0;
	}

	S=(double)255*(V-m)/V;
	if(S<s_lo || s_hi<S)
	{
		printf("Lumi will not like it.");
		return 0;
	}

	if(V==R)
		H=(double)60*(G-B)/(V-m);
	else if(V==G)
		H=(double)120+60*(B-R)/(V-m);
	else
		H=(double)240+60*(R-G)/(V-m);

	if(H<0)
		H+=360;

	if(H<h_lo || h_hi<H)
	{
		printf("Lumi will not like it.");
		return 0;
	}

	printf("Lumi will like it.");
	return 0;
}