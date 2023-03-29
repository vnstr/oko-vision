#include "main_window.h"

#include <QDesktopServices>
#include <QFontDatabase>
#include <QScrollBar>
#include <QUrl>
#include <cassert>

#include "ui/ui_main_window.h"

namespace Oko {

static void LoadFont() {
  const char *kFont = ":/fonts/SixCaps/SixCaps-Regular.ttf";
  auto id = QFontDatabase::addApplicationFont(kFont);
  assert(id != -1);
}

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags), ui_(std::make_unique<Ui::MainWindow>()) {
  ui_->setupUi(this);

  connect(ui_->watchVideoButton, &QPushButton::clicked, this,
          &MainWindow::OnWatchVideoClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::Prepare() {
  constexpr int kHScrollValue = 117;

  LoadFont();

  setFixedSize(kWidth_, kHeight_);
  ui_->scrollArea->horizontalScrollBar()->setValue(kHScrollValue);
}

void MainWindow::OnWatchVideoClicked() {
  QDesktopServices::openUrl(QUrl("https://www.youtube.com/@okovision4395"));
}

}  // namespace Oko
