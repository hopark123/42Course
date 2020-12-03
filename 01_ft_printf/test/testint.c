#include <stdio.h>

int main()
{
	// //width < length
	// printf("1 : @%3d@\n",1234); // width 무시
	// //width > length
	// printf("2 : @%6d@\n",1234);
	// //width > length -플래그
	// printf("3 : @%-6d@\n",1234);
	// //width > precision > length
	// printf("4 : @%6.5d@\n",1234);
	// //precision > width > length
	// printf("5 : @%5.6d@\n",1234);
	// //length > precision > width
	// printf("6 : @%5.6d@\n",1234567);
// 	// 공백플래그
// 	printf("%d\n", 123);`
// 	printf("% d\n", 123);
// 	printf("% 3d\n", 123);
// 	printf("%3d\n", 123);
	// printf("%- 0+#6d",123);
				// printf("%03.3f\n",1.23);
				// printf("%010.7f\n",1.23);
				// printf("%010.8f\n",1.23);
				// printf("%010.9f\n",1.23);
				// printf("%010.10f\n",1.23);
				// printf("%010.11f\n",1.23);
	// printf("%5.2d",  3,1234);


// printf("%1lf\n",(double)0.12345678);
// printf("%2lf\n",(double)0.12345678);
// printf("%3lf\n",(double)0.12345678);
// printf("%4lf\n",(double)0.12345678);
// printf("%5lf\n",(double)0.12345678);
// printf("%6lf\n",(double)0.12345678);
// printf("%7lf\n",(double)0.12345678);
// printf("%8lf\n",(double)0.12345678);
// printf("%9lf\n",(double)0.12345678);
// char *format = "%09.5d@\n";
// char *a = "abc";
// printf("return : %d\n",printf(format, -7));
// printf("@%09.10d@\n", -1234);
// printf("@%- 9.10d@\n", 1234);
// printf("@%-9.10d@\n", 1234);
// printf("@%-10.9d@\n", -1234);
// printf("@%- 10.9d@\n", 1234);
// printf("@%-10.9d@\n", 1234);



// len >= w > p
// printf("@%5.3d@\n", 1234567);
// printf("@%+5.3d@\n", 1234567);
// printf("@% 5.3d@\n", 1234567);
// printf("@%5.3d@\n", -1234567);
// printf("@%+5.3d@\n", -1234567);
// printf("@% 5.3d@\n", -1234567);
// printf("%d",printf("@%5.3d@\n", 12345));
// printf("%d",printf("@%+5.3d@\n", 12345));
// printf("%d",printf("@% 5.3d@\n", 12345));
// printf("%d",printf("@%5.3d@\n", -12345));
// printf("%d",printf("@%+5.3d@\n", -12345));
// printf("%d",printf("@% 5.3d@\n", -12345));

// 	// len >= p > w
// printf("@%3.5d@\n", 1234567);
// printf("@%+3.5d@\n", 1234567);
// printf("@% 3.5d@\n", 1234567);
// printf("@%3.5d@\n", -1234567);
// printf("@%+3.5d@\n", -1234567);
// printf("@% 3.5d@\n", -1234567);
	// w > len > p
// printf("@%08d@\n", 12345);
// printf("@%+8.3d@\n", 12345);
// printf("@% 8.3d@\n", 12345);
// printf("@%8.3d@\n", -12345);
// printf("@%+8.3d@\n", -12345);
// printf("@% 8.3d@\n", -12345);
// printf("@%-8.3d@\n", 12345);
// printf("@%-+8.3d@\n", 12345);
// printf("@%- 8.3d@\n", 12345);
// printf("@%-8.3d@\n", -12345);
// printf("@%-+8.3d@\n", -12345);
// printf("@%- 8.3d@\n", -12345);

	// w > p > len
	// printf("@%8.4d@\n", 123);
	// printf("@%+8.4d@\n", 123);
	// printf("@% 8.4d@\n", 123);
	// printf("@%8.4d@\n", -123);
	// printf("@%+8.4d@\n", -123);
	// printf("@% 8.4d@\n", -123);
	// printf("@%-8.4d@\n", 123);
	// printf("@%-+8.4d@\n", 123);
	// printf("@%- 8.4d@\n", 123);
	// printf("@%-8.4d@\n", -123);
	// printf("@%-+8.4d@\n", -123);
	// printf("@%- 8.4d@\n", -123);

	// char *format = "@%-+5.0d@\n";
	// long long c = 0;
	// printf("\n");
	// printf("pf : %d\n",	printf(format,c));

	//p >= w > len
	// printf("@%5.9d@\n", 123);
	// printf("@%+5.9d@\n", 123);
	// printf("@% 5.9d@\n", 123);
	// printf("@%5.9d@\n", -123);
	// printf("@%+5.9d@\n", -123);
	// printf("@% 5.9d@\n", -123);

	// printf("@%-5.9d@\n", 123);
	// printf("@%-+5.9d@\n", 123);
	// printf("@%- 5.9d@\n", 123);
	// printf("@%-5.9d@\n", -123);
	// printf("@%-+5.9d@\n", -123);
	// printf("@%- 5.9d@\n", -123);

	// p > len > w
	// printf("@%4.9d@\n", 12345);
	// printf("@%+4.9d@\n", 12345);
	// printf("@% 4.9d@\n", 12345);
	// printf("@%4.9d@\n", -12345);
	// printf("@%+4.9d@\n", -123456);
	// printf("@% 4.9d@\n", -123456);

// printf("@%+08d@\n", -12345);
// printf("@%08d@\n", 12345);
// printf("@% 08d@\n", -12345);
// printf("@%+03d@\n", -12345);
// printf("@%03d@\n", -12345);
// printf("@% .0d@\n", 0);

char *f1= "1\n%d#\n";
char *f2= "2\n%.d#\n";
char *f3= "3\n%.*d#\n";
char *f4= "4\n%d#\n";

int c = 0;
printf("p : %d\n",printf(f1,c));
printf("p : %d\n",printf(f2,c));
printf("p : %d\n",printf(f3,0,c));
printf("p : %d\n",printf(f4,c));




}
