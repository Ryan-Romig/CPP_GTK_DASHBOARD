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
static void launcher_button_init(LauncherButton* self)
{

    gtk_widget_init_template(GTK_WIDGET(self));
    GtkCssProvider* provider = gtk_css_provider_new();
    gtk_css_provider_load_from_resource(provider, "/com/melodia/launcher/ui/styles/launcher_button.css");
    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_widget_set_halign(self, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(self, GTK_ALIGN_CENTER);

    //set the height and width of the button
    gtk_widget_set_size_request(GTK_WIDGET(self), 200, 200);
    
}