#include "stack_manager.h"

// The singleton instance of StackManager
static StackManager *instance = NULL;

// Get the singleton instance of StackManager
StackManager *stack_manager_get_instance() {
  if (instance == NULL) {
    instance = g_new0(StackManager, 1);
    // Initialize the GtkStack here
    instance->stack = GTK_STACK(gtk_stack_new());
  }
  return instance;
}

// Add a widget to the stack
void stack_manager_add_widget(StackManager *self, GtkWidget *widget, const char *id, const char *title) {
  gtk_stack_add_titled(self->stack, widget, id, title);
}

// Show a widget in the stack
void stack_manager_show_widget(StackManager *self, const char *id) {
  gtk_stack_set_visible_child_name(self->stack, id);
}

// Get the GtkStack
GtkStack *stack_manager_get_stack(StackManager *self) {
  return self->stack;
}