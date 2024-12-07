#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
 public:
  explicit Session(tcp::socket socket) : socket_(std::move(socket)) {}

  void start() { read(); }

 private:
  void read() {
    auto self = shared_from_this();
    socket_.async_read_some(
        boost::asio::buffer(data_),
        [this, self](boost::system::error_code ec, std::size_t length) {
          if (!ec) {
            write(length);
          } else {
            close();
          }
        });
  }

  void write(std::size_t length) {
    auto self = shared_from_this();
    boost::asio::async_write(
        socket_, boost::asio::buffer(data_, length),
        [this, self](boost::system::error_code, std::size_t) { close(); });
  }

  void close() {
    boost::system::error_code ec;
    socket_.shutdown(tcp::socket::shutdown_both, ec);
    socket_.close(ec);
    if (ec) {
      std::cerr << "Error closing socket: " << ec.message() << "\n";
    } else {
      std::cout << "Session closed successfully.\n";
    }
  }

  tcp::socket socket_;
  char data_[1024];
};

class Server {
 public:
  Server(boost::asio::io_context& io_context, int port)
      : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    accept();
  }

 private:
  void accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
          std::cout << "accept client." << std::endl;
          if (!ec) {
            std::make_shared<Session>(std::move(socket))->start();
          }
          accept();
        });
  }

  tcp::acceptor acceptor_;
};

int main() {
  try {
    boost::asio::io_context io_context;

    int port = 60001;
    Server server(io_context, port);

    std::cout << "Server running on port " << port << " ...\n";
    io_context.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
