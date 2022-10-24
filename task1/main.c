#include<stdio.h>
#include<math.h>
int main(void) {
	double x0=0;
	float a,b;
	float h=0.001;
	a=b=M_E;

	printf("          xn             yn          distance\n");
	do {
		b=a;
		printf("%15f%15f%",x0,a);
		x0=x0+h;
		a=(1-h)*a;
		printf("%15f\n",b-a);


	} while(b-a>0.000001) ;
	printf("The last value of y is %f",a);


	return 0;
}