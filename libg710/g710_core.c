/*
 * Logitech G710+ Macro LED driver
 *
 * Copyright (C) 2015 Nirenjan Krishnan (nirenjan@nirenjan.org)
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation, version 2.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libudev.h>

#define VENDOR_ID_LOGITECH 0x046d
#define PRODUCT_ID_LOGITECH_G710PLUS 0xc24d

/* Check if the USB device is supported by this library */
static int libg710_check_product(uint16_t idVendor, uint16_t idProduct)
{
    return (idVendor == VENDOR_ID_LOGITECH && idProduct == PRODUCT_ID_LOGITECH_G710PLUS);
}


