#include<stdio.h>
main() {
	int N,p=1,s=1, c,i,f;

	scanf("%d%d",&N,&f);

	for(int n=1;n<N;n++) {
		scanf("%d", &c);
		if(c==N) {
			i=n;
			break;
		}
	}

	while(1<<p<N-f) p++;
	while(1<<s<i) s++;

	printf("%d %d\n",p,s);
}