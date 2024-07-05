
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define LAUNCHER_BUTTON_TYPE (launcher_button_get_type())

G_DECLARE_FINAL_TYPE (LauncherButton, launcher_button, LAUNCHER_BUTTON, WIDGET, GtkButton)

G_END_DECLS