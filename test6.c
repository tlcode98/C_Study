#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

// 利用指针-指针求字符串长度
// int my_strlen(char* str){
//     char* start = str;
//     char* end = str;
//     while(*end != '\0'){
//         end++;
//     }
//     return end - start;
// }
// int main(){
//     char arr[] = "abcdefg";
//     int len = my_strlen(arr);
//     printf("%d\n",len);
//     return 0;
// }

// 1.&arr-&数组名-代表的是去除整个数组的地址，
// 而不是首元素的地址
// 2.sizeof(arr)-sizeof(数组名),计算的是整个数组的长度

// <-----二级指针------>
// int main(){
//     int a = 1;
//     int b = 2;
//     int c = 3;
//     int* arr[3] = {&a,&b,&c};
//     for(int i = 0 ; i < 3; i++){
//         printf("%d ",*arr[i]);
//     }
// }

// <----结构体---->
// struct 结构体关键字 Stu-结构体标签 struct Stu - 结构体类型
// struct Stu
// {
//     // 成员变量
//     char name[20];
//     short age; // 定义一个结构体类型
//     char tele[12];
//     char sex[5];
// }s1,s2,s3; //s1,s2,s3 是三个全局的结构体变量

// typedef struct Stu // typedef重命名
// {
//     // 成员变量
//     char name[20];
//     short age; // 定义一个结构体类型
//     char sex[5];
// }Stu; // Stu是类型

// int main(){
//     //            s，这个s是局部变量
//     // struct Stu s = {'张三',20,'1'}; // 创建结构体变量
//     Stu s1 = {'李四',20,'0'};
//     Stu* ps = &s1;
//     printf("%s",ps->name); // 结构体过大建议使用箭头
//     // 结构体传参要传地址
//     return 0;
// }

// 压栈

// 数据的存储

// 类型：1.内置类型 2.构造类型(自定义类型)
// 1.类型决定了开辟内存空间的大小
// 1.类型决定了如何看点内存空间的视角

// 1.内置类型
// 整型家族：
// char
// 1.unsigned char(无符号) 0~255
// 2.signed char(有符号) -128~127

// short
// 1.unsigned short(无符号) 
// 2.signed short(有符号) 

// int
// 1.unsigned int(无符号) 
// 2.signed int(有符号) 

// long
// 1.unsigned long(无符号)
// 2.signed long(有符号)

// 浮点型
// float
// double

// 2.构造类型
// 数组类型
// 结构体类型
// 枚举类型
// 联合类型

// 指针类型 (单独的): int* char* float* void*

// 空类型 (单独的) void 函数的返回类型 函数的参数 指针类型

// 整型在内存中是怎样存储
// int main(){
//     // 计算机中的整型有符号数有三种表示方法：原码、反码、补码  
//     // 计算机中的整型无符号数有三种表示方法：原码、反码、补码，但三者相同

//     // 正数
//     int a = 20;
//     // 00000000000000000000000000010100 正数 原、反、补相同
    
//     // 负数
//     int b = -10;
//     // 10000000000000000000000000001010 原码
//     // 11111111111111111111111111110101 反码
//     // 11111111111111111111111111110110 补码=反码+1 // FFFF FFF6
//     // 因此整数在内存中存放的是补码

//     // 字节的存储顺序：大端(字节序)、小端(字节序)
//     // 大端：数据的低位保存在内存的高地址，而数据的高位，保存在内存的低地址中；
//     // 小端：数据的低位保存在内存的低地址，而数据的高位，保存在内存的高地址中；
//     return 0;
// }

// <-----判断当前电脑的字节序---->
// int check_sys(){
//     // int a = 1;
//     // char* pa = (char*) &a;
//     // return *pa; // 返回1小端；返回0小端

//     int a = 1;
//     return *(char*)&a;
// }
// int main(){
//     // int a = 1;
//     // char* pa = (char*) &a; // 强行转换&a的类型为char*
//     // if(*pa == 1){
//     //     printf("小端\n");
//     // }
//     // else
//     // {
//     //     printf("大端\n");
//     // }
//     int ret = check_sys();
//     if(ret == 1){
//         printf("小端\n");
//     }
//     else
//     {
//         printf("大端\n");
//     }
//     return 0;
// }

// int main(){
//     char a = -1; // -1
//     // 11111111~打印成整型-就要整型提升，高位为符号位不变，补1
//     // 11111111111111111111111111111111
//     signed char b = -1; // -1
//     // 11111111
//     // 11111111111111111111111111111111
//     unsigned char c = -1; // 255
//     // 11111111 无符号数，高位不是符号位，补0
//     // 00000000000000000000000011111111 为255
//     printf("a=%d\nb=%d\nc=%d",a,b,c);
//     return 0;
// }

// int main(){
//     char a = -128;
//       // 00000000000000000000000010000000
//       // 11111111111111111111111101111111
//       // 11111111111111111111111110000000 - 补码
//     printf("%u",a); 
//     // 打印的是补码，即打印11111111111111111111111110000000 二进制为4294967168
//     return 0;
// }

// int main(){
//     char a = 128; 
//     // =127+1, char最大能存127，+1就成了-128 所以结果一样
//     char b = -128; 
//     printf("%u\n",a);  // 4294967168
//     printf("%u",b);    // 4294967168
// }


// int main(){
//     int a = -20;
//     unsigned int b = 10;
//     printf("%d",a+b);// -10
// }
// 10000000000000000000000000010100 -20 原码 
// 11111111111111111111111111101011     反码
// 11111111111111111111111111101100     补码

// 00000000000000000000000000001010  10 补码
// 11111111111111111111111111110110  结果=补码(-20)+补码(10)

// 11111111111111111111111111110101   结果的反码
// 11111111111111111111111111111010   结果的原码 -10
// int main(){
//     unsigned int i ;
//     for(i = 9; i>=0;i--){
//         printf("%u\n",i);
//     }
//     return 0;
// }

int main(){
    char a[1000];
    int i;
    for(i = 0; i<1000;i++){
        a[i] = -1 -i;
    }
    // -1、-2、-3………………-128 127 126…………3、2、1、0
    // strlen找的是0
    // 因此是-1、-2、-3………………-128 127 126…………3、2、1
    // 为255
    printf("%d\n",strlen(a)); // 255
    // printf("%d",a[255]);
}
