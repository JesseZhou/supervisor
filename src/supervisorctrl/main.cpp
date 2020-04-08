#include "private/abort.hpp"
#include <iostream>
#include <getopt.h>
//#include "private/supervisorctrl.hpp"

//using namespace supervisor;

namespace {
    struct Params {
        bool interactive;
        std::string username;
        std::string password;
        std::string configFilePath;
        std::string serverurl;
        std::string historyFile;
    };

    void outPutHelp(char* processName) {
        std::cout <<
            "supervisorctl -- control applications run by supervisord from the cmd line.\n"
            "\n"
            "Usage: "<<processName<<" [options] [action [arguments]]\n"
            "\n"
            "Options:\n"
            "-c/--configuration FILENAME -- configuration file path (searches if not given)\n"
            "-h/--help -- print usage message and exit\n"
            "-i/--interactive -- start an interactive shell after executing commands\n"
            "     (default \"http://localhost:9001\").\n"
            "-u/--username USERNAME -- username to use for authentication with server\n"
            "-p/--password PASSWORD -- password to use for authentication with server\n"
            "-r/--history-file -- keep a readline history (if readline is available)\n"
            "\n"
            "action [arguments] -- see below\n"
            "\n"
            "Actions are commands like \"tail\" or \"stop\".  If -i is specified or no action is\n"
            "specified on the command line, a \"shell\" interpreting actions typed\n"
            "interactively is started.  Use the action \"help\" to find out about available\n"
            "actions.\n"
            "\n";
        std::cout << std::flush;
    }

    Params parseParams(int argc, char** argv) {
        Params params;
        const struct option options[] = {
            {"help",         no_argument,       nullptr, 'h'},
            {"username",     required_argument, nullptr, 'u'},
            {"password",     required_argument, nullptr, 'p'},
            {"serverurl",    required_argument, nullptr, 's'},
            {"interactive",  no_argument,       nullptr, 'i'},
            {"history-file", required_argument, nullptr, 'r'},
            {0,              0,                 nullptr,   0}
        };
        const char* optstring = "hu:p:s:ir:";
        bool doneParsing(false);
        int optionIndex(0);

        while(!doneParsing) {
            const int ret(getopt_long(argc, argv, optstring, options, &optionIndex));
            switch(ret) {
                case 'h':
                    outPutHelp(argv[0]);
                    exit(EXIT_SUCCESS);
                case 'u':
                    params.username.assign(optarg);
                    std::cout<<"get: "<<params.username<<std::endl;
                    break;
                case 'p':
                    params.password.assign(optarg);
                    std::cout<<"get: "<<params.password<<std::endl;
                    break;
                case 's':
                    params.serverurl.assign(optarg);
                    std::cout<<"get: "<<params.serverurl<<std::endl;                
                    break;
                case 'i':
                    params.interactive = true;
                    std::cout<<"get: "<<params.interactive<<std::endl;                 
                    break;
                case 'r':
                    params.historyFile.assign(optarg);
                    std::cout<<"get: "<<params.historyFile<<std::endl;                 
                    break;   
                case (-1):
                    /* No more arguments */
                    doneParsing = true;                
                    break;
                case '?':
                    /* Unknown option */
                    std::cout << "For help, use " << argv[0] << " -h" << std::endl;
                    exit(EXIT_FAILURE);
                default:
                    /* BUG */
                    SUPERVISOR_ABORT("getopt_long bug");                                    
            }
        }
        return params;
    }
}

int main(int argc, char** argv) {
    parseParams(argc, argv);
    return 0;
}