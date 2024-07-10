#include "dashboard.h"
#include "../../src/components/buttons/launcher_button/launcher_button.h"
struct _DashboardPage {
    GtkWidget parent_type;
};

G_DEFINE_TYPE(DashboardPage, dashboard_page, GTK_TYPE_BOX)

void handle_button_click(GtkButton* button, gpointer user_data)
{
#include <stdlib.h>

    // Open Chrome
    int status
        = system("google-chrome --start-maximized  --kiosk --profile-directory=Default --app=https://www.spotify.com");
    printf("status: %d\n", status);
}
void handle_button_click2(GtkButton* button, gpointer user_data)
{
#include <stdlib.h>

    // Open Chrome
    int status
        = system("google-chrome --start-maximized  --kiosk --profile-directory=Default --app=https://www.tidal.com");
    printf("status: %d\n", status);
}
void handle_button_click3(GtkButton* button, gpointer user_data)
{
#include <stdlib.h>

    // Open Chrome
    int status
        = system("google-chrome --disable-gpu --start-maximized  --kiosk --profile-directory=Default --app=https://www.pandora.com");
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


    //create a new launcher button
    LauncherButton* launcher_button2 = g_object_new(LAUNCHER_BUTTON_TYPE, NULL);
    //set the text of the button
    gtk_button_set_label(GTK_BUTTON(launcher_button2), "Tidal");
    //attach click event function to button click event
    g_signal_connect(launcher_button2, "clicked", G_CALLBACK(handle_button_click2), NULL);



    //create a new launcher button
    LauncherButton* launcher_button3 = g_object_new(LAUNCHER_BUTTON_TYPE, NULL);
    //set the text of the button
    gtk_button_set_label(GTK_BUTTON(launcher_button3), "Pandora");
    //attach click event function to button click event
    g_signal_connect(launcher_button3, "clicked", G_CALLBACK(handle_button_click3), NULL);



    //set to expand to fill the parent container
    gtk_widget_set_hexpand(self, TRUE);
    gtk_widget_set_vexpand(self, TRUE);



    //set the spacing between the children
    gtk_box_set_spacing(GTK_BOX(self), 10);

    //set orentation of box to vertical
    gtk_orientable_set_orientation(GTK_ORIENTABLE(self), GTK_ORIENTATION_VERTICAL);  // Set the box orientation

    //add the button to the the box
    gtk_box_append(GTK_BOX(self), GTK_BUTTON(launcher_button));
    gtk_box_append(GTK_BOX(self), GTK_BUTTON(launcher_button2));
    gtk_box_append(GTK_BOX(self), GTK_BUTTON(launcher_button3));
}