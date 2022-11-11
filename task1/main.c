#include<stdio.h>
#include<math.h>
int main(void) {
	double x0=0;//定义起点
	float a,b;
	float h=0.001;//定义步长
	a=b=M_E;

	printf("          xn             yn          distance\n");
	do {
		b=a;//把上一个a的值赋值给b，根据（b-a）可以计算出因变量（函数值）的变化量。
		printf("%15f%15f%",x0,a);
		x0=x0+h;//根据步长得出自变量的递推关系
		a=(1-h)*a;//由欧拉法得出因变量（函数值）的递推关系
		printf("%15f\n",b-a);


	} while(b-a>0.000001) ;//验证测试条件，由于一开始b-a=0，所以此处采用出口条件循环即可。
	printf("The last value of y is %f",a);


	return 0;
}