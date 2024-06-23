
#include "../app/melodia_launcher-application.h"
#include "test.h"

struct _TestWindow
{
  GtkApplicationWindow  parent_instance;
};

G_DEFINE_TYPE (TestWindow, test_window, GTK_TYPE_APPLICATION_WINDOW)

static void
test_window_class_init (TestWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/melodia/launcher/ui/test.ui");
  gtk_widget_class_bind_template_child (widget_class, TestWindow, header_bar);
  // gtk_widget_class_bind_template_child (widget_class, MelodiaLauncherWindow, label);
}

static void
test_window_init (TestWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
