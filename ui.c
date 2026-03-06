#include "ui.h"

#include <stdio.h>

#define CLEAR_SCREEN "\033[2J"
#define MOVE_HOME "\033[H"
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"
#define RESET_COLOR "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

static void draw_progress_bar(int width, double percentage)
{
    printf("[");
    int filled = (int)(width * percentage / 100.0);
    for (int i = 0; i < width; i++)
    {
        if (i < filled)
        {
            printf("█");
        }
        else
        {
            printf("░");
        }
    }
    printf("] %.0f%%", percentage);
}

void clear_screen_and_move_home(void)
{
    printf(CLEAR_SCREEN MOVE_HOME);
}

void enter_terminal_ui(void)
{
    printf(HIDE_CURSOR);
}

void exit_terminal_ui(void)
{
    printf(SHOW_CURSOR);
}

void print_times_up_banner(void)
{
    printf(BOLD GREEN);
    printf("\n\n");
    printf("  ╔════════════════════════════════════════╗\n");
    printf("  ║                                        ║\n");
    printf("  ║         TIME'S UP                      ║\n");
    printf("  ║                                        ║\n");
    printf("  ╚════════════════════════════════════════╝\n");
    printf(RESET_COLOR "\n");
}

void print_timer_screen(const char *current_time_str,
                        const char *target_time_str,
                        const char *remaining_str,
                        double percentage)
{
    printf("\n\n");
    printf(BOLD "  ╔════════════════════════════════════════════════════════╗\n");
    printf("  ║                    COUNTDOWN TIMER                     ║\n");
    printf("  ╚════════════════════════════════════════════════════════╝\n" RESET_COLOR);
    printf("\n");
    printf(CYAN "  Current Time:   " RESET_COLOR BOLD "%s\n", current_time_str);
    printf(YELLOW "  Target Time:    " RESET_COLOR BOLD "%s\n", target_time_str);
    printf(GREEN "  Time Remaining: " RESET_COLOR BOLD "%s\n", remaining_str);
    printf(RESET_COLOR "\n");
    printf("  ");
    draw_progress_bar(50, percentage);
    printf("\n\n");
}
