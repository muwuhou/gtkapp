#include <gtk/gtk.h>

static GtkCssProvider*
load_css(const char* css_file)
{
  GtkCssProvider* provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(provider, css_file);
  return provider;
}


static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *title, *subtitle, *button, *box;

  gtk_style_context_add_provider_for_display(
    gdk_display_get_default(),
    GTK_STYLE_PROVIDER(load_css("new-style.css")),
    GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
  );

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Hello");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);

  
  title = gtk_label_new("hello!");
  gtk_widget_add_css_class(title, "title");
  gtk_label_set_wrap(GTK_LABEL(title), true);
  gtk_label_set_wrap_mode(GTK_LABEL(title), PANGO_WRAP_WORD_CHAR);
  gtk_label_set_xalign(GTK_LABEL(title), 0);
  gtk_label_set_yalign(GTK_LABEL(title), 0);

  subtitle = gtk_label_new("this looks like an html page!");
  gtk_widget_add_css_class(subtitle, "subtitle");
  gtk_label_set_wrap(GTK_LABEL(subtitle), true);
  gtk_label_set_wrap_mode(GTK_LABEL(subtitle), PANGO_WRAP_WORD_CHAR);
  gtk_label_set_xalign(GTK_LABEL(subtitle), 0);
  gtk_label_set_yalign(GTK_LABEL(subtitle), 0);

  button = gtk_button_new_with_label("Close");
  gtk_widget_set_halign(button, GTK_ALIGN_START);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_append(GTK_BOX(box), title);
  gtk_box_append(GTK_BOX(box), subtitle);
  gtk_box_append(GTK_BOX(box), button);



  gtk_window_set_child (GTK_WINDOW (window), box);

  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.cssdemo", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
