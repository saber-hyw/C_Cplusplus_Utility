#include <iostream>
#include <string>
#include <string.h>
//using namespace std;
    /* strtoul example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtoul */


#include <sstream>  // stringstream

#include <algorithm>  // a -> A

unsigned char* getbyte(const std::string &hexStr) {
    char buf[8] = {};
    static unsigned char byte[4] = {0};
    strcpy(buf , hexStr.c_str());
    std::cout << "buf[] = " << buf << ", sizeof = " << sizeof(buf) <<std::endl;
    for (int i = 1; i <= sizeof(buf); i++) {
        if (0 == (i % 2)) {
            std::string str = "";
            str = buf[i-2];
            str = str + buf[i-1];
            std::cout << "char to str = \"" << str << "\"" << std::endl;
            int i_hex = std::stoi (str, nullptr, 16);
            std::cout << "Hex string to int = " << i_hex << ", i = " << i << std::endl;
            byte[(i/2)-1] = i_hex & 0xff;
            printf ("byte[%d] = %d \n", (i/2)-1, byte[(i/2)-1]);
        }
    }
    return byte;
}

std::string byteToHexStr(unsigned char* byte_arr, int arr_len)
{
    std::string  hexstr;
    for (int i=0;i<arr_len;i++) {
        char hex1;
        char hex2;
        int value=byte_arr[i]; //直接将unsigned char赋值给整型的值，系统会正动强制转换
        int v1=value/16;
        int v2=value % 16;

        //将商转成字母
        if (v1>=0&&v1<=9)
        hex1=(char)(48+v1);
        else
        hex1=(char)(55+v1);

        //将余数转成字母
        if (v2>=0&&v2<=9) {
            hex2=(char)(48+v2);
        } else {
            hex2=(char)(55+v2);
        }

        //将字母连接成串
        hexstr=hexstr+hex1+hex2;
    }
    return hexstr;
}


int main() {

    // const std::string HexFormatString = "400F8000";
    // char buf[8] = {};
    // unsigned char byte[4] = {0};
    // strcpy(buf , HexFormatString.c_str()); //字符串转字符数组，使用strcpy
    // std::cout << "buf[] = " << buf << ", sizeof = " << sizeof(buf) <<std::endl;   //name.c_str()将字符串转换成字符数组
    // for (int i = 1; i <= sizeof(buf); i++) {
    //     if (0 == (i % 2)) {
    //         std::string str = "";
    //         str = buf[i-2];
    //         str = str + buf[i-1];
    //         std::cout << "char to str = \"" << str << "\"" << std::endl;
    //         int i_hex = std::stoi (str, nullptr, 16);
    //         std::cout << "Hex string to int = " << i_hex << ", i = " << i << std::endl;
    //         byte[(i/2)-1] = i_hex & 0xff;
    //         printf ("byte[%d] = %d \n", (i/2)-1, byte[(i/2)-1]);
    //     }
    // }
    // std::string byteStr = "";
    // byteStr = (char*)byte;
    // printf ("print byte str = %s \n", byteStr.c_str());
    // std::cout << "byte str = " << byteStr << std::endl;


    const std::string HexFormatString = "01d50009";
    unsigned char *p = getbyte(HexFormatString);
    printf ("final unsigned char = %s \n", p);

    std::string hexStr = byteToHexStr(p, 4);
    printf ("final byte to string = %s \n", hexStr.c_str());

    return 0;
}