#include "ytdownloader.h"

#include <QApplication>
#include <QIcon>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YTDownloader w;
    const QIcon logoprogram(":/new/YT-Downloader/Youtube-512.png");
    w.setWindowIcon(logoprogram);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    w.show();
    return a.exec();
}
