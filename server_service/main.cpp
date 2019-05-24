
#include <iostream>

#include <usr_interrupt_handler.hpp>
#include <runtime_utils.hpp>

#include "app_server.hpp"

using namespace web;
using namespace cfx;

int main(int argc, const char * argv[]) {
    InterruptHandler::hookSIGINT();

    AppServer server;
    server.setEndpoint("http://host_auto_ip4:9090/api");
    
    try {
        // wait for server initialization...
        server.accept().wait();
        std::cout << "TMApp Server now listening for requests at: " << server.endpoint() << '\n';
        
        InterruptHandler::waitForUserInterrupt();

        server.shutdown().wait();
    }
    catch(std::exception & e) {
        std::cerr << "что-то пошло не так! :(" << '\n';
    }
    catch(...) {
        RuntimeUtils::printStackTrace();
    }

    return 0;
}
