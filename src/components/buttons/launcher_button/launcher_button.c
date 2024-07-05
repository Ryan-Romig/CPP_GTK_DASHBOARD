#include "launcher_button.h"
struct _LauncherButton {
    GtkWidget parent_type;
};

G_DEFINE_TYPE(LauncherButton, launcher_button, GTK_TYPE_BUTTON)

static void launcher_button_class_init(LauncherButtonClass* klass)
{
    GtkWidgetClass* widget_class = GTK_WIDGET_CLASS(klass);

    gtk_widget_class_set_template_from_resource(widget_class, "/com/melodia/launcher/ui/components/launcher_button.ui");


}
static void launcher_button_init(LauncherButton* self) { gtk_widget_init_template(GTK_WIDGET(self)); }