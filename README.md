# timer

A simple countdown timer that displays the current time and remaining time with a progress bar.

## Building

```sh
make
```

This will compile the timer executable.

## Usage

```sh
./timer HH:MM
```

Run the timer with a target time in 24-hour format. The timer will count down and display a progress bar showing the time remaining until the target time.

Example:

```sh
./timer 12:34
```

## About

This is a small tool I coded for myself to use during exams when I finished early. I got tired of running `watch -n 1 date` whenever I wanted to check the exact time I could leave, so I built this instead. Feel free to use it for whatever you need.
