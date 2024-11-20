//
// Created by MSI on 2024/11/20.
//

#include <iostream>
#include <memory>

class MyClass: public std::enable_shared_from_this<MyClass>{
public:
    // 获取一个指向当前对象的 shared_ptr
    std::shared_ptr<MyClass> getSharedPtr(){
        return shared_from_this();
    }

    // 获取一个指向当前对象的weak_ptr
    std::weak_ptr<MyClass> getWeakPtr(){
        return weak_from_this();
    }

    void print(){
        std::cout<<"MyClass instance here!"<<std::endl;
    }

};

int main(){

    // 创建一个 shared_ptr 指向 MyClass 对象
    std::shared_ptr<MyClass> sptr = std::make_shared<MyClass>();

    // 获取 shared_ptr 并使用它
    std::shared_ptr<MyClass> sptr2 = sptr->getSharedPtr();
    sptr2->print();

    // 获取 weak_ptr 并使用它
    std::weak_ptr<MyClass> wptr = sptr->getWeakPtr();

    // 检查weak_ptr 是否有效，并转换为 shared_ptr 使用
    if(auto locked_sptr = wptr.lock()){
        locked_sptr->print();
    }else{
        std::cout<<"weak_ptr is expired !"<< std::endl;
    }

    return 0;
}