#pragma once

#ifdef _WIN32
#define ENDL "\r\n"
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
#define ENDL "\n"
#endif