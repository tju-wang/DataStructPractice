#include "recurs.h"

/*
递归函数
1.递归方法实现斐波那契数列输出  
2.递归实现0-100求和
*/

int main(int argv,char *argc[])
{
    long value =15;
    printf("长度为 %ld 位的斐波那契数列为：\n",value);
    printf("%ld  \n",fibonacci(value));
    fibonacci_print(1,0,value+1);
    printf("\n");
    long num = 100;
    printf("0-%ld的自然数和为： %ld\n",num,sum(num));
    return 0;
}



long fibonacci(int n)
{
    long value = 0;
    if(n<=2)
        return 1;
    value = fibonacci(n-1) + fibonacci(n-2);
    return value;
}

unsigned long fibonacci_print(unsigned long a,unsigned long b,unsigned long n)
{
    printf("%ld  ",a);
    if(n<=2)
        return 1;
   return (fibonacci_print(a+b,a,n-1));
}

long sum(long n)
{
    if(n<1)
        return 0;
    n--;
    return (n+sum(n));
    
}



