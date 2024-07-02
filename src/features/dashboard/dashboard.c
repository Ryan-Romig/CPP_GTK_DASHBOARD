#include "dashboard.h"
struct _DashboardPage {
    GtkWidget parent_type;

    GtkLabel *label;
    GtkButton *button;
};

G_DEFINE_TYPE(DashboardPage, dashboard_page, GTK_TYPE_BOX)

void handle_button_click(GtkButton *button, gpointer user_data)
{
    // Open Firefox
    #include <stdlib.h>

    // Open Chrome
    system("/opt/google/chrome/google-chrome --start-maximized --start-fullscreen --kiosk --profile-directory=Default --app-id=pjibgclleladliembfgfagdaldikeohf" );
}
static void dashboard_page_class_init(DashboardPageClass* klass)
{
    GtkWidgetClass* widget_class = GTK_WIDGET_CLASS(klass);

    gtk_widget_class_set_template_from_resource(widget_class, "/com/melodia/launcher/ui/dashboard.ui");
    gtk_widget_class_bind_template_child(widget_class, DashboardPage, label);
    gtk_widget_class_bind_template_child(widget_class, DashboardPage, button);
}
static void dashboard_page_init(DashboardPage* self) 
{ 
    gtk_widget_init_template(GTK_WIDGET(self));    
    g_signal_connect(self->button, "clicked", G_CALLBACK(handle_button_click), NULL);

}