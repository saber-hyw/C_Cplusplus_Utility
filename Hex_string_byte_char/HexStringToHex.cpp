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

unsigned int swapUInt32(unsigned int value) {
    return ((value & 0x000000FF) << 24) |  ((value & 0x0000FF00) << 8) |  ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24);   
}

int swapInt32(int value) {
    return ((value & 0x000000FF) << 24) |  ((value & 0x0000FF00) << 8) |  ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24);   
}

std::string int2Hex(std::string intstr) {
    // int to hexString
    int faceId = std::stoi(intstr);
    std::string temp;
    std::stringstream ss;
    ss << std::hex << faceId;
    ss >> temp;
    std::cout << "target Hex string temp = " << temp << std::endl;

    int faceIDSwap = swapInt32(faceId);
    std::cout << "faceIDSwap = " << faceIDSwap << std::endl;
    std::string temp_swap = "";
    std::stringstream ss_swap;
    ss_swap << std::hex << faceIDSwap;
    ss_swap >> temp_swap;
    std::cout << "temp_swap = " << temp_swap << std::endl;

    for (int i = 0; i < 8; i++) {
        if (temp_swap.length() < 8) {
            temp_swap = "0" + temp_swap;
        } else {
            break;
        }
    }
    std::cout << "temp_swap = " << temp_swap << std::endl;

    // 大小写
    std::string str = temp_swap;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::cout << "转小写: " << str << std::endl;

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << "转大写: " << str << std::endl;

    return temp_swap;
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


    // const std::string HexFormatString = "400F8000";
    // unsigned char *p = getbyte(HexFormatString);
    // printf ("final unsigned char = %s \n", p);

    // std::string hexStr = byteToHexStr(p, 4);
    // printf ("final byte to string = %s \n", hexStr.c_str());





    // char buffer [12];
    // unsigned int ul;
    // std::string strfaceID = "400e4000";
    // sprintf(buffer,"0x%s", str.c_str());
    // ul = strtoul (str.c_str(), NULL, 16);
    // // printf ("Value entered: %lu. Its double: %lu\n",ul,ul*2);
    // printf ("Value entered: %lu,  hex[] = %02x %02x %02x %02x \n", ul, buffer[0], buffer[1], buffer[2], buffer[3]);
    
    // // std::string ret(reinterpret_cast<const char*>(buffer), sizeof(buffer));
    // std::string ret(buffer, 4);
    // // printf ("Value entered: %lu. Its double: %lu\n",ul,ul*2);
    // printf ("Value entered: %lu,  hex[] = %02x %02x %02x %02x \n", ul, ret.c_str()[0], ret.c_str()[1], ret.c_str()[2], ret.c_str()[3]);

    // // hex to string
    // std::string hexString(ret.c_str()[0], 1);
    // hexString = hexString + ret.c_str()[1] + ret.c_str()[2] + ret.c_str()[3];


    // int faceID = 151049473; // 302003287  1463025682
    // std::string temp;
    // std::stringstream ss;
    // ss << std::hex << faceID;
    // ss >> temp;
    // std::cout << "temp = " << temp << std::endl;




    // // int to hexString   使用string的翻转功能
    // std::string hexstring = "151049473"; // 7424  151049473(01d50009)
    // int faceId = std::stoi(hexstring);
    // std::string temp;
    // std::stringstream ss;
    // ss << std::hex << faceId;
    // ss >> temp;
    // std::cout << "target Hex string temp = " << temp << std::endl;

    // std::reverse(temp.begin(),temp.end());
    // std::cout << "reverse temp = " << temp << std::endl;

    // std::string str = temp;
    // std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    // std::cout << "转小写: " << str << std::endl;

    // std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    // std::cout << "转大写: " << str << std::endl;


    // 7424  151049473(01d50009)
    // std::string str_1 = int2Hex("7424");
    // std::cout << "str_1 = " << str_1 << std::endl;
    // std::string str_2 = int2Hex("151049473");
    // std::cout << "str_2 = " << str_2 << std::endl;
    // std::string str_3 = int2Hex("1049088");  // 00100200
    // std::cout << "str_3 = " << str_3 << std::endl;

    std::string str_4 = int2Hex("640");  // 00000001
    std::cout << "str_4 = " << str_4 << std::endl;

    return 0;
}