#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include "esp_chip_info.h"

void board_info_show(void);

esp_chip_info_t* board_info_get_chip_info();

#endif /* end of include guard: BOARD_INFO_H */
