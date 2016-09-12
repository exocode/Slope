/*
 * Copyright (C) 2016  Elvis Teixeira
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

#ifndef SLOPE_VIEW_H
#define SLOPE_VIEW_H

#include <gtk/gtk.h>
#include <slope/scene.h>

#define SLOPE_VIEW_TYPE              (slope_view_get_type())
#define SLOPE_VIEW(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj), SLOPE_VIEW_TYPE, SlopeView))
#define SLOPE_VIEW_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass), SLOPE_VIEW_TYPE, SlopeViewClass))
#define SLOPE_VIEW_GET_CLASS(obj)    (SLOPE_VIEW_CLASS(G_OBJECT_GET_CLASS(obj)))
#define SLOPE_IS_VIEW(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj), SLOPE_VIEW_TYPE))
#define SLOPE_IS_VIEW_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass), SLOPE_VIEW_TYPE))

SLOPE_BEGIN_DECLS

struct _SlopeView
{
  GtkDrawingArea parent;

  /* Padding to allow adding up to 4 members
     without breaking ABI. */
  gpointer padding[4];
};


typedef struct
_SlopeViewClass
{
  GtkDrawingAreaClass parent_class;

  void (*set_scene) (SlopeView *self, SlopeScene *scene, gboolean ownmem);

  /* Padding to allow adding up to 4 members
     without breaking ABI. */
  gpointer padding[4];
}
SlopeViewClass;


GType slope_view_get_type (void) G_GNUC_CONST;

GtkWidget* slope_view_new (void);

GtkWidget* slope_view_new_with_scene (SlopeScene *scene, gboolean ownmem);

void slope_view_set_scene (SlopeView *self, SlopeScene *scene, gboolean ownmem);

SlopeScene* slope_view_get_scene (SlopeScene *self);

void slope_view_write_to_png (SlopeView *self, const char *filename, int width, int height);

SLOPE_END_DECLS

#endif /* SLOPE_VIEW_H */
