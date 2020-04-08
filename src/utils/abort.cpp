#include "private/abort.hpp"
#include <cstdlib>
#include <syslog.h>

void supervisor::logAndAbort(const char* file, int line, const char* message) noexcept
{
    syslog(LOG_ERR, "SUPERVISOR_ABORT, file %s, line %d: %s", file, line, message);
    abort();
}