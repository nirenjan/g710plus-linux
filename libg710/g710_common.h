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

#ifndef G710_COMMON_H
#define G710_COMMON_H

#include <limits.h>

struct g710_device {
    /** Path to hidraw device for interface 0 */
    char if0_hidraw[NAME_MAX];
    /** Path to hidraw device for interface 1 */
    char if1_hidraw[NAME_MAX];
    /** Path to event file for interface 0 */
    char if0_event[NAME_MAX];
    /** Path to event file for interface 1 */
    char if1_event[NAME_MAX];

    /** Is this the G710 (1) or G710+ (0)? */
    uint8_t is_g710:1;
    /** Mode 1 enabled? */ 
    uint8_t m_m1:1;
    /** Mode 2 enabled? */ 
    uint8_t m_m2:1;
    /** Mode 3 enabled? */ 
    uint8_t m_m3:1;
    /** Is MR on? */
    uint8_t m_mr:1;
    /** Is MR recording? */
    uint8_t mr_recording:1;
    /** Is the keyboard in game mode? (Windows key disabled) */
    uint8_t game_mode:1;
    /** Is mode combo enabled? This allows the user to have up to 8 modes
     * using the individual states of the M1, M2 and M3 keys. Not yet supported.
     */
    uint8_t mode_combo_enabled:1;

    /** Brightness for the WASD/arrow keys */
    uint8_t bri_wasd:4;
    /** Brightness for the other keys */
    uint8_t bri_keys:4;
};

#endif /* G710_COMMON_H */
