#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_time(const char *time_str, TimeStruct *t)
{
    char temp[6];
    strncpy(temp, time_str, sizeof(temp) - 1);
    temp[sizeof(temp) - 1] = '\0';

    char *colon = strchr(temp, ':');
    if (colon == NULL)
    {
        return 0;
    }

    *colon = '\0';
    t->hour = atoi(temp);
    t->minute = atoi(colon + 1);
    t->second = 0;

    if (t->hour < 0 || t->hour > 23 || t->minute < 0 || t->minute > 59)
    {
        return 0;
    }

    return 1;
}

void print_usage(const char *program_name)
{
    fprintf(stderr, "Usage: %s HH:MM\n", program_name);
    fprintf(stderr, "Example: %s 12:15\n", program_name);
}

int parse_target_time_or_exit(const char *input, TimeStruct *target_time)
{
    if (!parse_time(input, target_time))
    {
        fprintf(stderr, "Invalid time format. Use HH:MM (24-hour format)\n");
        return 0;
    }

    return 1;
}
