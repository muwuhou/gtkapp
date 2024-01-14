#include <gtkmm.h>


class MyWindow: public Gtk::Window {
public:
    MyWindow();
};

MyWindow::MyWindow()
{
    set_title("hello world");
    set_default_size(200, 200);
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("my.gtkmm.helloworld");
    return app->make_window_and_run<MyWindow>(argc, argv);
}