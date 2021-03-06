#ifndef LOGGER_H
#define LOGGER_H

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include <strview.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define LOG_DATE_FORMAT "[%02d-%02d-%02d %02d:%02d:%02d]"

void logstr(const char *label, strview view);

void loginfo(const char *format, ...);
void logwarn(const char *format, ...);
void logerror(const char *format, ...);

#endif /* LOGGER_H */
