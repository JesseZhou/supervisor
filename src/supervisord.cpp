
using namespace supervisor;

namespace {
    void Supervisord::run() {

    }

    int main(int argc, char** argv) {
       ServerOptions options();
       Supervisord supervisord(options);
       supervisord.run();
    }
}