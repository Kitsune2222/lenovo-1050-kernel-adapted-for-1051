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

#include "ia_css_types.h"
#include "sh_css_defs.h"
#include "ia_css_debug.h"
#include "sh_css_frac.h"

#include "ia_css_dp.host.h"

const struct ia_css_dp_config default_dp_config = {
	8192,
	2048,
	32768,
	32768,
	32768,
	32768
};

void
ia_css_dp_encode(
	struct sh_css_isp_dp_params *to,
	const struct ia_css_dp_config *from)
{
	int gain = from->gain;
	int gr   = from->gr;
	int r    = from->r;
	int b    = from->b;
	int gb   = from->gb;
	to->threshold_single =
	    SH_CSS_BAYER_MAXVAL;
	to->threshold_2adjacent =
	    uDIGIT_FITTING(from->threshold, 16, SH_CSS_BAYER_BITS);
	to->gain =
	    uDIGIT_FITTING(from->gain, 8, SH_CSS_DP_GAIN_SHIFT);

	to->coef_rr_gr =
	    uDIGIT_FITTING (gain * gr / r, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_rr_gb =
	    uDIGIT_FITTING (gain * gb / r, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_bb_gb =
	    uDIGIT_FITTING (gain * gb / b, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_bb_gr =
	    uDIGIT_FITTING (gain * gr / b, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_gr_rr =
	    uDIGIT_FITTING (gain * r / gr, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_gr_bb =
	    uDIGIT_FITTING (gain * b / gr, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_gb_bb =
	    uDIGIT_FITTING (gain * b / gb, 8, SH_CSS_DP_GAIN_SHIFT);
	to->coef_gb_rr =
	    uDIGIT_FITTING (gain * r / gb, 8, SH_CSS_DP_GAIN_SHIFT);
}

void
ia_css_dp_dump(
	const struct sh_css_isp_dp_params *dp,
	unsigned level)
{
	ia_css_debug_dtrace(level, "Defect Pixel Correction:\n");
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dp_threshold_single_w_2adj_on",
		dp->threshold_single);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dp_threshold_2adj_w_2adj_on",
		dp->threshold_2adjacent);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dp_gain", dp->gain);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_rr_gr", dp->coef_rr_gr);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_rr_gb", dp->coef_rr_gb);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_bb_gb", dp->coef_bb_gb);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_bb_gr", dp->coef_bb_gr);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_gr_rr", dp->coef_gr_rr);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_gr_bb", dp->coef_gr_bb);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_gb_bb", dp->coef_gb_bb);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"dpc_coef_gb_rr", dp->coef_gb_rr);
}

void
ia_css_dp_debug_dtrace(
	const struct ia_css_dp_config *config,
	unsigned level)
{
	ia_css_debug_dtrace(level,
		"config.threshold=%d, config.gain=%d\n",
		config->threshold, config->gain);
}
