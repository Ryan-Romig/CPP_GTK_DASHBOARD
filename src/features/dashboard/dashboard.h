
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define DASHBOARD_PAGE_TYPE (dashboard_page_get_type())

G_DECLARE_FINAL_TYPE (DashboardPage, dashboard_page, DASHBOARD_PAGE, WIDGET, GtkBox)

G_END_DECLS