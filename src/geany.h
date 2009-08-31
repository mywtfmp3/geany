/*
 *      geany.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2005-2009 Enrico Tröger <enrico(dot)troeger(at)uvena(dot)de>
 *      Copyright 2006-2009 Nick Treleaven <nick(dot)treleaven(at)btinternet(dot)com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $Id$
 */

/* Main header - should be included first in all source files.
 * externs and function prototypes are implemented in main.c. */

#ifndef GEANY_H
#define GEANY_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "tm_tagmanager.h"

#ifndef PLAT_GTK
#   define PLAT_GTK 1	/* needed when including ScintillaWidget.h */
#endif

/* Compatibility for sharing macros between API and core, overridden in plugindata.h */
#define GEANY(symbol_name) symbol_name


/* for detailed description look in the documentation, things are not
 * listed in the documentation should not be changed */
#define GEANY_FILEDEFS_SUBDIR			"filedefs"
#define GEANY_TEMPLATES_SUBDIR			"templates"
#define GEANY_CODENAME					"Vellam"
#define GEANY_HOMEPAGE					"http://www.geany.org/"
#define GEANY_USE_WIN32_DIALOG			0
#define GEANY_STRING_UNTITLED			_("untitled")
#define GEANY_WINDOW_MINIMAL_WIDTH		550
#define GEANY_WINDOW_MINIMAL_HEIGHT		350
#define GEANY_WINDOW_DEFAULT_WIDTH		900
#define GEANY_WINDOW_DEFAULT_HEIGHT		600


/* Common forward declarations */
typedef struct GeanyDocument GeanyDocument;
typedef struct GeanyEditor GeanyEditor;
typedef struct GeanyFiletype GeanyFiletype;


/** Important application fields. */
typedef struct GeanyApp
{
	gboolean			debug_mode;		/**< @c TRUE if debug messages should be printed. */
	/** User configuration directory, usually @c ~/.config/geany.
	 * This is a full path read by @ref tm_get_real_path().
	 * @note Plugin configuration files should be saved as:
	 * @code g_build_path(G_DIR_SEPARATOR_S, geany->app->configdir, "plugins", "pluginname",
	 * 	"file.conf"); @endcode */
	gchar				*configdir;
	gchar				*datadir;
	gchar				*docdir;
	const TMWorkspace	*tm_workspace;	/**< TagManager workspace/session tags. */
	struct GeanyProject	*project;		/**< Currently active project or @c NULL if none is open. */
}
GeanyApp;

extern GeanyApp *app;

extern GObject *geany_object;


extern gboolean	ignore_callback;


/* prototype is here so that all files can use it. */
void geany_debug(gchar const *format, ...) G_GNUC_PRINTF (1, 2);


#ifndef G_GNUC_WARN_UNUSED_RESULT
#define G_GNUC_WARN_UNUSED_RESULT
#endif

#endif
