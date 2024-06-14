//
// Created by Beriuta on 2024/6/11.
//
#ifndef STUDENTPRO_PROJECTS_H
#define STUDENTPRO_PROJECTS_H

class MyString {
    friend ostream& operator<<(ostream& c, MyString& str);
    friend istream& operator>>(istream& c, MyString& str);
public:
    // 有参构造
    MyString(const char* str);
    // 拷贝构造
    MyString(const MyString& str);
    // 析构函数
    ~MyString();
    // 重载+
    MyString operator+(const char* str);
    MyString operator+(MyString& str);
    // 重载=
    MyString& operator=(const char* str);
    MyString& operator=(const MyString& str);
    // 重载[]
    char& operator[](int pos);
    // 重载==
    bool operator==(const char* str);
    bool operator==(const MyString& str);
private:
    char* m_string;  // 维护底层的字符数组
    size_t m_size;  // 字符串开辟长度
};
#endif //STUDENTPRO_PROJECTS_H
