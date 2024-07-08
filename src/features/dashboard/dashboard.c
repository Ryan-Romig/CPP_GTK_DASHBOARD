#include "dashboard.h"
#include "../../src/components/buttons/launcher_button/launcher_button.h"
struct _DashboardPage {
    GtkWidget parent_type;
};

G_DEFINE_TYPE(DashboardPage, dashboard_page, GTK_TYPE_BOX)

void handle_button_click(GtkButton* button, gpointer user_data)
{
// Open Firefox
#include <stdlib.h>

    // Open Chrome
    int status
        = system("google-chrome --start-maximized  --kiosk --profile-directory=Default --app=https://www.spotify.com");
    printf("status: %d\n", status);
}
static void dashboard_page_class_init(DashboardPageClass* klass)
{
    GtkWidgetClass* widget_class = GTK_WIDGET_CLASS(klass);

    gtk_widget_class_set_template_from_resource(widget_class, "/com/melodia/launcher/ui/pages/dashboard.ui");
}
static void dashboard_page_init(DashboardPage* self)
{
    gtk_widget_init_template(GTK_WIDGET(self));

    //attach css stylesheet to the current display
    GtkCssProvider* provider = gtk_css_provider_new();
    gtk_css_provider_load_from_resource(provider, "/com/melodia/launcher/ui/styles/dashboard.css");
    gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //create a new launcher button
    LauncherButton* launcher_button = g_object_new(LAUNCHER_BUTTON_TYPE, NULL);
    //set the text of the button
    gtk_button_set_label(GTK_BUTTON(launcher_button), "Spotify");
    //attach click event function to button click event
    g_signal_connect(launcher_button, "clicked", G_CALLBACK(handle_button_click), NULL);

    //set to expand to fill the parent container
    gtk_widget_set_hexpand(self, TRUE);
    gtk_widget_set_vexpand(self, TRUE);

    
    //add the button to the the box
    gtk_box_append(GTK_BOX(self), GTK_BUTTON(launcher_button));
}