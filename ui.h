#ifndef UI_H
#define UI_H

void clear_screen_and_move_home(void);
void enter_terminal_ui(void);
void exit_terminal_ui(void);
void print_times_up_banner(void);
void print_timer_screen(const char *current_time_str,
                        const char *target_time_str,
                        const char *remaining_str,
                        double percentage);

#endif
