#include "include/ft_printf.h"

int main() {

	//No Speicifiers Tests
	ft_printf("hello, world!");
	ft_printf("");
	ft_printf("\t\n\r\v\f\n");
	ft_printf("hello");
	ft_printf("world");
	ft_printf("he");
	ft_printf(" is alive");
	//%% Tests
	ft_printf("%%");
	ft_printf("%5%");
	ft_printf("%-5%");
	ft_printf("%05%");
	ft_printf("%-05%");
	//Null specifier tests
	ft_printf("%");
	ft_printf("%5");
	ft_printf("%05");
	ft_printf("%-05");
	ft_printf("%-5");
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','?');
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','?');
	ft_printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','?');
	ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	ft_printf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	ft_printf("%c", '\0');
	ft_printf("%5c", '\0');
	ft_printf("%-5c", '\0');
//%s STRING TESTS
	ft_printf("hello, %s.", "gavin");
	ft_printf("%s", "testing testing");
	ft_printf("%s%s", "hello", "world");
	ft_printf("..%s stuff %s", "a", "b");
	ft_printf("this %s is empty", "");
	ft_printf("this %s is %s", "hello", "");
	ft_printf("this %s is %s", "", "hello");
	ft_printf("%s%s%s", "1", "2", "3's a charm");
//String specifiers with field_width, space- or zero-padded
	ft_printf("%32s", "abc");
	ft_printf("%16s", "nark nark");
	ft_printf("%5s", "goes over");
//String specifiers with field_width, space- or zero-padded, left-justified
	ft_printf("%-32s", "abc");
	ft_printf("%-16s", "nark nark");
	ft_printf("%-5s", "goes over");
//String specifiers with precision
	ft_printf("%.7s", "hello");
	ft_printf("%.3s", "hello");
	ft_printf("%.s", "hello");
	ft_printf("%.0s", "hello");
	ft_printf("%.3s%.2s", "holla", "bitch");
	ft_printf("%.2s%.7s", "hello", "world");
	ft_printf("%.7s%.2s", "hello", "world");
	ft_printf("%.5s%7s", "yo", "boi");
//String specifiers with both precision and field width
	ft_printf("%7.5s", "yolo");
	ft_printf("%7.5s", "bombastic");
	ft_printf("%-7.5s", "yolo");
	ft_printf("%-7.5s", "tubular");
	ft_printf("%7.7s%7.7s", "hello", "world");
	ft_printf("%3.7s%7.7s", "hello", "world");
	ft_printf("%7.7s%3.7s", "hello", "world");
	ft_printf("%3.7s%3.7s", "hello", "world");
	ft_printf("%7.3s%7.7s", "hello", "world");
	ft_printf("%3.3s%7.7s", "hello", "world");
	ft_printf("%7.3s%3.7s", "hello", "world");
	ft_printf("%3.3s%3.7s", "hello", "world");
	ft_printf("%7.7s%7.3s", "hello", "world");
	ft_printf("%3.7s%7.3s", "hello", "world");
	ft_printf("%7.7s%3.3s", "hello", "world");
	ft_printf("%3.7s%3.3s", "hello", "world");
	ft_printf("%7.3s%7.3s", "hello", "world");
	ft_printf("%3.3s%7.3s", "hello", "world");
	ft_printf("%7.3s%3.3s", "hello", "world");
	ft_printf("%3.3s%3.3s", "hello", "world");
	ft_printf("%3s%3s", "hello", "world");
	//String specifiers, other tests
	ft_printf("%-7s%5s", "hello", "world");
	ft_printf("%7s%-5s", "hello", "world");
	//String specifiers - NULL strings
	ft_printf("hello, %s.", NULL);
	ft_printf("%s", NULL);
	ft_printf("%32s", NULL);
	ft_printf("%2s", NULL);
	ft_printf("%-32s", NULL);
	ft_printf("%-16s", NULL);
	ft_printf("%-3s", NULL);
//String specifiers with precision
	ft_printf("%.9s", "NULL");
	ft_printf("%.3s", "NULL");
	ft_printf("%.s", "NULL");
	ft_printf("%.0s", "NULL");
//String s_hidden tests
static char *s_hidden = "hi low\0don't print me lol\0";
	ft_printf("%s", s_hidden);
// width pad
	ft_printf("%3s", s_hidden);
	ft_printf("%9s", s_hidden);
// precision no width
	ft_printf("%.s", s_hidden);
	ft_printf("%.9s", s_hidden);
// precision  0 before number
	ft_printf("%.03s", s_hidden);
	ft_printf("%.09s", s_hidden);
	ft_printf("%.03s", NULL);
	ft_printf("%.09s", NULL);
	ft_printf("%.00s", "\0");
	ft_printf("%.01s", "\0");
	ft_printf("%.03s", "\0");
	ft_printf("%.09s", "\0");
// width  no precision
	ft_printf("%3.s", s_hidden);
	ft_printf("%10.s", s_hidden);
	ft_printf("%3.s", NULL);
	ft_printf("%10.s", NULL);
	ft_printf("%1.s", "\0");
	ft_printf("%2.s", "\0");
	ft_printf("%9.s", "\0");
// lj flag width  no precision
	ft_printf("%-3.s", s_hidden);
	ft_printf("%-8.s", s_hidden);
	ft_printf("%-3.s", NULL);
	ft_printf("%-8.s", NULL);
	ft_printf("%-1.s", "\0");
	ft_printf("%-2.s", "\0");
	ft_printf("%-6.s", "\0");
// width  precision 1
	ft_printf("%3.1s", s_hidden);
	ft_printf("%10.1s", s_hidden);
	ft_printf("%3.1s", NULL);
	ft_printf("%9.1s", NULL);
// lj flag width  precision 1
	ft_printf("%-3.1s", s_hidden);
	ft_printf("%-10.1s", s_hidden);
	ft_printf("%-3.1s", NULL);
	ft_printf("%-9.1s", NULL);
	ft_printf("%-3.1s", "\0");
	ft_printf("%-6.1s", "\0");
// width  exact precision
	ft_printf("%3.6s", s_hidden);
	ft_printf("%20.6s", s_hidden);
	ft_printf("%3.6s", NULL);
	ft_printf("%20.6s", NULL);
	ft_printf("%3.6s", "\0");
	ft_printf("%6.6s", "\0");
// lj flag width exact precision
	ft_printf("%-3.6s", s_hidden);
	ft_printf("%-20.6s", s_hidden);
// lj flag width excess precision
	ft_printf("%-3.8s", s_hidden);
	ft_printf("%-10.8s", s_hidden);
	ft_printf("%-3.8s", NULL);
	ft_printf("%-10.8s", NULL);
// decoy lj flag
   	ft_printf("%-.00s", s_hidden);
   	ft_printf("%-.09s", s_hidden);
// multiple flags diff order same width and precision
	 ft_printf("%+- 06.06s", s_hidden);
	 ft_printf("% 0+-6.06s", s_hidden);
	 ft_printf("%0 +-6.06s", s_hidden);
	 ft_printf("%+-0 6.06s", s_hidden);
	 ft_printf("%-+ 06.06s", s_hidden);
	 ft_printf("% -+06.06s", s_hidden);
 // multiple flags diff order width > precision
	 ft_printf("%+- 07.06s", s_hidden);
	 ft_printf("% 0+-8.06s", s_hidden);
	 ft_printf("%0 +-9.06s", s_hidden);
	 ft_printf("%+-0 10.06s", s_hidden);
	 ft_printf("%-+ 011.06s", s_hidden);
	 ft_printf("% -+012.06s", s_hidden);
// multiple flags diff order width > precision, truncated string
	 ft_printf("%+- 06.04s", s_hidden);
	 ft_printf("% 0+-6.04s", s_hidden);
	 ft_printf("%0 +-6.04s", s_hidden);
	 ft_printf("%+-0 6.04s", s_hidden);
	 ft_printf("%-+ 06.04s", s_hidden);
	 ft_printf("% 0-+6.04s", s_hidden);
// multiple flags diff order width < precision, excess precision
	 ft_printf("%+- 06.09s", s_hidden);
	 ft_printf("% 0+-6.09s", s_hidden);
	 ft_printf("%0 +-6.09s", s_hidden);
	 ft_printf("%+-0 6.09s", s_hidden);
	 ft_printf("%-+ 06.09s", s_hidden);
	 ft_printf("% 0-+6.09s", s_hidden);
 // multi zeros
	 ft_printf("%00s", s_hidden);
	 ft_printf("%000s", s_hidden);
	 ft_printf("%0000s", s_hidden);
	 ft_printf("%-00s", s_hidden);
	 ft_printf("%0-0s", s_hidden);
	 ft_printf("%00-s", s_hidden);
// zero and width
	 ft_printf("%03s", s_hidden);
	 ft_printf("%09s", s_hidden);
// as and zero flags  width
	 ft_printf("%+03s", s_hidden);
	 ft_printf("%+09s", s_hidden);
 // flag cancelling
	 ft_printf("%-03s", s_hidden);
	 ft_printf("%-09s", s_hidden);
	 ft_printf("%+ 3s", s_hidden);
	 ft_printf("%+ 6s", s_hidden);
/* -----------------------------------------------------------------------------
**                                              %p POINTERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Pointers - Basic
static char     a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;
	ft_printf("%p", NULL);

	 ft_printf("%9.2p\n", 1234);
	 ft_printf("%2.9p\n", 1234);
	 ft_printf("%.5p", 0);
	 ft_printf("%.0p", 0);
	ft_printf("%5p", 0);
	ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
   	ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
   	ft_printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

/* -----------------------------------------------------------------------------
**                                              %d INTEGER TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Signed integers - no modifers
   	ft_printf("this %d number", 17);
	ft_printf("this %d number", -267);
	ft_printf("this %d number", 0);
   	ft_printf("%d", 3);
	ft_printf("%d", -1);
	ft_printf("%d", 0);
   	ft_printf("%d",  2147483647);
   	ft_printf("%d", (int)(-2147483678));
//Signed integers with field width
	ft_printf("%7d", 33);
	ft_printf("%7d", -14);
	ft_printf("%3d", 0);
	ft_printf("%5d", 52625);
	ft_printf("%5d", -2562);
	ft_printf("%4d", 94827);
	ft_printf("%4d", -2464);
	ft_printf("%-7d", 33);
   	ft_printf("%-7d", -14);
	ft_printf("%-3d", 0);
	ft_printf("%-5d", 52625);
	ft_printf("%-5d", -2562);
	ft_printf("%-4d", 94827);
   	ft_printf("%-4d", -2464);
//signed integers with precision
	ft_printf("%.5d", 2);
   	ft_printf("%.6d", -3);
	ft_printf("%.3d", 0);
   	ft_printf("%.4d", 5263);
   	ft_printf("%.4d", -2372);
	ft_printf("%.3d", 13862);
	ft_printf("%.3d",-23646);
//Signed integers with zero field width padding
   	ft_printf("%05d", 43);
	ft_printf("%07d", -54);
	ft_printf("%03d", 0);
	ft_printf("%03d", 634);
	ft_printf("%04d", -532);
	ft_printf("%04d", -4825);
//Signed integers with field width and precision
	ft_printf("%8.5d", 34);
	ft_printf("%10.5d", -216);
	ft_printf("%8.5d", 0);
	ft_printf("%8.3d", 8375);
   	ft_printf("%8.3d", -8473);
	ft_printf("%3.7d", 3267);
   	ft_printf("%3.7d", -2375);
   	ft_printf("%3.3d", 6983);
   	ft_printf("%3.3d", -8462);
//Signed integers with field width and precision, left-justified
	ft_printf("%-8.5d", 34);
	ft_printf("%-10.5d", -216);
   	ft_printf("%-8.5d", 0);
   	ft_printf("%-8.3d", 8375);
   	ft_printf("%-8.3d", -8473);
   	ft_printf("%-3.7d", 3267);
   	ft_printf("%-3.7d", -2375);
   	ft_printf("%-3.3d", 6983);
   	ft_printf("%-3.3d", -8462);
//Signed integers with field width and precision with zeropadding
   	ft_printf("%08.5d", 34);
   	ft_printf("%010.5d", -216);
   	ft_printf("%08.5d", 0);
   	ft_printf("%08.3d", 8375);
   	ft_printf("%08.3d", -8473);
   	ft_printf("%03.7d", 3267);
   	ft_printf("%03.7d", -2375);
   	ft_printf("%03.3d", 6983);
   	ft_printf("%03.3d", -8462);
//Signed integers with field width and precision, left-justified with zeropadding
   	ft_printf("%0-8.5d", 34);
   	ft_printf("%0-10.5d", -216);
   	ft_printf("%0-8.5d", 0);
   	ft_printf("%0-8.3d", 8375);
   	ft_printf("%0-8.3d", -8473);
   	ft_printf("%0-3.7d", 3267);
   	ft_printf("%0-3.7d", -2375);
   	ft_printf("%0-3.3d", 6983);
   	ft_printf("%0-3.3d", -8462);
//Signed integers - zero precision zero value
   	ft_printf("%.0d", 0);
   	ft_printf("%.d", 0);
   	ft_printf("%5.0d", 0);
   	ft_printf("%5.d", 0);
   	ft_printf("%-5.0d", 0);
   	ft_printf("%-5.d", 0);
/* -----------------------------------------------------------------------------
**                                              %i INTEGER TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Signed integers - no modifers
   	ft_printf("this %i number", 17);
   	ft_printf("this %i number", -267);
   	ft_printf("this %i number", 0);
   	ft_printf("%i", 3);
   	ft_printf("%i", -1);
   	ft_printf("%i", 0);
   	ft_printf("%i",  2147483647);
   	ft_printf("%i", (int)(-2147483678));
//Signed integers  field width
   	ft_printf("%7i", 33);
	ft_printf("%3i", 0);
   	ft_printf("%5i", 52625);
   	ft_printf("%5i", -2562);
   	ft_printf("%4i", 94827);
   	ft_printf("%4i", -2464);
   	ft_printf("%-7i", 33);
   	ft_printf("%-7i", -14);
   	ft_printf("%-3i", 0);
   	ft_printf("%-5i", 52625);
	ft_printf("%-5i", -2562);
   	ft_printf("%-4i", 94827);
   	ft_printf("%-4i", -2464);
//signed integers with precision
   	ft_printf("%.5i", 2);
   	ft_printf("%.6i", -3);
   	ft_printf("%.3i", 0);
   	ft_printf("%.4i", 5263);
   	ft_printf("%.4i", -2372);
	ft_printf("%.3i", 13862);
	ft_printf("%.3i",-23646);
//Signed integers with zero field width padding
   	ft_printf("%05i", 43);
	ft_printf("%07i", -54);
   	ft_printf("%03i", 0);
   	ft_printf("%03i", 634);
   	ft_printf("%04i", -532);
   	ft_printf("%04i", -4825);
//Signed integers with field width and precision
   	ft_printf("%8.5i", 34);
	ft_printf("%10.5i", -216);
   	ft_printf("%8.5i", 0);
   	ft_printf("%8.3i", 8375);
   	ft_printf("%8.3i", -8473);
   	ft_printf("%3.7i", 3267);
   	ft_printf("%3.7i", -2375);
   	ft_printf("%3.3i", 6983);
   	ft_printf("%3.3i", -8462);
//Signed integers with field width and precision, left-justified
	ft_printf("%-8.5i", 34);
   	ft_printf("%-10.5i", -216);
   	ft_printf("%-8.5i", 0);
	ft_printf("%-8.3i", 8375);
	ft_printf("%-8.3i", -8473);
	ft_printf("%-3.7i", 3267);
	ft_printf("%-3.7i", -2375);
	ft_printf("%-3.3i", 6983);
	ft_printf("%-3.3i", -8462);
//Signed integers with field width and precision with zeropadding
   	ft_printf("%08.5i", 34);
	ft_printf("%010.5i", -216);
	ft_printf("%08.5i", 0);
	ft_printf("%08.3i", 8375);
	ft_printf("%08.3i", -8473);
	ft_printf("%03.7i", 3267);
	ft_printf("%03.7i", -2375);
	ft_printf("%03.3i", 6983);
	ft_printf("%03.3i", -8462);
//Signed integers with field width and precision, left-justified with zeropadding
	ft_printf("%0-8.5i", 34);
	ft_printf("%0-10.5i", -216);
	ft_printf("%0-8.5i", 0);
	ft_printf("%0-8.3i", 8375);
	ft_printf("%0-8.3i", -8473);
	ft_printf("%0-3.7i", 3267);
	ft_printf("%0-3.7i", -2375);
	ft_printf("%0-3.3i", 6983);
	ft_printf("%0-3.3i", -8462);
//Signed integers - zero precision zero value
	ft_printf("%.0i", 0);
	ft_printf("%.i", 0);
	ft_printf("%5.0i", 0);
	ft_printf("%5.i", 0);
	ft_printf("%-5.0i", 0);
	ft_printf("%-5.i", 0);
/* -----------------------------------------------------------------------------
**                                              %u UNSIGNED INTEGERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Unsigned integers - no modifers
	ft_printf("this %u number", 17);
	ft_printf("this %u number", 0);
	ft_printf("%u", 3);
	ft_printf("%u", 4294967295u);
//Unsigned integers with field width
	ft_printf("%7u", 33);
	ft_printf("%3u", 0);
   	ft_printf("%5u", 52625);
   	ft_printf("%4u", 94827);
   	ft_printf("%-7u", 33);
   	ft_printf("%-3u", 0);
   	ft_printf("%-5u", 52625);
   	ft_printf("%-4u", 94827);
//unsigned integers with precision
   	ft_printf("%.5u", 2);
	ft_printf("%.3u", 0);
   	ft_printf("%.4u", 5263);
   	ft_printf("%.3u", 13862);
//Unsigned integers with zero field width padding
   	ft_printf("%05u", 43);
   	ft_printf("%03u", 0);
   	ft_printf("%03u", 634);
//Unsigned integers with field width and precision
   	ft_printf("%8.5u", 34);
	ft_printf("%8.5u", 0);
   	ft_printf("%8.3u", 8375);
   	ft_printf("%3.7u", 3267);
   	ft_printf("%3.3u", 6983);
//Unsigned integers with field width and precision, left-justified
   	ft_printf("%-8.5u", 34);
   	ft_printf("%-8.5u", 0);
   	ft_printf("%-8.3u", 8375);
   	ft_printf("%-3.7u", 3267);
   	ft_printf("%-3.3u", 6983);
//Unsigned integers with field width and precision with zeropadding
	ft_printf("%08.5u", 34);
   	ft_printf("%08.5u", 0);
	ft_printf("%08.3u", 8375);
	ft_printf("%03.7u", 3267);
	ft_printf("%03.3u", 6983);
//Unsigned integers with field width and precision, left-justified with zeropadding
   	ft_printf("%0-8.5u", 34);
   	ft_printf("%0-8.5u", 0);
   	ft_printf("%0-8.3u", 8375);
   	ft_printf("%0-3.7u", 3267);
   	ft_printf("%0-3.3u", 6983);
//Unsigned integers - zero precision zero value
	ft_printf("%.0u", 0);
   	ft_printf("%.u", 0);
   	ft_printf("%5.0u", 0);
   	ft_printf("%5.u", 0);
   	ft_printf("%-5.0u", 0);
   	ft_printf("%-5.u", 0);
// /* -----------------------------------------------------------------------------
// **                                              %x HEXADECIMAL LOWERS TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
//Hexadecimal lowers - no modifers
   	ft_printf("this %x number", 17);
	ft_printf("this %x number", 0);
	ft_printf("%x", 3);
   	ft_printf("%x", 4294967295u);
//Hexadecimal lowers with field width
	ft_printf("%7x", 33);
   	ft_printf("%3x", 0);
   	ft_printf("%5x", 52625);
   	ft_printf("%2x", 94827);
	ft_printf("%-7x", 33);
	ft_printf("%-3x", 0);
   	ft_printf("%-5x", 52625);
   	ft_printf("%-4x", 9648627);
//Hexadecimal lowers with precision
	ft_printf("%.5x", 21);
   	ft_printf("%.3x", 0);
   	ft_printf("%.4x", 5263);
   	ft_printf("%.3x", 938862);
//Hexadecimal lowers with zero
//field width padding
	ft_printf("%05x", 43);
