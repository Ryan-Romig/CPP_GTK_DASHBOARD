
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MELODIA_LAUNCHER_TYPE_APPLICATION (melodia_launcher_application_get_type())

G_DECLARE_FINAL_TYPE (MelodiaLauncherApplication, melodia_launcher_application, MELODIA_LAUNCHER, APPLICATION, GtkApplication)

MelodiaLauncherApplication *melodia_launcher_application_new (gchar *application_id,
                                                              GApplicationFlags  flags);

G_END_DECLS
