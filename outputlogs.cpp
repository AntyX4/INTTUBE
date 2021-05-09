#include "outputlogs.h"

outputlogs::outputlogs(QWidget* parent) : QDialog(parent)
{
    int x = 525;
    int y = 100;
    setStyleSheet("QDialog {background: 'white';}");
    setFixedSize(x, y);

    logi = new QTextEdit(this);
    logi->setGeometry(0, 0, 525, 200);
    logi->setReadOnly(true);

    const QIcon logoprogram(":/new/YT-Downloader/Youtube-512.png");
    setWindowIcon(logoprogram);
}

outputlogs::~outputlogs()
{

}

void outputlogs::setText(QString text)
{
    logi->document()->setPlainText(text);
}

void outputlogs::setYtdl(QProcess* ytdl)
{
    this->ytdl = ytdl;
}

void outputlogs::setSpotDL(QProcess* spotdl)
{
    this->spotdl = spotdl;
}

void outputlogs::readyRead()
{
    logi->document()->setPlainText(this->ytdl->readAll());
}

void outputlogs::readyReadSpotify()
{
    logi->document()->setPlainText(this->spotdl->readAll());
}

void outputlogs::downloadFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::NormalExit)
        this->close();
}

//Program inspired by rrooij
