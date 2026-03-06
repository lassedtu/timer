#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <sys/time.h>

typedef struct
{
    int hour;
    int minute;
    int second;
} TimeStruct;

void timeval_to_time_struct(const struct timeval *tv, TimeStruct *t);
long long timeval_to_ms(const struct timeval *tv);
long long calculate_total_duration_ms(const TimeStruct *start_time, const TimeStruct *target_time);
void format_duration(long seconds, char *buffer);
void format_current_time_from_tv(const struct timeval *tv, char *buffer);
void format_target_time(const TimeStruct *target_time, char *buffer);

#endif
