#pragma once
#include "Config.h"

#include <string.h>
#include <ctime>
#include "fstream"


enum class logLevel {
	TRACE = 0,
	INFO,
	WARN,
	ERR,
	FATAL
};

void setLogLevel(logLevel level);
void initLogger();
void log(std::string msg);
void log(std::string msg, logLevel level);