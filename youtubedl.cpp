#include "youtubedl.h"

youtubedl::youtubedl()
{
    program = QApplication::applicationDirPath() + "/youtube-dl.exe";
    QObject* parent = QApplication::instance();
    ytdl = new QProcess(parent);
    ytdl->setProcessChannelMode(QProcess::MergedChannels);
}

bool youtubedl::isValidUrl(QString url)
{
    QRegularExpression urlRegex("^(http|https)://[a-z0-9]+([-.]{1}[a-z0-9]+)*.[a-z]{2,5}(([0-9]{1,5})?/?.*)$");
    QRegularExpressionValidator validator(urlRegex);
    int index = 0;

    if (validator.validate(url, index) == QValidator::Acceptable) {
        return true;
    }
    return false;
}


void youtubedl::updateYoutubeDL()
{
    arguments << "-U";
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoBestMP4(QString url, QString workingDirectory)
{
    arguments << "-f" << "bestvideo+bestaudio[ext=m4a]/bestvideo+bestaudio/best" << "--merge-output-format" << "mp4" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoMediumMP4(QString url, QString workingDirectory)
{
    arguments << "-f" << "worst" << "--merge-output-format" << "mp4" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoWorstMP4(QString url, QString workingDirectory)
{
    arguments << "-f" << "worstvideo+worstaudio[ext=m4a]/worstvideo+worstaudio/worst" << "--merge-output-format" << "mp4" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoBestMKV(QString url, QString workingDirectory)
{
    arguments << "-f" << "bestvideo+bestaudio[ext=m4a]/bestvideo+bestaudio/best" << "--merge-output-format" << "mkv" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoMediumMKV(QString url, QString workingDirectory)
{
    arguments << "-f" << "worst" << "-o" << "%(title)s.mkv" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoWorstMKV(QString url, QString workingDirectory)
{
    arguments << "-f" << "worstvideo+worstaudio" << "--merge-output-format" << "mkv" << "-o" << "%(title)s.mkv" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoBestWEBM(QString url, QString workingDirectory)
{
    arguments << "-f" << "bestvideo[ext=webm]+bestaudio[ext=webm]/best" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoMediumWEBM(QString url, QString workingDirectory)
{
    arguments << "-f" << "worst" << "-o" << "%(title)s.webm" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadVideoWorstWEBM(QString url, QString workingDirectory)
{
    arguments << "-f" << "worstvideo[ext=webm]+worstaudio[ext=webm]/worst" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}


void youtubedl::startDownloadBestMP3(QString url, QString workingDirectory)
{
    arguments << "-f" << "bestaudio" << "--extract-audio" << "--audio-format" << "mp3" << "--audio-quality" << "0" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadMediumMP3(QString url, QString workingDirectory)
{
    arguments << "-f" << "bestaudio" << "--extract-audio" << "--audio-format" << "mp3" << "--audio-quality" << "5" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

void youtubedl::startDownloadWorstMP3(QString url, QString workingDirectory)
{
    arguments << "-f" << "bestaudio" << "--extract-audio" << "--audio-format" << "mp3" << "--audio-quality" << "9" << "-o" << "%(title)s.%(ext)s" << url;
    ytdl->setWorkingDirectory(workingDirectory);
    ytdl->start(program, arguments);
}

QProcess* youtubedl::getYtdl()
{
    return ytdl;
}

//Program inspired by rrooij
