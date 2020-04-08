
#ifndef SUPERVISOR_OPTIONS_HPP_
#define SUPERVISOR_OPTIONS_HPP_

namespace supervisor {
    constexpr string SUPERVISORD_CONF_PATH("/etc/supervisor/supervisord.conf");

    class Options {
        
    };

    class ServerOptions: public Options {

    };

    class ClientOptions: public Options {

    };
}

#endif