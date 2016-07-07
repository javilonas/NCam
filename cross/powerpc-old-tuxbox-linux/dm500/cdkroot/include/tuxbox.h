/*
 * tuxbox.h - TuxBox hardware info
 *
 * Copyright (C) 2003 Florian Schirmer <jolt@tuxbox.org>
 *                    Bastian Blank <waldi@tuxbox.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * $Id: tuxbox.h,v 1.5.2.2 2003/03/09 16:26:41 waldi Exp $
 */

#ifndef TUXBOX_H
#define TUXBOX_H

#include <tuxbox/info.h>

#ifdef __cplusplus
extern "C" {
#endif

int tuxbox_read_proc (char *type);

tuxbox_capabilities_t tuxbox_get_capabilities (void);
tuxbox_model_t tuxbox_get_model (void);
const char *tuxbox_get_model_str (void);
tuxbox_submodel_t tuxbox_get_submodel (void);
const char *tuxbox_get_submodel_str (void);
tuxbox_vendor_t tuxbox_get_vendor (void);
const char *tuxbox_get_vendor_str (void);

#ifdef __cplusplus
}
#endif

#endif /* TUXBOX_H */

#if defined(need_TUXBOX_GET) && !defined(TUXBOX_GET)
#define TUXBOX_GET(type) \
tuxbox_##type##_t tuxbox_get_##type (void) \
{ \
	static tuxbox_##type##_t tuxbox_##type; \
	if (!tuxbox_##type) \
		tuxbox_##type = (tuxbox_##type##_t) tuxbox_read_proc (#type); \
	return tuxbox_##type; \
}
#endif /* need_TUXBOX_GET && !TUXBOX_GET */

