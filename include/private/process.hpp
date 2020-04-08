#ifndef SUPERVISOR_PROCESS_HPP_
#define SUPERVISOR_PROCESS_HPP_

namespace supervisor {
    class Supprocess {
    public:
        enum class State
        {
            STARTING,
            RUNNING,
            STOPPING,
            STOPPED,
            EXITED,
            FATAL,
            BACKOFF,
            UNKNOWN
        };

        Supprocess();
    private:
        pid_t pid;
        SubProcessConfig config;
    }
}

#endif