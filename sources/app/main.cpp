#include <QApplication>

#include <QBoxLayout>
#include <QLabel>
#include <QWidget>

#include <memory>

#include <SomeLib/SomeLibFile.h>

int main(int argc, char *argv[]) {
  QApplication qApplication(argc, argv);

  // Must be set after creating a QApplication.
  QGuiApplication::setApplicationDisplayName("ProjectTemplate");
  QCoreApplication::setApplicationName("ProjectTemplate");
  QGuiApplication::setDesktopFileName("ProjectTemplate");
  QCoreApplication::setOrganizationName("Example");
  QCoreApplication::setOrganizationDomain("example.com");
  QCoreApplication::setApplicationVersion("0.1.0");
  QApplication::setHighDpiScaleFactorRoundingPolicy(
      Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

  // Create the window.
  auto window = std::make_unique<QWidget>();
  window->setMinimumSize(320, 240);
  auto *layout = new QVBoxLayout(window.get());
  layout->setAlignment(Qt::AlignCenter);

  auto *label = new QLabel(somelib::someStringOperation(), window.get());
  layout->addWidget(label);

  // Show the window.
  window->show();

  return qApplication.exec();
}
