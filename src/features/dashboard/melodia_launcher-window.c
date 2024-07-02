
#include "../../app/melodia_launcher-application.h"
#include "melodia_launcher-window.h"
#include "../stack_manager/stack_manager.h"

struct _MelodiaLauncherWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  // GtkHeaderBar        *header_bar;
  GtkBox            *main_box;
};

G_DEFINE_TYPE (MelodiaLauncherWindow, melodia_launcher_window, GTK_TYPE_APPLICATION_WINDOW)

static void
melodia_launcher_window_class_init (MelodiaLauncherWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/melodia/launcher/ui/main-window.ui");
  
  gtk_widget_class_bind_template_child (widget_class, MelodiaLauncherWindow, main_box);
}
// Function to handle button click event
static void on_button_clicked(GtkButton *button, gpointer user_data)
{
  StackManager *stack_manager = stack_manager_get_instance();
  GtkStack *stack = stack_manager_get_stack(stack_manager);
  gtk_stack_set_visible_child_name(stack, "box_id2");
}
static void
melodia_launcher_window_init (MelodiaLauncherWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  
  
  // Create a new GtkBox
  GtkBox *box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
  GtkBox *box2 = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
    // Create a new label
  GtkLabel *label = gtk_label_new("Hello, World!");

  GtkLabel *label2 = gtk_label_new("Hello, World!2");

  GtkButton *button = gtk_button_new_with_label("Click me!"); // Create a new button
  
  g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL); // Connect the "clicked" signal to the on_button_clicked function
  gtk_box_append(GTK_BOX(box), GTK_WIDGET(button)); // Add the button to the box

  // Add the label to the box
  gtk_box_append(GTK_BOX(box), GTK_WIDGET(label));


  // Add the GtkBox to the GtkStack
  StackManager *stack_manager = stack_manager_get_instance();
  GtkStack *stack = stack_manager_get_stack(stack_manager);

  gtk_stack_add_titled (stack, GTK_WIDGET(box), "box_id", "Box Title");
  gtk_stack_add_titled (stack, GTK_WIDGET(box2), "box_id2", "Box Title2");

  // Add the stack to the main box
  gtk_box_append(GTK_BOX(self->main_box), GTK_WIDGET(stack));

  gtk_stack_set_visible_child_name(stack, "box_id");
}
