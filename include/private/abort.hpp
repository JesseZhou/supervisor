#ifndef SUPERVISOR_ABORT_HPP_
#define SUPERVISOR_ABORT_HPP_

namespace supervisor
{
    void logAndAbort(const char* file, int line, const char* message) noexcept __attribute__ ((__noreturn__));
}

#define SUPERVISOR_ABORT(_message) ::supervisor::logAndAbort(__FILE__, __LINE__, _message)

#endif