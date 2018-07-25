/*
 * Copyright (C) 2018  Elvis Teixeira
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SLP_GLOBAL_H
#define SLP_GLOBAL_H

#include "slope/platform.h"
#include <glib.h>

#define slp_enabled(X,BIT) (((X) & (BIT)) == (BIT))
#define slp_enable(X,BIT)  (X) |= (BIT)
#define slp_disable(X,BIT)  (X) &= ~(BIT)

#endif /* SLP_GLOBAL_H */
