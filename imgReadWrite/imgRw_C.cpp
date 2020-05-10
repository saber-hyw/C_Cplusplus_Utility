#include<iostream>
 
using namespace std;
 
int main() {
    std::string fileName_1 = "1.png";
    std::string fileName_1_copy = "1_copy.png";
    uint32_t length;
    // 文件操作指针
	FILE* fp;
	// 以二进制方式打开图像
	if (nullptr == (fp = fopen(fileName_1.c_str(), "rb"))) {
		std::cout << "Open image 1 failed!" << std::endl;
		return 1;
    }
	// 获取图像数据总长度
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	rewind(fp);
	// 根据图像数据长度分配内存buffer
	char* ImgBuffer=(char*)malloc( length* sizeof(char) );
	// 将图像数据读入buffer
	fread(ImgBuffer, length, 1, fp);
	fclose(fp);
	// 以二进制写入方式打开
	if (nullptr == (fp = fopen(fileName_1_copy.c_str(), "wb"))) {
		std::cout << "Open image_copy failed!" << std::endl;
		return 1;
    }
	// 从buffer中写数据到fp指向的文件中
	fwrite(ImgBuffer, length, 1, fp);
	std::cout << "Done!" << std::endl;
	// 关闭文件指针，释放buffer内存
	fclose(fp);
	free(ImgBuffer);
    return 0;
}