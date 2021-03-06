/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef __ISP_OP1W_TYPES_H_INCLUDED__
#define __ISP_OP1W_TYPES_H_INCLUDED__

/*
 * This file is part of the Multi-precision vector operations exstension package.
 */
 
/* 
 * Single-precision vector operations
 */
 
/*  
 * Prerequisites:
 *
 */

#include "mpmath.h"

/*
 * Single-precision data type specification
 */


typedef mpsdata_t       tvector1w;
typedef mpsdata_t       tscalar1w;
typedef spsdata_t        tflags;


typedef  struct {
  tvector1w       d;
  tflags        f;
} tvector1w_tflags1w;

#endif /* __ISP_OP1W_TYPES_H_INCLUDED__ */
