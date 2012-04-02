/* Copyright © 2012 Brandon L Black <blblack@gmail.com>
 *
 * This file is part of gdnsd-plugin-geoip.
 *
 * gdnsd-plugin-geoip is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * gdnsd-plugin-geoip is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gdnsd.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GDMAPS_H
#define GDMAPS_H

#include "config.h"
#include <inttypes.h>
#include <gdnsd-vscf.h>
#include <gdnsd-plugapi.h>

static const char GEOIP_DIR[] = "etc/geoip/";

typedef struct _gdmaps_t gdmaps_t;
typedef void (*gdmaps_iter_dclists_cb_t)(const uint8_t* dclist, void* data);

F_NONNULL
gdmaps_t* gdmaps_new(const vscf_data_t* maps_cfg);
F_NONNULL
void gdmaps_load_geoip_databases(gdmaps_t* gdmaps);
F_NONNULL
int gdmaps_name2idx(const gdmaps_t* gdmaps, const char* map_name);
F_NONNULL
const char* gdmaps_idx2name(const gdmaps_t* gdmaps, const unsigned gdmap_idx);
F_NONNULL
unsigned gdmaps_get_dc_count(const gdmaps_t* gdmaps, const unsigned gdmap_idx);
F_NONNULL
unsigned gdmaps_dcname2num(const gdmaps_t* gdmaps, const unsigned gdmap_idx, const char* dcname);
F_NONNULL
const char* gdmaps_dcnum2name(const gdmaps_t* gdmaps, const unsigned gdmap_idx, const unsigned dcnum);
F_NONNULL
const char* gdmaps_logf_dclist(const gdmaps_t* gdmaps, const unsigned gdmap_idx, const uint8_t* dclist);
F_NONNULLX(1,3)
void gdmaps_iter_dclists(const gdmaps_t* gdmaps, const unsigned gdmap_idx, gdmaps_iter_dclists_cb_t f, void* data);
F_NONNULL
const uint8_t* gdmaps_lookup(const gdmaps_t* gdmaps, const unsigned gdmap_idx, const client_info_t* client, unsigned* scope_mask);
F_NONNULL
void gdmaps_setup_geoip_watcher_paths(gdmaps_t* gdmaps);
F_NONNULL
void gdmaps_setup_geoip_watchers(gdmaps_t* gdmaps);
F_NONNULL
void gdmaps_destroy(gdmaps_t* gdmaps);

#endif // GDMAPS_H
