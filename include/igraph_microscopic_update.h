/* -*- mode: C -*-  */
/*
  Microscopic update rules for dealing with agent-level strategy revision.
  Copyright (C) 2011 Minh Van Nguyen <nguyenminh2@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301 USA
*/

#ifndef IGRAPH_MICROSCOPIC_UPDATE_H
#define IGRAPH_MICROSCOPIC_UPDATE_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include "igraph_constants.h"
#include "igraph_datatype.h"
#include "igraph_iterators.h"
#include "igraph_types.h"
#include "igraph_vector.h"

__BEGIN_DECLS

int igraph_deterministic_optimal_imitation(const igraph_t *graph,
					   igraph_integer_t vid,
					   igraph_optimal_t optimality,
					   const igraph_vector_t *quantities,
					   igraph_vector_t *strategies,
					   igraph_neimode_t mode);

__END_DECLS

#endif
