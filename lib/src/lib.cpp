#include "lib.hpp"
#include <boost/asio.hpp>

void Lib::print() {
    boost::asio::io_context io;
    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(1));
    timer.async_wait([](const boost::system::error_code&) {
        std::cout << "Hello from boost!" << std::endl;
    });
    io.run();
}
