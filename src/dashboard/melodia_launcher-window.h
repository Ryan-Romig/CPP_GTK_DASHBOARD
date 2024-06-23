
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MELODIA_LAUNCHER_TYPE_WINDOW (melodia_launcher_window_get_type())

G_DECLARE_FINAL_TYPE (MelodiaLauncherWindow, melodia_launcher_window, MELODIA_LAUNCHER, WINDOW, GtkApplicationWindow)

G_END_DECLS
