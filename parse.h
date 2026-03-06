#ifndef PARSE_H
#define PARSE_H

#include "time_utils.h"

void print_usage(const char *program_name);
int parse_target_time_or_exit(const char *input, TimeStruct *target_time);

#endif
