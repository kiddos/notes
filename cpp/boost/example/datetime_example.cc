#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

int main() {
  namespace pt = boost::posix_time;
  namespace gr = boost::gregorian;

  // Current date and time
  pt::ptime current_time = pt::second_clock::local_time();
  gr::date today = current_time.date();

  // Format the current date in yyyy-mm-dd
  std::cout << "Today's date (yyyy-mm-dd): "
            << gr::to_iso_extended_string(today) << "\n";

  // Constructing a specific date
  gr::date specific_date(2024, gr::Jan, 1);
  std::cout << "Specific date (yyyy-mm-dd): "
            << gr::to_iso_extended_string(specific_date) << "\n";

  // Adding days to a date
  gr::date_duration days_to_add(10);
  gr::date future_date = today + days_to_add;
  std::cout << "Date 10 days from today (yyyy-mm-dd): "
            << gr::to_iso_extended_string(future_date) << "\n";

  return 0;
}
