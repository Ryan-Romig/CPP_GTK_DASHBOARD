#ifndef STACK_MANAGER_H
#define STACK_MANAGER_H

#include <gtk/gtk.h>

typedef struct _StackManager {
  GtkStack *stack;
} StackManager;

StackManager *stack_manager_get_instance();
void stack_manager_add_widget(StackManager *self, GtkWidget *widget, const char *id, const char *title);
void stack_manager_show_widget(StackManager *self, const char *id);
GtkStack *stack_manager_get_stack(StackManager *self);

#endif 