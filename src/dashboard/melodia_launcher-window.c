
#include "../app/melodia_launcher-application.h"
#include "melodia_launcher-window.h"

struct _MelodiaLauncherWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  // GtkHeaderBar        *header_bar;
  // GtkLabel            *label;
};

G_DEFINE_TYPE (MelodiaLauncherWindow, melodia_launcher_window, GTK_TYPE_APPLICATION_WINDOW)

static void
melodia_launcher_window_class_init (MelodiaLauncherWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/melodia/launcher/ui/dashboard.ui");
  // gtk_widget_class_bind_template_child (widget_class, MelodiaLauncherWindow, header_bar);
  // gtk_widget_class_bind_template_child (widget_class, MelodiaLauncherWindow, label);
}

static void
melodia_launcher_window_init (MelodiaLauncherWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
