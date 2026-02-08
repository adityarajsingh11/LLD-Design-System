#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <ctime>
#include <string>

using namespace std;

// TimeUtils ek utility class hai
// Ye current system time ko readable string me convert karti hai
class TimeUtils {

public:
    // Static method – current time return karta hai
    static string getCurrentTime() {

        time_t now = time(0);     // current time get karte hain
        char* dt = ctime(&now);   // time ko readable format me convert

        string s(dt);

        // newline character remove kar rahe hain (agar ho)
        if (!s.empty() && s.back() == '\n')
            s.pop_back();

        return s; // final formatted time
    }
};

#endif // TIME_UTILS_H
