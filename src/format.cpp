#include <string>
#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long s) {
    int hh = s / 3600;
    int mm = (s / 60) % 60;
  	int ss = s % 60;
    char buffer[10];
    sprintf(buffer, "%d:%02d:%02d", hh, mm, (int)ss);
    string str = buffer;
    return str;
}