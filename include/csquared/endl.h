#pragma once

/*
 *	Our cross-platform solution to endline characters.
 *	Why does the C standard not have something like this already?
 */
#if defined(_WIN32) || defined(_WIN64)
#define ENDL "\r\n"
#elif defined(__APPLE__) || defined(__MACH__)
#define ENDL "\n"
#elif defined(__linux__) || defined(__unix__) || defined(__unix)
#define ENDL "\n"
#else
#error "Unknown operating system!"
#endif