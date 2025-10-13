#include <hidapi/hidapi.h>

#include <iomanip>
#include <iostream>

int main(void) {
  if (hid_init() < 0) {
    return 1;
  }

  struct hid_device_info* devs = hid_enumerate(0x0, 0x0);
  struct hid_device_info* cur_dev = devs;
  std::cout << "\n--- Enumerated HID Devices ---" << std::endl;
  while (cur_dev) {
    std::cout << "Device Found:" << std::endl;
    std::wcout << "  Path: " << cur_dev->path << std::endl;
    std::cout << "  Vendor ID: 0x" << std::hex << std::setw(4)
              << std::setfill('0') << cur_dev->vendor_id << std::endl;
    std::cout << "  Product ID: 0x" << std::hex << std::setw(4)
              << std::setfill('0') << cur_dev->product_id << std::dec
              << std::endl;

    if (cur_dev->manufacturer_string) {
      std::wcout << "  Manufacturer: " << cur_dev->manufacturer_string
                 << std::endl;
    }
    if (cur_dev->product_string) {
      std::wcout << "  Product: " << cur_dev->product_string << std::endl;
    }

    cur_dev = cur_dev->next;
    std::cout << "-----------------------------------" << std::endl;
  }
  hid_free_enumeration(devs);

  // hid_device* handle = hid_open(TARGET_VID, TARGET_PID, NULL);

  if (hid_exit() < 0) {
    std::cerr << "Error: hid_exit() failed." << std::endl;
    return 1;
  }
  return 0;
}
