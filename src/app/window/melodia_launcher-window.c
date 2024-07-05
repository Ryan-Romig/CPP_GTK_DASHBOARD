
#include "../melodia_launcher-application.h"
#include "melodia_launcher-window.h"
#include "../../features/stack_manager/stack_manager.h"
#include "../../features/dashboard/dashboard.h"

struct _MelodiaLauncherWindow
{
  GtkApplicationWindow  parent_instance;
  /* Template widgets */
  GtkBox            *main_box;
};

G_DEFINE_TYPE (MelodiaLauncherWindow, melodia_launcher_window, GTK_TYPE_APPLICATION_WINDOW)

static void
melodia_launcher_window_class_init (MelodiaLauncherWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/melodia/launcher/ui/pages/main_window.ui");
  
  gtk_widget_class_bind_template_child (widget_class, MelodiaLauncherWindow, main_box);
}
// Function to handle button click event

static void
melodia_launcher_window_init (MelodiaLauncherWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  StackManager *stack_manager = stack_manager_get_instance();
  GtkStack *stack = stack_manager_get_stack(stack_manager);
  gtk_box_append(GTK_BOX(self->main_box), GTK_WIDGET(stack));

  DashboardPage *dashboard = g_object_new(DASHBOARD_PAGE_TYPE, NULL);


  gtk_stack_add_named(GTK_STACK(stack), GTK_WIDGET(dashboard), "dashboard");
  // gtk_widget_show(GTK_WIDGET(dashboard));
  // gtk_stack_set_visible_child_name(stack, "dashboard");

}
