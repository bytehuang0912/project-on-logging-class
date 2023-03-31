//### 日志打印的头文件
//logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <ctime>

enum class LogLevel {
	INFO,
	WARNING,
	ERROR
};

class Logger {
public:
	Logger(LogLevel _logLevel);
	
    //打印信息的模板函数声明和定义都写在头文件
	template<typename T>
	Logger& operator<<(const T& msg)
	{
		printLog();
		std::cout << msg;
		++lastPrinted_;
		return *this;
	}

	Logger& operator<<(std::ostream& (*pf)(std::ostream&));

private:
	
	LogLevel level_;
	void printLog(); //私有成员函数只供类内部使用
	time_t lastPrinted_;
};

extern Logger LOG_INFO;	//extern声明了外部变量，这样的话其他文件也能使用这个全局变量
extern Logger LOG_WARNING;
extern Logger LOG_ERROR;

#endif
