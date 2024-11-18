//
// Created by MSI on 2024/11/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

// Base64解码表
static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

// Base64字符到6位二进制值的映射
static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

static inline unsigned char base64_decode(unsigned char c) {
    return static_cast<unsigned char>(base64_chars.find(c));
}

std::string base64_decode(const std::string& encoded_str) {
    int in_len = encoded_str.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_out[3];
    std::string decoded_string;

    while (in_len-- && (encoded_str[in_len] != '=') && is_base64(encoded_str[in_len])) {
        char_array_4[i++] = encoded_str[in_len];
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_decode(char_array_4[i]);

            char_array_out[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_out[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_out[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                decoded_string += char_array_out[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_decode(char_array_4[j]);

        char_array_out[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_out[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);

        decoded_string += char_array_out[0];

        if (encoded_str[in_len] != '=')
            decoded_string += char_array_out[1];
    }

    return decoded_string;
}

std::string base64_encode(std::string const& bytes_to_encode) {
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (bytes_to_encode.size() - i > 2) {
        char_array_3[0] = bytes_to_encode[i++];
        char_array_3[1] = bytes_to_encode[i++];
        char_array_3[2] = bytes_to_encode[i++];

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for(j = 0; (j <4) ; j++)
            ret += base64_chars[char_array_4[j]];
    }

    if(i){
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
            ret += '=';
    }

    return ret;
}

int main() {
    std::string encoded_str = "SGVsbG8gV29ybGQh"; // "Hello World!" in Base64
    std::string decoded_str = base64_decode(encoded_str);
    std::cout << "Decoded string: " << decoded_str << std::endl;
    return 0;
}