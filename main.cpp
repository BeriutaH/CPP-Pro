#include <iostream>
using namespace std;
#include <algorithm>  // 包含 std::for_each
#include <iterator>   // 包含 std::begin 和 std::end
#include <string>
#include <numeric>
#include <map>
#include "user.h"
#include "func.h"

int number = 9;

#define Day 7  // 宏常量
int MyClass1::private_static_var = 0;



int main() {
/*变量与常量*/
    //    // 常量和变量: 变量能变，常量不能变
        //    int a = 10;
        //    a = 12;
        //    printf("%d\n", a);  // 10
        //    double b = 3.1415926;
        //    b = 12.34;
        //    printf("%f\n", b);  // 3.141593
        //    double a2;
        //    printf("请输入数字，计算平方:");
        //    // 将终端输入的值保存到a2变量中
        //    scanf("%lf", &a2);
        //    // %.2lf保留小数点后两位
        //    printf("Result: %.2lf\n", a2 * a2);
        // cout << "一周有：" << Day << "天" << endl;
        // string sd = "握手";
        // cout << "中文：" << sd << endl;
    /*
        * 数字类型
            * 类型            表示范围
            char            -128~127
            short           -32768~32767
            int             -2147483648-2147483647
            unsigned char   0~255
            unsigned short  0~65535
            unsigned int    0~4294967295
            float           -3.4x10-38~3.4x10-38
            double          -1.7x10-308~1.7x10-308
    */
        //    // 整型变量-选择不同的类型
            //    int age1 = 33;
            //    short age2 = 22;
            //    char age3 = 44;
            //    printf("1: %d, 2: %d, 3: %d\n", age1, age2, age3);
            //    short year = 2024;
            //    char month = 4;
            //    char day = 23;
            //    printf("%d-%d-%d\n", year, month, day);

        //    // 整型变量的赋值
            //    int n1 = 10;  // 十进制
            //    int n2 = 0x0A;  // 十六进制
            //    printf("n1= %d, n2=%d\n", n1, n2);
            //    int a1 = 0x12345678;
            //    int a2 = 305419896;
            //    printf("a1= %d, a2=%d\n", a1, a2);

        // double：表示8个字节（范围很大）  float：表示4个字节（范围较小）
            //    // float类型的输入: float-point, fixed-point
            //    float f1;
            //    scanf("%f", &f1);
            //    // float输出：
            //    float f2;
            //    printf("%f\n", f2);  // 0.000000
            //    // float赋值后面要加f
            //    float s2 = 12.34f;
            //    printf("%f\n", s2);
            //    // double 输入,用%lf,long float-point 的缩写
            //    double d1;
            //    scanf("%lf", &d1);
            //    printf("double to %.2lf\n", d1);

/*变量与内存*/
    /*
        * 内存的表示
            0000 0000      物理内存的单元是“字节”
            0000 1010      一个字节8个位
            1111 1111      一个字节的表示范围：0000 0000 ~ 1111 1111 （0xFF）
            0000 0000      2个字节的表示范围：0000 0000 0000 0000  ~  1111 1111 1111 1111  （0x0000 ~ 0xFFFF）
            0000 0000
            0000 0000      4个字节的表示范围：0x00000000 ~ 0xFFFFFFFF
    */
    // 内存：单元室字节，每个字节存储8个bit，一台计算机的内存通常为几G
        // 1G = 1000 * 1000 * 1000B (B: bit,字节)
        // 1M = 1000 * 1000B
        // 1k = 1000B
        // 每个单元给以编号：00000000 ~ FFFFFFFF,内存单元的编号成为：内存地址 Address
    // 变量的大小：指的是它在内存中占几个字节
        // char类型：1个字节
        // short类型：2个字节
        // int类型：4个字节
        // 可以使用sizeof(int)获取当前的变量大小
            //    int a1 = 123;
            //    char a2 = 123;
            //    printf("%d\n", sizeof(a1));
            //    printf("%d\n", sizeof(a2));
    // 变量的地址：变量在内存中的位置，用&符号来获取地址
        //    int a1 = 0x1234562;
        //    printf("address a1 = %08X \n", &a1);  // 6FDB768C
        //    printf("address a1 = %d \n", &a1);  // 1876653708
    //  有符号跟无符号
        // 无符号 1100 0110 -> 198(十进制)  unsigned char a = 198
        // 有符号：最高位是符号位，采用补码表示  1100 0110 -> -58(十进制)  char b = -58
            //    unsigned char a = 198;
            //    char b = -58;

/* 数组 */
    // 定义一个有5个元素的数组
        // char arr[5];  // 数组的名称为arr，不初始化
        // char arr[5] = {90, 23, 34, 43, 44};  // 初始化全部
        // char arr[] = {90, 23, 34, 43, 44};
        // char arr[5] = {90, 92};  // 初始化一部分
        // printf("第一个同学的成绩 %d\n", arr[0]);
        // int n = 50;
        // arr[2] = arr[3] + n;
        // printf("%d\n", arr[2]);
        // 使用 lambda 函数和 std::for_each 打印数组元素，static_cast将char打印的ASCII 字符转化为数值的整数表示
        // std::for_each(std::begin(arr), std::end(arr), [](char num) { std::cout << static_cast<int>(num)<< " "; });
        // std::cout << std::endl;
    // 二维数组
        //char arr_two[5][3] = {
        //        {91, 23, 95},
        //        {81, 83, 35},
        //        {71, 63, 85},
        //};
        //printf("%d \n", arr_two[1][2]);

/* 字符 */
    // ASCII 字符
        // printf("%c, %c\n", 65, 'A');  // A, A
        // printf("%d\n", 'A');  // 65
    // 字符数组
        // char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};  // 普通数组一样初始化
        // char str[6] = "hello";  // 特殊初始化，注意字符个数不要超过前面的数组长度
        // printf("%s\n", str);
        // char str[] = "hello \n123 \nsay: \" Hi, counter. \"";  // 转义字符
        // printf("%s", str);
        // 字符串的结束符 '\0':从头开始一直到结束符0，中间的字符数，如果没有结束符，就不算一个字符串
            // char str[12] = "hello";
            // str[3] = 0;  // 强制把第四个字符变为0
            // printf("%s", str);  // hel
        // 字符串长度是统计有效字符的长度，也就是说，统计0的位置
            // char str[12] = "hello";
            // printf("%d", strlen(str));  // 引入 cstring 头文件，strlen函数

/* 字算术表达式 */
    //算数表达式：变量和常量用 + - * / % 组合起来的式子
        // int a = 10;
        // int b = 3;
        // printf("%d \n", a * b);
        // printf("%d \n", a + b);
        // printf("%d \n", a - b);
        // printf("%d \n", a / b);
        // printf("%d \n", a % b);
    // 除法运算
    // 整数相除：小数点部分会去除
        // int c = 8;
        // printf("%d \n", c / b);  // 2
    // 浮点型相除：
        // double d = 8;
        // double e = 3;
        // printf("%f \n", d / e);  // 2.666667
    // 赋值运算 =
        // int f = b + c;
        // char arr[2] = {1,2};
        // arr[0] = c + d;
        // printf("f = %d, arr[0] = %d \n", f, arr[0]);
    // 取出三位数的个位值，十位值，百位值
        // int num = 367;
        // int buf[3];
        // buf[2] = num % 10;  // 取余
        // num /= 10;  // 36
        // buf[1] = num % 10;
        // num /= 10;
        // buf[0] = num % 10;
        // printf("个位值: %d，十位值: %d，百位值: %d \n", buf[0], buf[1], buf[2]);
    // 关系表达式    真：1， 假：0
        // int l = 10;
        // double ll = 5;
        // printf("对比大小: l < ll %d \n", l < ll);
        // printf("对比大小: ll + 5 == l %d \n", ll + 5 == l);
    // 条件表达式  表达式 ? 如果表达式为真返回的值 : 如果表达式为假返回的值
        // printf("%d\n", ll < l ? 100: 200);
        // printf("%d\n", ll == l ? 100: 200);
    // 一个学生的成绩>=90就是A，如果小于<60 就是C，其余的为B
        //    int score;
        //    printf("请输入学生成绩:\n");
        //    scanf("%d", &score);
        //    char result = score >= 90 ? 'A' : (score < 60 ? 'C' : 'B');
        //    printf("当前学生成绩等级为: %c", result);
    // 逻辑表达式与逗号表达式: &&:逻辑与，||: 逻辑或， !:逻辑非
        // printf("%d\n", l && a < b );
        // printf("%d\n", a < b || l );
        // printf("%d\n", !a < b );
    // 逗号表达式,把里面的表达式全部执行一遍，取最后一个表达式的值
        // int nn = (8, !10, 4);
        // printf("%d\n", nn);  // 4
    // 类型转换与优先级
        // 表达式中发生的类型转化
            // 1.赋值符左右两侧的类型不相同
            // 2.不通类型的混合运算
                // unsigned char ab = 27;  // int -> unsigned char
                // int nl = 12.34;  // double -> int
                // double x = 92.12 + 5;
                // printf("ab = %d, nl = %d, x= %f\n", ab, nl, x);
            // 注意，上述的类型转化容易发生数据丢失
        // 类型的自动提升：表达式中，各种类型混合运算时，编译器会自动类型提升
            // char 与 short一起运算，会被提升为short
            // int 与 double一起运算，int会被自动提升为double
            // printf("%f\n", 10 + 0.5);  // int -> double
            // // 显示转化
            // int w1 = 3;
            // int w2 = 10;
            // double res = (double) w1 / w2;  // 显式转化为double
            // printf("%f\n", res);
       // 优先级：多个运算符构成的混合表达式，需要考虑优先级
            // int as = 10 + 11 * 12 /13 -14 * 15;
            // printf("%d\n", as);
            // 凡是不确定优先级的运算，统一用括号
                // a && (!b) || ((c + d > 100) && (c < 10))
            // 算数运算优先级
                // * / 优先级最高
            // 逻辑运算符优先级
                // !最高 && 次之 || 最后

/* 语句 */
    // if 语句
        //    if (表达式)
        //        代码执行
        //    else
        //        代码执行
            //int sc = 61;
            //if (sc > 60)
            //{
            //    printf("考试通过\n");
            //    printf("再干一件事情\n");
            //}
            //else
            //{
            //    printf("未通过考试\n");
            //    printf("继续复习\n");
            //}
    // else if 语句
        //int sc1 = 81;
        //if (sc1 < 60)
        //{
        //    printf("C\n");
        //    printf("考试不及格\n");
        //}
        //else if (sc1 < 80)
        //{
        //    printf("B\n");
        //    printf("继续努力\n");
        //}
        //else
        //{
        //    printf("A\n");
        //    printf("继续加油\n");
        //}
        // 用户在控制台输入一个数字，0表示周日，1-6表示周一-周六。其他打印bad input
            //int today;
            //printf("请输入数字:");
            //scanf("%d", &today);
            //if (today == 0 || today == 6) {
            //    printf("at home\n");
            //} else if (today >=1 && today <=5) {
            //    printf("at office\n");
            //} else {
            //    printf("bad input\n");
            //}
    // switch语句: 如果不加break，在执行完对应的语句之后，会贯穿执行后面的语句，case只是标签页分发，不是作比较
        //switch (表达式，其值必须是整型) {
        //    case 常量，必须是整型:
        //        break;
        //    default:默认标签,也可以放在最前面
        //        break;
        //}
            //int ch = 9;
            //switch (ch < 2) {
            //    case 1:
            //        printf("1\n");
            //        break;
            //    case 2:
            //        printf("2\n");
            //        break;
            //    default:
            //        printf("other");
            //        break;
            //}
    // for语句
        //int al[100];
        //for (int i=0; i<100; i++) {
        //    al[i] = i + 1;
        //}
        //printf("%d\n", al[99]);
        // 无限循环
            //for(;;) {
            //    printf("无限循环\n");
            //}
    // continue语句：跳过后面的语句，直接进入下一轮循环
        //int count = 0;
        //for (int i = 0; i < 100; ++i) {
        //    if (i % 2) {
        //        continue;
        //    }
        //    count ++;  // count += 1
        //    printf("i= %d\n", i);
        //}
        //printf("count= %d\n", count);

        //unsigned char bu[10] = {1,2,3,4, 5,6,7, 8};
        //for (int i = 0; i < 8; ++i) {
        //    printf("%02X ", bu[i]);  // %02X 会将一个整数以两位的十六进制大写形式输出，不足的地方用零填充
        //    if ((i + 1) % 4 == 0) {
        //        printf("\n");
        //    }
        //}
        // 求小于100的奇数的平方和
            //int sum = 0;
            //for (int i = 0; i < 100; i+=2) {
            //    sum += i * i;
            //}
            //printf("%d\n", sum);
    // while 语句：实现循环，形式更为简单
        //while (语句) {
        //    执行逻辑代码
        //}
        //char buff[101];
        //int i = 0;
        //while (i < 100) {
        //    buff[i] = i + 1;
        //    i++;
        //}
        //printf("%d\n", i);
    // while true循环，逻辑内部break
        //while (1) {
        //    if (i >= 100) {
        //        break;
        //    }
        //    i++;
        //}
        //printf("%d\n", i);
        // 用户从控制台输入一系列正整数，当用户输入为0时，表示结束，存储这些数，求出它们的和
            //int sum = 0;  // 要注意在cpp中，局部变量（如 sum）在未初始化的情况下其值是未定义的，这意味着它可能包含任何值，这取决于它在内存中的位置，所以一开始尽量定义好原始值
            //int userInput;
            //while (1) {
            //    printf("请输入数字:");
            //    scanf("%d", &userInput);
            //    if (userInput == 0) {
            //        break;
            //    }
            //    sum += userInput;
            //}
            //printf("最终的数字总和: %d\n", sum);
        // 用户输入一个整数（十进制），判断他有几位数
            //int user_input;
            //while (1) {
            //    printf("请输入数字:");
            //    scanf("%d", &user_input);
            //    if (userInput == 0) {
            //        break;
            //    }
            //    // 将整数转换为字符串
            //    std::string num_str = std::to_string(user_input);
            //    // 计算字符串长度
            //    int length = num_str.length();
            //    printf("数字长度: %d\n", length);
            //}
        // do ... while；当必须要执行一次的循环时，可以使用
            //do {
            //    逻辑代码
            //} while (expr) expr为真时，继续下一轮循环，expr为假时，跳出循环，只是在判断时，先执行一遍do内的逻辑代码
     // goto
        // goto FLAG: 太强大，不建议使用，直接会跳转到指定的标签

/* 函数 */
    // 函数的形式
        //返回值类型 函数名称(参数) {
        //    逻辑代码函数体
        //    return 返回值;
        //}
            //int ret = sum_fn(10, 20);
            //printf("res: %d\n", ret);
            //printf("%.3f\n", area(2.1, 5.2));
        // 没有返回值的函数
            //void 函数名称(参数) {
            //    逻辑代码函数体
            //    return;
            //}
            //pr();
        // 函数的传值
            //int nm = 10;
            //printf("nm地址: %08X \n", &nm);
            //test_num(nm);
            //printf("nm = %d\n", nm);  // 10
        // 全局变量
            //printf("%d\n", number);
            //number = 10;
            //printf("%d\n", number);
        // 函数参数传递数组
            //int data[7] = {9,3,4,4,5,6,7};
            //int size = sizeof(data) / sizeof(data[0]);
            //double rett = eq_num(data, size);
            //printf("%.2f\n", rett);
    // 内联函数: 以空间换时间，类内部的函数会自动变为内联函数
        // 关键字 inline 写在函数前面
            // test03();
            // test04();
        // c++编译不会将以下函数进行内联编译
            // 1. 不能存在任何形式的循环语句
            // 2. 不能存在过多的条件判断语句
            // 3. 函数体不能过于庞大
            // 4. 不能对函数进行取址操作
    // 函数的默认参数
        //// int add(int a, int b = 20, int c = 30)
        //// 从某个位置已经有了默认参数，那么从这个位置往后，从左到右就必须要有默认值
        //// int add(int a, int b = 20, int c) 报错
        //cout << add(10, 30) << endl;
        //// 声明和实现只能有一个有默认参数，一般都放在声明中(头文件)
    // 函数占位参数
        // void f2(int a, int)
        // 占位参数还可以有默认值
        // void f2(int a, int = 10)
    // 函数重载
        // 函数名可以相同，提高复用性
        // 函数重载满足条件:
            // 同一个作用域下
            // 函数名称相同
            // 函数参数 类型不同 或者 个数不同 或者 顺序不同
            // 函数的返回值不可以作为函数重载的条件
            // 当有相同函数名，函数参数是默认值时，需要确定在调用的时候，默认值的传参
                //    void f3(int a, int b = 10)
                //    void f3(int a, int64_t b = 10)
                //    f3(23);  // 报错，当缺少第二个值时，编译器匹配到了两个函数
// extern C
    // 在cpp文件中链接c文件，调用c中的函数
        // 调用的文件中导入  #include "c文件名.h"
        // c文件名.中加上6行代码
            //#ifdef __cplusplus  如果c++编译器在编译这个文件时，会有__cplusplus宏，表示下面的代码都按照C语言的方式链接
            //extern "C" {
            //#endif
            //#include <stdio.h>
            //void show();  这里写函数声明
            //#ifdef __cplusplus
            //#endif

/* 指针 */
    //char sst[] = "wjwojfowd为cmlkdcm";
    //printf("%d, %s, %p\n", sizeof(sst), sst, sst);
    //int a = 12;
    //int* pa = &a;  // int* 称为指针类型，pa为指针类型的变量，简称指针
    //printf("a本身的值: %d, a本身的地址:%p, pa的值为a的地址: %p, pa本身还有他自己的地址: %p\n", a, &a, pa, &pa);
    //*pa = 23;  // 通过内存地址修改本身的内容
    //printf("a本身的值: %d, a本身的地址:%p, pa的值为a的地址: %p, pa本身还有他自己的地址: %p\n", a, &a, pa, &pa);
    // 指针与数组
        // 在C/C++，数组名就是地址，也就是数组在内存中的位置，他表示第一个元素的地址
            //int arr[4] = {1, 5, 8, 10};
            //int* p = arr;  // 不用&arr,相当于 int* p = &arr[0];
            //printf("arr地址: %p, 等于 %p\n", p, &arr[0]);  // arr地址: 0x16cf0f660, 等于 0x16cf0f660
        // 指针的加减法，表示的是元素的加减，不是具体内容的加减
            //p += 1;  // 这里其实编译器给优化了，其实内部实际是 int 类型 p+4 ， char 类型 p+1, double 类型 p+8
            //printf("%d，地址: %p\n", *p, p);  // 5，地址: 0x16cf0f664 获取的是数组下标为2的值,地址后移了4个字节
        // 给数组元素赋值
            //arr[3] = 12;
            //*(arr + 3) = 13;
            //int* p3 = arr + 3;
            //*p3 = 14;
            //printf("%d\n", arr[3]);  // 14
        // 把p可以当成数组使用
            //p[1] = 33;  // 因为p是数组的0号元素，所以p[0] == arr[0], p[1] == arr[1],依次类推
            //printf("%d\n", arr[1]);  // 33
            //int* p4 = &arr[2];  // 因为p4是数组的3号元素，所以p[0] == arr[2], p[1] == arr[3],依次类推
            //p4[0] = 99;  //  *p4 = 100;  相等
            //p4[1] = 98;
            //printf("%d, %d\n", arr[2], arr[3]);
            //int a = 10;
            //int* p2 = &a;
            //p2[0] = 11;  // 其实就是长度为1的数组
            //printf("%d\n", a);
        // 数组的遍历
            //int arr[] = {3,4,6,7};
            //// 第一种方法
            //for (int i = 0; i < 4; ++i) {
            //    printf("%d\n", arr[i]);
            //}
            //printf("--------------\n");
            //// 第二种方法
            //for (int* p = arr; p < arr + 4; p++) {  // arr + 4 表示arr往后移动4个位置
            //    printf("%d\n", *p);
            //}
            //int arr[3] = {1,2,3};
            //arr[3] = 10;  // 这样虽然不会报错，但是修改了别的内存的值，如果牵扯到别的变量，就会发生不可预测的错误
            //printf("%d\n", arr[3]);
            //char* p = nullptr;
            //p = (char *)malloc(1024);
            //p = rechar(p);
            //printf("%p",p);
            // 冒泡排序
                //// 排序的总论述，是元素个数 - 1
                //// 每轮对比次数 = 元素的个数 - 排序轮数 - 1
                //int arr[] = { 8, 2, 4, 0, 5 ,7 ,1, 3, 9};
                //int size = sizeof(arr) / sizeof(arr[0]);
                //int num = size - 1;
                //// 排序的总论述，是元素个数 - 1
                //for (int i = 0; i < num; ++i) {
                //    // 每轮对比次数 = 元素的个数 - 排序轮数 - 1
                //    for (int j = 0; j < num - i; j++) {
                //        if (arr[j] > arr[j+1]) {
                //            int max_num = arr[j];
                //            arr[j] = arr[j+1];
                //            arr[j+1] = max_num;
                //        }
                //    }
                //}
                //cout << "排序后" << endl;
                //for (int i = 0; i < size; ++i) {
                //    cout << arr[i] << " ";
                //}
                //cout << endl;

    // 指针作为函数的参数
        //int s2 = 3;
        //tt(&s2);
        //int arr[] = {3, 23};
        //printf("%d\n", 0[arr]);
        //int nums[] = {34, 54, 67, 67, 78, 1, 23, 44, 5,76, 8};
        //int max, min;
        //int size = sizeof nums / sizeof *nums;
        //find_max_min(nums, size, &max, &min);
        //printf("最大值: %d, 最小值: %d", max, min);
    // 定义一个字典，键为字符串，值也为字符串
        //std::map<std::string, std::string> myDict;
        //// 将 label 键的值设为 "中文"
        //myDict["label"] = "中文";
        //// 取值并判断是否等于 "中文"
        //std::string value = myDict["label"];
        //if (value == "中文") {
        //    std::cout << "The value is equal." << std::endl;
        //} else {
        //    std::cout << "The value is not equal." << std::endl;
        //}
    // const 指针
        // 加上const修饰，只可读
        //int a = 10;
        //const int* p = &a;
        //int b = *p;
        //printf("%d", b);  // 10
        //// *p = 11;  // 报错: read-only variable is not assignable
/* struct 结构体 */
    // 定义User结构体，在user.h文件中，然后头文件使用
        // User user1 = {2315, "beriuta", "15023453213"};
        //user1.id = 1234;
        //strcpy(user1.name, "小鬼");  // strcpy函数用于字符串的拷贝
        //strcpy(user1.phone, "13323123456");
        // printf("%d, %s", user1.id, user1.name);
    // 批量化声明
        //User users[4] = {
        //        {2315, "beriuta", "15023453213"},
        //        {2615, "小鬼", "15023453314"},
        //        {1315, "点点", "15023253213"},
        //};
    // 结构体的指针访问
        //User user = {2315, "beriuta", "15023453213"};
        //User* p = &user;
        //printf("user直接获取值===>   用户id: %d, 用户名: %s, 用户手机号: %s\n", user.id, user.name, user.phone);
        //printf("地址操作取值=====>   用户id: %d, 用户名: %s, 用户手机号: %s\n", p->id, p->name, p->phone);

/* 动态分配内存 malloc(申请内存) free(释放内存) */
    //// malloc函数：参数size指定要申请的内存空间的大小，返回void*，指向这一块内存地址，这个内存区域为 ”堆“，Heap，动态分配的内部是记录首地址跟结尾的，并且保证内存不会重叠，所以释放的时候，只需要传递首地址就好
    //char* p = (char*)malloc(8);  // 申请8个字节
    //    for (int i = 0; i < 8 ; i++) {
    //        p[i] = i + 1;
    //    }
    //    // 释放内存
    //    printf("%s", p);
    //    free(p);  // 如果提前释放内存，这时候这个指针已经变成野指针了，可能就会打印出很奇怪的东西
    ////    printf("%s", p);

/* C++核心编程 斧头帮第二阶段 */
    // 内存区分模型
    // 代码区: 存放函数体的二进制带啊，由操作系统进行管理的
        // 不在全局区: 局部变量，const修饰的局部变量（局部常量）
        // 在全局区: 全局变量， 静态变量，static关键字，常量 ==> const修饰的全局变量（全局常量）、字符串常量
        // 栈区: 由编译器自动分配释放，存放函数的参数值，局部变量等
            // 注意：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
            // 第一次可以打印正确的数字，是因为编译器保留
            // 利用new关键字，可以将数据开辟到堆区
                // int* p = new int(10);  //  在堆上分配一个int并初始化为10，p存储在栈上
                // int* arr = new int[10];  // 在堆上创建一个10个连续内存的数组，返回首地址的指针
                // delete[] arr; //释放数组的时候要加 []
                // cout << "地址是: " << p << "   值是: " << *p << endl;  // 地址是: 0x6000027c8040   值是: 10
                // 利用关键字delete释放
                // delete p;  // p 是一个指针，它本身存储在栈上， 释放堆上的内存，但p的值不变
                // cout << "地址是: " << p << "   值是: " << *p << endl;  // 地址是: 0x6000027c8040   值是: 947486784
        // 引用: 给变量起别名
            // 语法: 数据类型 &别名 = 原名
                // int a = 10;
                // int& b = a;
                // b = 20;
                // cout << "a值是: " << a << endl;  // 20
            // 注意事项: 引用必须要初始化，在初始化之后不可修改
                // // int& b;  // 错误，引用必须要初始化
                // int c = 12;
                // int d = 12;
                // int& b = c;
                // // int& b = d;  // 报错，初始化之后不可修改
           // 引用做函数的返回值
                // 不要返回局部变量的引用
                // 函数的调用可以作为左值
                    // int& ref = test01();
                    // int& ref2 = test02();
                    // cout << "ref = " << ref << endl;
                    // cout << "ref = " << ref2 << endl;
    // 全局区: 存放全局变量和静态变量以及常量
    // 栈区: 由比那一期自动分配释放，存放函数的参数值，局部变量等
    // 堆区: 由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

/* 面向对象 */

    // 类特性: 封装、继承、多态
        // 上面是行为方法，下面是属性
        // 公共权限 public    成员类内可以访问,类外可以访问
        // 保护权限 protected 成员类内可以访问,类外不可以访问,子类可以访问父类中的保护内容
        // 私有权限 private   成员类内可以访问,类外不可以访问,子类不可以访问父类的私有内容

    // struct 跟 class唯一的区别在于: 默认访问权限不同
        // struct 默认权限为公有
        // class 默认权限为私有

    // 成员属性设置为私有
        // 优点
            // 将所有成员属性设置为私有，可做自己控制读写权限
            // 对于写权限，可以检测数据的有效性

    // 对象的初始化和清理
        //  对象的初始化和清理是非常重要的安全问题
            //  对象或者变量没有初始化状态，对其使用的后果是未知的
            //  同样使用完一个对象或变量，没有及时清理，也会造成一定的安全问题
        // 使用构造函数或者析构函数解决上述问题，
            // 这两个函数会被比那一期自动调用，完成对象初始化和清理工作，如果不提供构造函数和析构函数，编译器会提供编译器的构造函数和析构函数是空实现
            // 构造函数:
                // 主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
                    // 语法: 类名() {}
                    // 1. 构造函数，没有返回值不写void
                    // 2. 函数名称与类名相同
                    // 3. 构造函数可以有参数，因此可以发生重载
                    // 4. 程序在调用对象时会自动调用构造，无需手动，并且只会调用一次
                       //  Person p1;  // 调用构造函数
                // 分类:
                    // 有参构造和无参构造
                    // 普通构造和拷贝构造
                // 调用方式:
                    // 括号法
                        // Person p1;  // 无参构造函数调用
                        // Person p2(10);  // 有参构造函数调用
                        // Person p3(p2);  // 拷贝
                        // 注意: Person p1();  会被认为是一个函数的声明，所以创建对象时不要单独加()
                    // 显示法
                        // Person p2 = Person(10);  // 有参构造函数调用
                        // Person p3 = Person(p2);  // 拷贝
                        // 注意: Person(10); 是一个匿名对象，当执行结束后，系统会立即回收
                    // 隐式转换法
                        // Person p4 = 10;  // 相当于写了 Person p4 = Person(10)
                        // Person p5 = p4;  // 拷贝
        // 析构函数: 主要作用于对象销毁前系统自动调用，执行一些清理工作
            // 语法: ~类名() {}
            // 1. 析构函数，没有返回值不写void
            // 2. 函数名称与类名相同前面加上 ~
            // 3. 构造函数不可以有参数，因此不可以发生重载
            // 4. 程序在调用对象时会自动调用构造，无需手动，并且只会调用一次
                // Person p1;  // 调用析构函数
        // 拷贝构造函数调用时机
            // 1. 是用一个已经创建完毕的对象来初始化一个新对象
                // Person p1(20);
                // Person p2(p1);
            // 2. 值传递的方式给函数参数传值
                // 定义一个值拷贝的参数函数
                    // void pp(Person p) {
                    // }
                    // Person p;
                    // pp(p);
            // 3 值方式返回局部对象(禁用 NRVO)情况下会出现
                // Person pp() {
                //     Person p1;
                //     return p1;
                // }
                // Person p = pp();
                // cout << "p的地址: " << (int*)&p << endl;
        // 构造函数调用规则
            // 默认情况下，一个类的创建，C++编译器至少会给这个类添加3个函数
                // 默认构造函数（无参，函数体为空）
                // 默认析构函数（无参，函数体为空）
                // 默认拷贝构造函数，对属性进行值拷贝
            // 如果自己提供有参构造函数，编译器将不会自动提供无参构造函数，但是还会提供析构跟拷贝函数
            // 如果自己提供了拷贝构造函数，那么其他的构造函数将不会提供（有参跟无参）
        // 深拷贝与浅拷贝
            // 浅拷贝带来的问题就是堆区的内存重复释放,等号赋值操作叫浅拷贝
                // Person p1(18, 180);
                // Person p2(p1);
        // 初始化列表
            // Person(int a, int h): p_age(a), height(new int(h)) {}
        // 类对象作为类成员
            // 当其他对象作为本类的成员，构造时候先构造类对象，再构造自身
                 // Boon b("B名称", "A名称");
                // cout << "A.a_name: "  << b.aoon.a_name  << endl;
                // cout << "b.b_name: "  << b.b_name  << endl;
            // 析构的顺序跟构造相反
        // explicit 关键字: 防止利用隐式法创建对象
        // 静态成员:
            // 注意: 关键字 static, 使用时，类外要先初始化，私有权限(private)访问不到
            // 静态成员变量
                // 所有对象共享同一份数据
                // 在编译阶段分配内存
                // 类内声明，类外初始化
                // 两种访问方式：
                    // 1.通过对象进行访问
                        // Student s;
                        // s.s_age = 28;
                        // cout << "学生年龄:" << s.s_age << endl;
                    // 2.通过类名进行访问
                         // Student::s_age = 10;
                         // cout << "学生年龄:" << Student::s_age << endl;
            // 静态成员函数
                // 所有对象共享同一个函数
                // 静态成员函数只能访问静态成员变量
            // 单例模式:
            // 是一种常用的软件设计模式，在它的核心结构中只包含一个被称为单例的特殊类，通过单例模式可以保证系统中一个类只有一个实例而且该实例易于外界访问，从而方便实例个数的控制并节约系统资源
            // 创建方式：
            // 1. 将默认构造函数私有化
                // private:
                    // std::vector<Student> students;
                    // StudentManager() {}
                // public:
                    // static StudentManager* single_student_mg;
            // 2. 只要拿到一个对象的指针既可，这个指针可以指向唯一的对象，这个对象在堆上面
                // StudentManager* StudentManager::single_student_mg = new StudentManager;
            // 3. 将唯一的指针私有化后，提供公共的接口，变为只读状态
    // 访问和修改私有静态变量，通过公有静态函数
        // 在类的外部定义并初始化静态变量
        // 私有在外面也是访问不到的，只能初始化
    // 成员变量跟成员函数
        // 实例化空对象(无函数，变量)，c++编译器会给每个空对象分配一个字节的空间，是为了区分空对象占用内存的位置
        // 每个空对象也应该有一个独一无二的内存地址
        // 非静态成员变量，属于类的对象
        // 静态成员变量，非静态成员函数，静态成员函数，不属于类的对象上
    // this指针
        // this指针指向被调用的成员函数所属的对象
            // 当形参和成员变量同名时，可用this指针来区分
            // 在类的非静态成员函数中返回对象本身，可使用return *this，可使用链式调用的方法
        // 空指针访问成员函数
            // c++中空指针也可以调用成员函数，需要注意有没有用到this指针，如果使用到，则会报错
                // P* p2 = nullptr;
                // p2 -> show_name();
                // p2 -> show_age();
    // const修饰
        // 常函数
            // 成员函数后加const，称这个函数为常函数
            // 常函数不可以修改成员属性, 但是如果属性前加了 mutable关键字，就可以被修改
            // 成员属性声明时加关键字mutable后，在常函数中依然可以修改
                // Animal a;
                // cout << a.a_age << endl;  // 5249936
                // cout << a.a_num << endl;  // 1
                // 指针的指向是不可以修改的，指针的指向的值如果也不允许修改，可以加const
        // 常对象
            // 声明对象前加const称该对象为常对象
                // 创建const必须要有默认构造函数来初始化，要么所有的成员都有默认初始化器，要么提供一个默认构造函数
                // const Animal a;
                // // a.a_num = 100;  // 报错
                // a.a_age = 23;
                // cout << a.a_num << " | " << a.a_age << endl;
            // 常对象只能调用常函数
                // a.show_const();
                // // a.show_all();  // 报错
    // 友元
        // 关键字为 friend
        // 友元的三种实现
            // 全局函数做友元: 将需要调用私有成员的全局函数签名 加上 friend 关键字添加到类内
                // Building* b = new Building;
                // good_friend(b);
            // 类做友元
                // Visit v;
                // v.visit();
            // 成员函数做友元: 需要注意一点，类内部需要先声明再定义
                 // Visit v;
                 // v.visit2();
    // 运算符重载
        // 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
            // 加号运算符重载
                // 1. 成员函数重载+号: 本质调用 Per p3 = p1.operator+(p2)
                    // Per p1;
                    // p1.p_id = 12;
                    // p1.p_age = 22;
                    // Per p2;
                    // p2.p_age = 30;
                    // p2.p_id = 11;
                    // Per p3 = p1 + p2;  // 在没有写运算重载时，会报错
                    // cout << "P3 id = " << p3.p_id << " P3 age = " << p3.p_age << endl;
                // 2. 全局函数重载+号: 例子一样，只是把重载函数写成了全局  本质调用 Per p3 = operator+(p1, p2)
            // 注意：
                // 对于内置的数据类型的表达式的运算符是不可能改变的
                // 不要滥用运算重载
            // 左移运算符重载 <<
                // Per p1;
                // p1.p_id = 12;
                // p1.p_age = 22;
                // cout << p1 << endl;
            // 递增运算符重载 ++
                // int a = 10;
                // cout << ++a << endl;  // 11 先加再输出
                // cout << a << endl;  // 11
                // int b = 10;
                // cout << b++ << endl;  // 10 先输出，再加
                // cout << b << endl; // 11
                // 注意左值右值的区分，左值是具体的变量，右值是临时变量（函数的返回值，直接赋值的数字）
                // Point p_int;
                // cout << ++(++p_int) << endl;
                // cout << p_int++ << endl;
                // cout << p_int << endl;
            // 赋值运算符重载
                // c++编译器至少给一个类添加4个函数
                    // 默认构造函数（无参，函数体为空）
                    // 默认析构函数（无参，函数体为空）
                    // 默认拷贝函数，对属性进行值拷贝
                    // 赋值运算符 operator= ，对属性进行值拷贝（对于等号赋值的浅拷贝进行重载）
                // 关于深拷贝问题
                    // PersonNew p1(18);
                    // PersonNew p2(20);
                    // PersonNew p3(20);
                    // p3 = p2 = p1;  // 赋值操作
                    // PersonNew p4 = p3;  // 拷贝操作
                    // cout << "P1年龄: " << *p1.p_age << endl;
                    // cout << "P2年龄: " << *p2.p_age << endl;
                    // cout << "P3年龄: " << *p3.p_age << endl;
                    // cout << "P4年龄: " << *p4.p_age << endl;
            // 关系运算符重载 == !=
                // PersonNewTwo p12("tom", 12);
                // PersonNewTwo p13("tom", 13);
                // if (p12 == p13) {
                //     cout << "两个对象相同" << endl;
                // } else {
                //     cout << "两个对象不相同" << endl;
                // }
                // if (p12 != p13) {
                //     cout << "两个对象不相同" << endl;
                // } else {
                //     cout << "两个对象相同" << endl;
                // }
            // 函数调用运算符重载 () 仿函数
                // MyAdd add;
                // int ret = add(1,3);
                // cout << "结果: " << ret << endl;
                // // 匿名对象调用
                // cout << "结果: " << MyAdd()(5, 3) << endl;
            // 指针运算符重载 智能指针: 托管new出来的对象，不用再写delete
            SmartPoint sp(new PersonThree);
            sp->show_str();
            (*sp).show_str();



    return 0;
}


