#include <QApplication>

#include "main_window.h"

auto main(int argc, char **argv) -> int {
  QApplication app(argc, argv);

  Oko::MainWindow main_window;
  main_window.Prepare();
  main_window.show();

  return QApplication::exec();
}
