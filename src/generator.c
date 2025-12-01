#include "passcheck/generator.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// system-oriented functions
#ifdef _WIN32
#include <bcrypt.h>
#include <windows.h>
#pragma comment(lib, "bcrypt.lib")
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__)
#include <sys/random.h>
#include <unistd.h>
#endif
