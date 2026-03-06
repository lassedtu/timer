#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "parse.h"
#include "time_utils.h"
#include "ui.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        print_usage(argv[0]);
        return 1;
    }

    TimeStruct target_time;
    if (!parse_target_time_or_exit(argv[1], &target_time))
    {
        return 1;
    }

    struct timeval start_tv;
    gettimeofday(&start_tv, NULL);

    TimeStruct start_time;
    timeval_to_time_struct(&start_tv, &start_time);
    long long start_time_ms = timeval_to_ms(&start_tv);

    long long total_duration_ms = calculate_total_duration_ms(&start_time, &target_time);

    if (total_duration_ms <= 0)
    {
        fprintf(stderr, "Target time must be in the future\n");
        return 1;
    }

    enter_terminal_ui();

    char current_time_str[16];
    char target_time_str[16];
    char remaining_str[16];

    while (1)
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);

        long long current_time_ms = timeval_to_ms(&tv);
        long long elapsed_ms = current_time_ms - start_time_ms;
        long long remaining_ms = total_duration_ms - elapsed_ms;

        clear_screen_and_move_home();

        if (remaining_ms <= 0)
        {
            print_times_up_banner();
            break;
        }

        double percentage = (elapsed_ms * 100.0) / total_duration_ms;

        format_current_time_from_tv(&tv, current_time_str);
        format_target_time(&target_time, target_time_str);
        format_duration(remaining_ms / 1000, remaining_str);

        print_timer_screen(current_time_str, target_time_str, remaining_str, percentage);

        fflush(stdout);

        usleep(50000);
    }

    exit_terminal_ui();

    return 0;
}
