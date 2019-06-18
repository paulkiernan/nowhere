#ifndef LOGGING_H
#define LOGGING_H

#include "Arduino.h"

class Logging
{
    public:
        static const int c_initTimeoutMs = 1000;

    public:
        static void Init();
        static void log(const char* buff);
};

#endif
