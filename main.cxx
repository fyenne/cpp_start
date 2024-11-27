#include <cxxopts.hpp>
#include <fmt/format.h>
#include <range/v3/view.hpp>
#include <boost/regex.hpp>
#include <boost/system/error_code.hpp>
#include <iostream>

namespace view = ranges::views;

int fib(int x)
{
  int a = 0, b = 1;

  for (int it : view::repeat(0) | view::take(x))
  {
    (void)it;
    int tmp = a;
    a += b;
    b = tmp;
  }

  return a;
}

int main(int argc, char **argv)
{
    cxxopts::Options options("fibo", "Print the fibonacci sequence up to a value 'n'");
    options.add_options()("n,value", "The value to print to", cxxopts::value<int>()->default_value("10"));

    auto result = options.parse(argc, argv);
    auto n = result["value"].as<int>();

    for (int x : view::iota(1) | view::take(n))
    {
        fmt::print("fib({}) = {}\n", x, fib(x));
    }

    // new 
    std::string text = "Hello, World! Boost regex is powerful.";
    // Regex pattern to match "World" followed by any characters and then "regex"
    boost::regex pattern("World.*regex");

    // Variable to hold the results of the regex search
    boost::smatch what;
    if (boost::regex_search(text, what, pattern)) {
        // If the pattern is found, output the matched substring
        std::cout << "Found match: " << what[0] << std::endl;
    } else {
        // If no match is found, output an error message
        std::cout << "No match found." << std::endl;
    }

    // Example of using boost::system::error_code
    boost::system::error_code ec;
    if (ec) {
        // If an error occurred, output the error message
        std::cout << "An error occurred: " << ec.message() << std::endl;
    } else {
        // If no error occurred, output a success message
        std::cout << "Operation completed without errors." << std::endl;
    }

    return 0;
}