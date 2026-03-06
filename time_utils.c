#include "time_utils.h"

#include <stdio.h>
#include <time.h>

static long time_to_seconds(const TimeStruct *t)
{
    return t->hour * 3600 + t->minute * 60 + t->second;
}

void timeval_to_time_struct(const struct timeval *tv, TimeStruct *t)
{
    struct tm *tm_info = localtime(&tv->tv_sec);
    t->hour = tm_info->tm_hour;
    t->minute = tm_info->tm_min;
    t->second = tm_info->tm_sec;
}

long long timeval_to_ms(const struct timeval *tv)
{
    return (long long)tv->tv_sec * 1000LL + (long long)tv->tv_usec / 1000LL;
}

long long calculate_total_duration_ms(const TimeStruct *start_time, const TimeStruct *target_time)
{
    long start_seconds = time_to_seconds(start_time);
    long target_seconds = time_to_seconds(target_time);

    if (target_seconds <= start_seconds)
    {
        target_seconds += 24 * 3600;
    }

    return (target_seconds - start_seconds) * 1000LL;
}

void format_duration(long seconds, char *buffer)
{
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    sprintf(buffer, "%02d:%02d:%02d", h, m, s);
}

void format_current_time_from_tv(const struct timeval *tv, char *buffer)
{
    time_t current_time_sec = tv->tv_sec;
    struct tm *tm_info = localtime(&current_time_sec);
    sprintf(buffer, "%02d:%02d:%02d", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
}

void format_target_time(const TimeStruct *target_time, char *buffer)
{
    sprintf(buffer, "%02d:%02d:%02d", target_time->hour, target_time->minute, 0);
}
