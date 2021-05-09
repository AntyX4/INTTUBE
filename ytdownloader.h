#ifndef YTDOWNLOADER_H
#define YTDOWNLOADER_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include "youtubedl.h"
#include "outputlogs.h"
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class YTDownloader; }
QT_END_NAMESPACE

class YTDownloader : public QMainWindow
{
    Q_OBJECT

public:
    YTDownloader(QWidget *parent = nullptr);
    ~YTDownloader();

private:
    Ui::YTDownloader *ui;

public slots:
    //YoutubeDownloader
    void VideoChange(bool checked);
    void MP3Change(bool checked);
    void DownloadThis();
    void updateThisProgram();
    void endDownloadNotification(int exitCode, QProcess::ExitStatus exitStatus);

    //Update
    void endUpdate(int exitCode, QProcess::ExitStatus exitStatus);
};
#endif // YTDOWNLOADER_H
