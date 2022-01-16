#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "LogPanel.h"

static std::string& operator+(std::string& str, int n) {
	std::stringstream ss;
	ss << n;
	str += ss.str();
	return str;
}
#define LOG_MK_STR(level)			\
	std::string("[" #level "]  ") \
  + std::string(__FILE__ ": ")		\
  + __LINE__						\
  + std::string("  > ")

#define LOG_DEBUG(logPanel) logPanel << LOG_MK_STR(DEBUG)
#define LOG_ERROR(logPanel) logPanel << LOG_MK_STR(ERROR)
#define LOG_INFO(logPanel)  logPanel << LOG_MK_STR(_INFO)

template<class ins>
ins& GetInstance() {
	static ins i;
	return i;
}

template<class ins>
ins* GetPoint() {
	static ins i;
	return &i;
}
