#include<stdio.h>

int main(void)
{
	int T, score[5]={0};
	long long id=0;

	scanf("%d", &T);

	for(int t=0;t<T;++t)
		scanf("%d", &score[t]);

	id+=score[2]<score[0]?(score[0]-score[2])*508:(score[2]-score[0])*108;
	id+=score[3]<score[1]?(score[1]-score[3])*212:(score[3]-score[1])*305;
	if(T==5)
		id+=score[4]*707;

	printf("%lld", id*4763);
	return 0;
}