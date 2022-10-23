#include<stdio.h>
int main(void) {
	double x0=0;
	float a;
	float h=0.001;
	int n=-1;
	int k;

    
	printf("Please enter a primary value.(value of \"a\") \n");
	scanf("%f",&a);
	printf("Please enter the number of points.\n");
	scanf("%d",&k);
	printf("n            xn             yn\n");
	while(n++<k) {
		printf("%-3d%15f%15f\n",n,x0,a);
		x0=x0+h;
		a=(1-h)*a;



	}
	

	return 0;
}
