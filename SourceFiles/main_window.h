#ifndef SOURCEFILES_MAIN_WINDOW_H_
#define SOURCEFILES_MAIN_WINDOW_H_

#include <QMainWindow>
#include <memory>

namespace Ui {
class MainWindow;
}

namespace Oko {

class MainWindow final : public QMainWindow {
 public:
  MainWindow(QWidget *parent = nullptr,
             Qt::WindowFlags flags = Qt::WindowFlags());
  MainWindow(const MainWindow &) = delete;
  MainWindow(MainWindow &&) = delete;

  auto operator=(const MainWindow &) -> MainWindow& = delete;
  auto operator=(MainWindow &&) -> MainWindow& = delete;

  ~MainWindow();

  void Prepare();

 private slots:
  void OnWatchVideoClicked();

  static constexpr int kWidth_ = 800;
  static constexpr int kHeight_ = 700;

  std::unique_ptr<Ui::MainWindow> ui_;
};

}  // namespace Oko

#endif  // SOURCEFILES_MAIN_WINDOW_H_
