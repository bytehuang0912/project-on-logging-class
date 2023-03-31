
//### 日志打印的调用方法
//main.cpp
#include "logger.h"

int main() 
{

	LOG_INFO << "print info 1" << 111 << std::endl;
	LOG_INFO << "print info 2" << 222 << std::endl;
	LOG_ERROR << "print error 1" << 333 << std::endl;

	return 0;
}