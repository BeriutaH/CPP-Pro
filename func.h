//
// Created by Beriuta on 2024/5/15.
//

#ifndef CPPPR_FUNC_H
#define CPPPR_FUNC_H
//#include <iostream>
//#include <climits>
//#include <cstring>

/* 当前文件放置课程涉及到的所有函数 */

int sum_fn(int a, int b) {
    int result = a + b;
    return result;
}

double area(double r, double h) {
    double ret = 3.14 * r * r * h;
    return ret;
}

void pr() {
    printf("没有返回值的函数\n");
}

void test_num(int &a) {
    a += 1;
}

double eq_num(int arr[], int size) {
    // 参数为数组的时候，必须要把数组的大小一起传进来
    printf("size: %d\n", size);
    int all_num = 0;
    for (int i = 0; i < size; ++i) {
        all_num += arr[i];
    }
    return all_num;
}

void tt(int* p) {
    printf("使用指针读取数据: %d\n", *p);
    *p += 1;
    printf("使用指针修改内存后再读取数据: %d\n", *p);
}

double f(int n){
    double sum = 1.0;
    int m = 4,flag = 0;
    for(int i=1;i < n;i++){
        if (flag){
            printf("执行%f+= 1/ %d\n", sum, m);
            sum += 1.0 / m;
        }else{
            printf("执行%f-= 1/ %d\n", sum, m);
            sum -= 1.0 /m;
        }
        flag = !flag;
        m += 3;
    }
    return sum;
}

double f2(int n){
    int fenmu = 1;
    double s =0, f =1;
    for (int t =1; t <=20; t ++) {
        printf("s = %f, f = %f, fenmu=%d，t=%d\n", s, f, fenmu, t);
        s = s + f / fenmu;
        f = -f;
        fenmu += 3;
    }
    return s;
}
// 判断一个list里面的最大值跟最小值
void find_max_min(const int* p, int size, int* max, int* min) {
    if (size <= 0) {
        *max = INT_MAX;
        *min = INT_MIN;
        return;
    }
    int _max = p[0];
    int _min = p[0];
    for (int i = 1; i < size ; ++i) {
        if (_max < p[i]) {
            _max = p[i];
        }
        if (_min > p[i]) {
            _min = p[i];
        }
    }
    *max = _max;
    *min = _min;
}
char * rechar(char * p){
    strcpy(p,(char *)"Hello\0");
    return p;
}

void test01() {
    int a  = 2;  // 局部变量存放在四区中
}

int& test02() {
    static int a  = 20;  // 存放在全局变量，有系统释放
    return a;
}

// 宏缺陷
// 1. 需要加括号保证运算的完整
#define MYADD(x, y) ((x) + (y))
void test03() {
    int ret = MYADD(10, 20) * 20;
    cout << "ret = " << ret << endl;
}
// 2. 即使加了括号，有些情况依然与预期效果不符
#define MYCOMPARE(a, b) (((a) < (b))?(a):(b))

// 内联函数
inline int my_compare(int a, int b) {return a < b ? a : b;}

void test04() {
    int a = 10;
    int b = 20;
//    int ret = MYCOMPARE(++a, b);  // 预期效果11，实际效果12  (((++a) < (b))?(++a):(b))
    int ret = my_compare(++a, b);  // 11
    cout << "ret = " << ret << endl;
}

// 函数的默认参数: 从某个位置已经有了默认参数，那么从这个位置往后，从左到右就必须要有默认值
int add(int a, int b = 20, int c = 30) {
    return a + b + c;
}

void f2(int a, int) {
    cout << a << endl;
}

void f3(int a, int b = 10) {
    cout << a << " , " << b << endl;
}
void f3(int a, int64_t b = 10) {
    cout << a << " , " << b << endl;
}


class Person {
public:
    //  无参
    Person() {
        cout << "Person 无参默认构造函数调用" << endl;
    }
    //  有参
//    Person(int age, int h) {
//        p_age = age;
//        height = new int(h);  // 在堆内开辟一块新内存
//        cout << "Person 有参构造函数调用" << endl;
//    }
        Person(int a, int h): p_age(a), height(new int(h)) {

        }
    //  拷贝构造函数
    Person(const Person& p) {
        p_age = p.p_age;
        // 编译器实现的是浅拷贝，而像内存这种的，需要深拷贝
        // height = p.height;
        height = new int(*p.height);
        cout << "Person 拷贝构造函数调用" << endl;
    }
    ~Person() {
        // 将堆区开辟数据做释放操作
        if (height != nullptr) {
            delete height;
            height = nullptr;
        }
        cout << "Person 析构函数调用" << endl;
    }
    int p_age;
    int* height; // 身高
};

class Aoon {
public:
    Aoon(string name) {
        a_name = name;
        cout << "执行A" << endl;
    }
    string a_name;
};

class Boon {
public:
    Boon(string name, string a_name): b_name(name), aoon(a_name) {
        cout << "执行B" << endl;
    }

    Aoon aoon;
    string b_name;
};
class MyClass1 {
public:
    // 公有静态变量
    static int public_static_var;

    // 公有静态函数，用于访问私有静态变量
    static void set_private_static_var(int value) {
        private_static_var = value;
    }

    static int get_private_static_var() {
        return private_static_var;
    }

private:
    // 私有静态变量
    static int private_static_var;
};

class P {
public:
    void show_name() {
        cout << "P Class Name" << endl;
    }
    void show_age() {
        cout << this -> p_age << endl;
    }
    int p_age;
};

class Animal {
public:
//    void show_all() const {
//        a_age = 12;
////        a_num = 23; // 报错
//    }
    int a_num;
    mutable int a_age;
};
class Building;
class Visit {
public:
//    Visit() {
//        building = new Building;
//    }
    // 先声明，然后类外定义
    Visit();
    void visit2();
    void visit();
    Building* building;
};

// 建筑物类
class Building {
//    friend class Visit;
    friend void Visit::visit2();
    friend void good_friend(Building* building);
public:
//    Building() {
//        b_bed_room = "卧室";
//        b_sitting_room = "客厅";
//    }
    Building();
    string b_sitting_room;
private:
    string b_bed_room;
};

// 全局函数操控Building
void good_friend(Building* building) {
    cout << "好朋友正在访问: " << building->b_sitting_room << endl;
    // 当没有将这个全局函数，写入这个类中并标注关键字friend，是无法访问私有变量的
    cout << "好朋友正在访问: " << building->b_bed_room << endl;
}

// Building的构造函数
Building::Building() {
    b_bed_room = "卧室";
    b_sitting_room = "客厅";
}

// Visit的构造函数
Visit::Visit() {
    building = new Building;
}

// 当没有将这个成员函数，写入这个Building类中并标注关键字friend，是无法访问私有变量的
void Visit::visit2() {
    cout << "好朋友正在访问: " << building->b_sitting_room << endl;
    cout << "好朋友正在访问: " << building->b_bed_room << endl;
}

void Visit::visit() {
    cout << "好朋友正在访问: " << building->b_sitting_room << endl;
//        cout << "好朋友正在访问: " << building->b_bed_room << endl;  // 报错，无法访问
}

class Per {
public:
    // 成员函数重载+号
//    Per operator+ (Per &p) {
//        Per temp;
//        temp.p_id = this->p_id + p.p_id;
//        temp.p_age = this->p_age + p.p_age;
//        return temp;
//    }
    int p_id;
    int p_age;
};

//// 全局函数重载+号
//Per operator+ (Per &p1, Per &p2) {
//    Per temp;
//    temp.p_age = p1.p_age + p2.p_age;
//    temp.p_id = p1.p_id + p2.p_id;
//    return temp;
//}

//// 全局函数重载左移运算符
//ostream& operator<< (ostream& c, Per& p) {
//    c << "P id = " << p.p_id << " P age = " << p.p_age;
//    return c;
//}

class Point {
    friend ostream& operator<< (ostream& c, const Point& p);
public:
    Point() {
        p_num = 0;
    }
    // 前置递增,返回引用是在原本的数据进行操作
    Point& operator++() {
        cout << "执行前置递增" << endl;
        p_num++;
        return *this;
    }
    // 后置递增,int为占位符
    Point operator++(int) {
        cout << "执行后置递增" << endl;
        Point temp = *this;
        p_num++;
        return temp;
    }
private:
    int p_num;
};

// Point& 只能绑定到左值，但是const Point& 可以绑定到右值，右值就是临时变量
ostream& operator<< (ostream& c, const Point& p) {
    c << "P num = " << p.p_num;
    return c;
}

class PersonNew {
public:
    PersonNew(int age): p_age(new int(age)) {}

    // 拷贝构造函数
    PersonNew(const PersonNew& p) : p_age(new int(*p.p_age)) {}

    PersonNew& operator=(const PersonNew& p) {
        // 判断是否是自赋值
        if (this != &p) {
            // 先分配新的内存 new int(*p.p_age)，确保成功后才替换旧的内存
//            int* new_p_age = new int(*p.p_age);
            // 先将堆区的释放，再重新赋值
            delete p_age;
            // 将赋值的值获取到再重新分配堆区内存
            p_age = new int(*p.p_age);
        }
        return *this;
    }

    // 析构函数
    ~PersonNew() {
        delete p_age;
    }
    int* p_age;
};

class PersonNewTwo {
public:
    PersonNewTwo(string name, int age): p_name(std::move(name)), p_age(age) {}

    // 重载运算符 ==
    bool operator==(const PersonNewTwo& p) const {
        return (this->p_age == p.p_age && this->p_name == p.p_name);
    }
    // 重载运算符 !=
    bool operator!=(const PersonNewTwo& p) const {
        return !(*this == p);
    }

    string p_name;
    int p_age;
};

class MyAdd {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

class PersonThree {
public:
    PersonThree() {
        cout << "PersonThree构造函数" << endl;
    };

    void show_str() {
        cout << "执行打印方法" << endl;
    }
    ~PersonThree() {
        cout << "PersonThree析构函数" << endl;
    }
};
// 针对PersonThree的智能指针
class SmartPoint {
public:
    explicit SmartPoint(PersonThree* person) {
        cout << "SmartPoint构造函数" << endl;
        s_person = person;
    }
    PersonThree* operator->() const {
        return this->s_person;
    }
    PersonThree& operator*() const {
        return *this->s_person;
    }
    ~SmartPoint() {
        cout << "SmartPoint析构函数" << endl;
        if (this->s_person != nullptr) {
            delete this->s_person;
            this->s_person = nullptr;
        }
    }
    PersonThree* s_person;
};

class BasePage {
public:
    void header() {
        cout << "统一的头部" << endl;
    }
    void left() {
        cout << "统一的左部" << endl;
    }
};
class Go: public BasePage {
public:
    void content() {
        cout << "Go 模块的内容" << endl;
    }
};
class Python: public BasePage {
public:
    void content() {
        cout << "Python 模块的内容" << endl;
    }
};
class Cpp: public BasePage {
public:
    void content() {
        cout << "Cpp 模块的内容" << endl;
    }
};

class Base {
public:
    int b_a;
protected:
    int b_b;
private:
    int b_c;
};
// 公共继承
class SonOne: public Base {
public:
    void foo() {
        b_a = 10;
        b_b = 12;   // 类外访问不到
        // b_c = 23;  // 无法访问
    }
};
// 保护继承
class SonTwo: protected Base {
public:
    void foo() {
        b_a = 100;  // 类外访问不到,父类公共成员也变为保护权限
        b_b = 120;  // 类外访问不到
        // b_c = 23;  // 无法访问
    }
};
// 私有继承
class SonThree: private Base {
public:
    void foo() {
        b_a = 100;  // 类外访问不到,父类公共成员也变为私有权限
        b_b = 120;  // 类外访问不到,父类公共成员也变为私有权限
        // b_c = 23;  // 无法访问
    }
};
class BaseOne {
public:
    BaseOne() {
        b_a = 100;
    }
    void foo() {
        cout << "Base中的foo方法" << endl;
    }
    int b_a;
};
class SonFour: public BaseOne {
public:
    SonFour() {
        b_a = 200;
    }
    void foo() {
        cout << "Son中的foo方法" << endl;
    }
    int b_a;
};
class A {
public:
    A() {
        num = 233;
    }
    int num;
};
class B {
public:
    B() {
        num = 454;
    }
    int num;
};
// 多继承
class C: public A, public B {
public:
    C() {
        cout << "C构造函数" << endl;
    }
};

class BaseAnimal {
public:
    // 定义虚函数
    virtual void speak() {
        cout << "动物在说话" << endl;
    }
};
class Cat: public BaseAnimal{
public:
    // override 关键字 在派生类中重写基类的虚函数时使用
    void speak() override {
        cout << "猫在说话" << endl;
    }
};
class Dog: public BaseAnimal {
public:
    void speak() override {
        cout << "狗在说话" << endl;
    }
};
void do_speak(BaseAnimal& animal) {
    animal.speak();
}
#endif


