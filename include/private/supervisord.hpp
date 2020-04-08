#ifndef SUPERVISOR_SUPERVISORD_HPP_
#define SUPERVISOR_SUPERVISORD_HPP_

namespace supervisor {
    class Supervisord {
    public:
        Supervisord(ServerOptions& options): options(options) {}
        ~Supervisord();
        void run();
    private:
        ServerOptions options;
    }
}

#endif