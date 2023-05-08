#include <stdio.h>
int giaiThua(int n){
	if(n==1)
		return 1;
	return n*giaiThua(n-1);
}
int main(){
	int n;
	printf("nhap n!\n",n);
	scanf("%d!",&n);
	printf("%d! = %d",n,giaiThua(n));
	return 0;
}
