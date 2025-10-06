#include "Logger.h"

#include <sstream>


void setLogLevel(logLevel level) {
	
	/*#if level == logLevel::TRACE
		#define LOG_LEVEL logLevel::TRACE
	#elif level == logLevel::INFO
		#define LOG_LEVEL logLevel::INFO;
	#endif

	switch (level) {
	case logLevel::TRACE: 
		#define LOG_LEVEL logLevel::TRACE;
	case logLevel::INFO:
		#define LOG_LEVEL logLevel::INFO;
	case logLevel::WARN:
		#define LOG_LEVEL logLevel::WARN;
	case logLevel::ERR:
		#define LOG_LEVEL logLevel::ERR;
	case logLevel::FATAL:
		#define LOG_LEVEL logLevel::FATAL;
	}*/
}

void initLogger() {
	// clear log file
	std::ofstream logFile;
	logFile.open("Log.txt");
	logFile.close();
}

void log(std::string msg) {
	std::time_t ts = std::time(0);
	struct tm dt = *localtime(&ts);

	std::stringstream ss;
	if (dt.tm_hour < 10) ss << "0" << dt.tm_hour << ":";   else ss << dt.tm_hour << ":";
	if (dt.tm_min  < 10) ss << "0" << dt.tm_min  << ":";   else ss << dt.tm_min  << ":";
	if (dt.tm_sec  < 10) ss << "0" << dt.tm_sec  << " - "; else ss << dt.tm_sec  << " - ";
	ss << msg << std::endl;

	std::ofstream logFile;
	logFile.open("Log.txt", std::ios_base::app);
	logFile << ss.str();
	logFile.close();
}

void log(std::string msg, logLevel level) {
	if (level >= LOG_LEVEL) {
		log(msg);
	}
}