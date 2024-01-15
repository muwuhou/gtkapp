#include <gtk/gtk.h>
#include <glib/gprintf.h>


const char* my_pango_text = " \
<big> \
Hello <b>there</b>, the <span foreground=\"blue\" size=\"x-large\">Pango text</span> is really <i>cool</i>, do you <u>agree</u>? \
</big> \
";

static void
print_hello (GtkWidget *widget, gpointer data)
{
  g_printf("you clicked: %s\n", (char*)data);
}

GtkWidget* create_top_right()
{
  GtkWidget *topRightBox, *button1, *button2, *button3;
  topRightBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
  button1 = gtk_button_new_with_label("Click me!");
  button2 = gtk_button_new_with_label("Run");
  button3 = gtk_button_new_with_label("Cancel");
  gtk_box_append(GTK_BOX(topRightBox), button1);
  gtk_box_append(GTK_BOX(topRightBox), button2);
  gtk_box_append(GTK_BOX(topRightBox), button3);
  gtk_widget_set_margin_end(topRightBox, 10);
  gtk_widget_set_margin_top(topRightBox, 10);
  gtk_widget_set_margin_bottom(topRightBox, 10);
  return topRightBox;
}

GtkWidget* create_top()
{
  GtkWidget* topBox, *textView, *topRightBox;
  GtkTextBuffer* buffer;

  topBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
  textView  = gtk_text_view_new();
  buffer = gtk_text_buffer_new(NULL);
  gtk_text_buffer_set_text(buffer, "hello world!", -1);
  gtk_text_view_set_buffer(GTK_TEXT_VIEW(textView), buffer);

  gtk_widget_set_size_request(textView, 100, 200);
  gtk_widget_set_margin_start(textView, 10);
  gtk_widget_set_margin_end(textView, 10);
  gtk_widget_set_margin_top(textView, 10);
  gtk_widget_set_margin_bottom(textView, 10);
  gtk_widget_set_hexpand(textView, true);


  topRightBox = create_top_right();
  gtk_box_append(GTK_BOX(topBox), textView);
  gtk_box_append(GTK_BOX(topBox), topRightBox);
  return topBox;
}

GtkWidget* create_middle()
{
  GtkWidget* label;

  label = gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label), my_pango_text);
  gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
  gtk_widget_set_vexpand(label, true);
  return label;
}

GtkWidget* create_bottom_bar()
{
  GtkWidget* bottomBox, *button1, *button2;

  bottomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  button1 = gtk_button_new_with_label("Hello");
  gtk_widget_set_margin_start(button1, 5);
  gtk_widget_set_margin_bottom(button1, 5);
  g_signal_connect(button1, "clicked", G_CALLBACK (print_hello), "hello!");

  button2 = gtk_button_new_with_label("Go!");
  gtk_widget_set_margin_start(button2, 5);
  gtk_widget_set_margin_bottom(button2, 5);
  gtk_widget_set_margin_end(button2, 5);
  g_signal_connect(button2, "clicked", G_CALLBACK (print_hello), "Go!");

  gtk_box_append(GTK_BOX(bottomBox), button1);
  gtk_box_append(GTK_BOX(bottomBox), button2);

  gtk_widget_set_halign(bottomBox, GTK_ALIGN_END);
  gtk_widget_set_valign(bottomBox, GTK_ALIGN_END);
  return bottomBox;
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *box;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Hello");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_append(GTK_BOX(box), create_top());
  gtk_box_append(GTK_BOX(box), create_middle());
  gtk_box_append(GTK_BOX(box), create_bottom_bar());
  gtk_window_set_child(GTK_WINDOW(window), box);
  gtk_widget_set_size_request(window, 500, 400);

  gtk_window_present(GTK_WINDOW(window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
