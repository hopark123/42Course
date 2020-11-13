#include <stdio.h>

int main()
{
	//width < length
	printf("1 : @%3d@\n",1234); // width 무시
	//width > length
	printf("2 : @%6d@\n",1234);
	//width > length -플래그
	printf("3 : @%-6d@\n",1234);
	//width > precision > length
	printf("4 : @%6.5d@\n",1234);
	//precision > width > length
	printf("5 : @%5.6d@\n",1234);
	//length > precision > width
	printf("6 : @%5.6d@\n",1234567);
	// 공백플래그
	printf("%d\n", 123);
	printf("% d\n", 123);
	printf("% 3d\n", 123);
	printf("%3d\n", 123);








}
