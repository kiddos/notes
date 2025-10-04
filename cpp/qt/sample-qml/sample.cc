#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);
  using namespace Qt::StringLiterals;
  const QUrl url(u"qrc:/sample.qml"_s);
  // If sample.qml is in the same directory as executable
  // const QUrl url(QStringLiteral("sample.qml"));

  QQmlApplicationEngine engine;
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
