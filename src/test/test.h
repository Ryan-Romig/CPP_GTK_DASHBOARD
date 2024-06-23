
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define TEST_TYPE_WINDOW (test_window_get_type())

G_DECLARE_FINAL_TYPE (TestWindow, test_window, TEST, WINDOW, GtkApplicationWindow)

G_END_DECLS
