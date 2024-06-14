//
// Created by Beriuta on 2024/6/11.
//
#include "projects.h"

// 有参构造
MyString::MyString(const char* str) {
    cout << "MyString有参构造" << endl;
    this->m_string = new char[strlen(str) + 1];
    strcpy(this->m_string, str);
    this->m_size = strlen(str);
//    cout << "m_size " << this->m_size << endl;
}
// 拷贝构造
MyString::MyString(const MyString& str) {
    cout << "MyString拷贝构造" << endl;
    this->m_string = new char[strlen(str.m_string) + 1];
    strcpy(this->m_string, str.m_string);
    this->m_size = strlen(str.m_string);
}

// 重载+ str
MyString MyString::operator+(const char* str) {
    // 现有的字符串 + 传入的
    int new_size = this->m_size + strlen(str) + 1;
    char* temp = new char[new_size];
    // 用字符 '0' 填充前五个字节
    memset(temp, 0, new_size);  // 将temp后面添加上指定数量的字节
    strcat(temp, this->m_string);  // 将temp跟原始数据做拼接
    strcat(temp, str);

    MyString new_str(temp);
    delete[] temp;
    return new_str;
}
// 重载+ MyString
MyString MyString::operator+(MyString& str) {
    // 现有的字符串 + MyString类里面的m_string
    size_t new_size = this->m_size + strlen(str.m_string) + 1;
    char* temp = new char[new_size];
    // 用字符 '0' 填充前五个字节
    memset(temp, 0, new_size);  // 将temp后面添加上指定数量的字节
    strcat(temp, this->m_string);  // 将temp跟原始数据做拼接
    strcat(temp, str.m_string);

    MyString new_str(temp);
    delete[] temp;
    return new_str;
}
// 重载[]
char& MyString::operator[](int pos) {
    return this->m_string[pos];
}
// 重载 == str
bool MyString::operator==(const char* str) {
    if (strcmp(this->m_string, str) == 0) {
        return true;
    }
    return false;
}
// 重载== MyString
bool MyString::operator==(const MyString& str) {
    // strcmp: 如果 str1 小于 str2，返回一个负值。等于 str2，返回 0。大于 str2，返回一个正值。
    if (strcmp(this->m_string, str.m_string) == 0) {
        return true;
    }
    return false;
}

// 重载=
MyString& MyString::operator=(const char* str) {
    // 将当前堆区数据清空，然后赋值新的数据
    if (this->m_string != nullptr) {
        delete[] this->m_string;
        this->m_string = nullptr;
    }
    this->m_string = new char[strlen(str) + 1];
    strcpy(this->m_string, str);
    return *this;
}

MyString& MyString::operator=(const MyString& str) {
    if (this == &str) return *this;  //  检查自我赋值
    if (this->m_string != nullptr) {
        delete[] this->m_string;
        this->m_string = nullptr;
    }
    size_t size = strlen(str.m_string) + 1;
    this->m_string = new char[size];
    strcpy(this->m_string, str.m_string);
    this->m_size = size;
    return *this;
}

MyString::~MyString() {
    cout << "MyString析构" << endl;
    if (this->m_string != nullptr) {
        delete []this->m_string;
        this->m_string = nullptr;
    }
}

// 重载 <<
ostream& operator<<(ostream& c, MyString& str) {
    c << str.m_string;
    return c;
}
// 重载 >>
istream& operator>>(istream& c, MyString& str) {
    // 先判断堆区是否有数据，如果有先清空
    if (str.m_string != nullptr) {
        delete[] str.m_string;
        str.m_string = nullptr;
    }
    char buf[1024] = {0};
    c >> buf;
    str.m_string = new char[strlen(buf) + 1];
    strcpy(str.m_string, buf);
    return c;
}




