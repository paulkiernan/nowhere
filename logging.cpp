#include "logging.h"
#include "Arduino.h"

void Logging::Init()
{
    Serial.begin(9600);
    int startMillis = millis();
    while(!Serial && millis() - startMillis < c_initTimeoutMs)
    {
        ;
    }

    log("*** Begin Session***");
}

void Logging::log(const char* buff)
{
    if(!Serial)
        return;

    char logstr[512];
    sprintf(logstr, "[%u]: %s", millis(), buff);

    Serial.println(logstr);
}
