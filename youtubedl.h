#include <QProcess>
#include <QApplication>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

class youtubedl
{
public:
    youtubedl();
    QProcess* getYtdl();
    static bool isValidUrl(QString url);

    //Wideo
    void startDownloadVideoBestMP4(QString url, QString workingDirectory);
    void startDownloadVideoMediumMP4(QString url, QString workingDirectory);
    void startDownloadVideoWorstMP4(QString url, QString workingDirectory);
    void startDownloadVideoBestMKV(QString url, QString workingDirectory);
    void startDownloadVideoMediumMKV(QString url, QString workingDirectory);
    void startDownloadVideoWorstMKV(QString url, QString workingDirectory);
    void startDownloadVideoBestWEBM(QString url, QString workingDirectory);
    void startDownloadVideoMediumWEBM(QString url, QString workingDirectory);
    void startDownloadVideoWorstWEBM(QString url, QString workingDirectory);

    //MP3
    void startDownloadBestMP3(QString url, QString workingDirectory);
    void startDownloadMediumMP3(QString url, QString workingDirectory);
    void startDownloadWorstMP3(QString url, QString workingDirectory);

    //UPDATE
    void updateYoutubeDL();

private:
    QStringList arguments;
    QString program;
    QProcess* ytdl;
};

//Program inspired by rrooij
