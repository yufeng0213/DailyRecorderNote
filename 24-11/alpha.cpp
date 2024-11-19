//
// Created by MSI on 2024/11/19.
//

#include <iostream>
#include <cctype>


/*
 *
 * 注意： 这些函数的返回值都不是bool，而是int
 * 所以 如果成功返回的就是非零值，这句话的意思包括 返回的不一定是1，也有可能是8，-1等等
 */
int main(){

    // 是否为字母或数字 a-z A-Z 0-9
    std::cout<<isalnum('a')<<"\n";

    // 是否为字母 a-z A-Z
    std::cout<<isalpha('A')<<"\n";

    // 是否为小写字母 a-z
    std::cout<<islower('A')<<"\n";

    // 是否为大写字母
    std::cout<<isupper('a')<<"\n";

    // 是否为空白字符 空格 换行符 制表符
    std::cout<<isspace(' ')<<"\n";

    // 是否为标点符号
    std::cout<<ispunct('.')<<"\n";

    // 是否为十六进制数字 a-f A-F 0-9
    std::cout<<isxdigit('a')<<"\n";



    return 0;
}