//
// Created by MSI on 2024/11/25.
//
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

// 定义一个简单的类
class MyClass {
public:
    MyClass(int value) : value_(value) {}

    // 一个成员函数，用于输出值
    void printValue() const {
        std::cout << "Value: " << value_ << std::endl;
    }

    // 一个成员函数，用于修改值
    void setValue(int newValue) {
        value_ = newValue;
    }

    // 一个成员变量
    int getValue() const {
        return value_;
    }

private:
    int value_;
};

int main() {
    // 创建一些 MyClass 对象
    std::vector<MyClass> objects = { MyClass(1), MyClass(2), MyClass(3) };

    // 使用 std::mem_fn 生成一个可调用对象，用于调用 printValue 成员函数
    auto printValueFn = std::mem_fn(&MyClass::printValue);

    // 使用 std::for_each 和可调用对象来打印每个对象的值
    std::for_each(objects.begin(), objects.end(), printValueFn);

    // 使用 std::mem_fn 生成一个可调用对象，用于调用 setValue 成员函数
    auto setValueFn = std::mem_fn(&MyClass::setValue);

    // 使用 std::for_each 和可调用对象来设置每个对象的新值
    std::for_each(objects.begin(), objects.end(), [=](MyClass& obj) {
        setValueFn(obj, 42);  // 将每个对象的值设置为 42
    });

    // 再次打印每个对象的值，验证它们是否已经被设置为 42
    std::for_each(objects.begin(), objects.end(), printValueFn);

    // 使用 std::mem_fn 生成一个可调用对象，用于调用 getValue 成员函数
    auto getValueFn = std::mem_fn(&MyClass::getValue);

    // 打印每个对象的值（使用 getValue 成员函数）
    for (const auto& obj : objects) {
        std::cout << "GetValue: " << getValueFn(obj) << std::endl;
    }

    return 0;
}