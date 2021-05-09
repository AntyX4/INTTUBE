#include "ytdownloader.h"
#include "ui_ytdownloader.h"

YTDownloader::YTDownloader(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YTDownloader)
{
    ui->setupUi(this);
    this->setFixedSize(535, 142);

    connect(ui->Video, SIGNAL(clicked(bool)), this, SLOT(VideoChange(bool)));
    connect(ui->MP3, SIGNAL(clicked(bool)), this, SLOT(MP3Change(bool)));
    connect(ui->ApplyChange, SIGNAL(released()), this, SLOT(DownloadThis()));
    connect(ui->updateYoutubeDl, SIGNAL(released()), this, SLOT(updateThisProgram()));
}

YTDownloader::~YTDownloader()
{
    delete ui;
}

void YTDownloader::VideoChange(bool checked)
{
    if (checked)
    {
        ui->MP3->setEnabled(false);
        ui->viewQualityMP3->setEnabled(false);
    }
    else
    {
        ui->MP3->setEnabled(true);
        ui->viewQualityMP3->setEnabled(true);
    }
}

void YTDownloader::MP3Change(bool checked)
{
    if (checked)
    {
        ui->Video->setEnabled(false);
        ui->viewQualityVideo->setEnabled(false);
    }
    else
    {
        ui->Video->setEnabled(true);
        ui->viewQualityVideo->setEnabled(true);
    }
}

void YTDownloader::DownloadThis()
{
    if (!youtubedl::isValidUrl(ui->LinkedYoutube->text()))
    {
        QMessageBox::information(this, QString::fromLocal8Bit("Zly adres URL"), QString::fromLocal8Bit("Prosze wprowadzic prawidlowy adres."), QMessageBox::Ok);
        return;
    }

    if (!ui->Video->isChecked() && !ui->MP3->isChecked())
    {
        QMessageBox::information(this, tr("Brak zaznaczonego wyboru"), QString::fromLocal8Bit("Prosze wybrac tryb pobierania."), QMessageBox::Ok);
        return;
    }

    QString saveDirectory = QFileDialog::getExistingDirectory();
    if (!saveDirectory.isEmpty())
    {

        outputlogs* logged = new outputlogs();
        logged->show();
        youtubedl ytdl;

        logged->setYtdl(ytdl.getYtdl());
        logged->connect(ytdl.getYtdl(), SIGNAL(readyRead()), logged, SLOT(readyRead()));
        logged->connect(ytdl.getYtdl(), SIGNAL(finished(int, QProcess::ExitStatus)), logged, SLOT(downloadFinished(int, QProcess::ExitStatus)));

        if (ui->Video->isChecked())
        {
            int index = ui->viewQualityVideo->currentIndex();
            switch (index)
            {
                case 0:
                    ytdl.startDownloadVideoBestMP4(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 1:
                    ytdl.startDownloadVideoBestMKV(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 2:
                    ytdl.startDownloadVideoBestWEBM(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 3:
                    ytdl.startDownloadVideoMediumMP4(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 4:
                    ytdl.startDownloadVideoMediumMKV(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 5:
                    ytdl.startDownloadVideoMediumWEBM(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 6:
                    ytdl.startDownloadVideoWorstMP4(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 7:
                    ytdl.startDownloadVideoWorstMKV(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 8:
                    ytdl.startDownloadVideoWorstWEBM(ui->LinkedYoutube->text(), saveDirectory);
                    break;
            }
        }

        if (ui->MP3->isChecked())
        {
            int index = ui->viewQualityMP3->currentIndex();
            switch (index)
            {
                case 0:
                    ytdl.startDownloadBestMP3(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 1:
                    ytdl.startDownloadMediumMP3(ui->LinkedYoutube->text(), saveDirectory);
                    break;
                case 2:
                    ytdl.startDownloadWorstMP3(ui->LinkedYoutube->text(), saveDirectory);
                    break;
            }
        }

        connect(ytdl.getYtdl(), SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(endDownloadNotification(int, QProcess::ExitStatus)));

    }
}


void YTDownloader::endDownloadNotification(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::NormalExit)
        QMessageBox::information(this, QString::fromLocal8Bit("Youtube-DL"), QString::fromLocal8Bit("Pobieranie zakonczono sukcesem."), QMessageBox::Ok);
}

void YTDownloader::endUpdate(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::NormalExit)
        QMessageBox::information(this, QString::fromLocal8Bit("Youtube-DL"), QString::fromLocal8Bit("Aktualizacja zakonczona sukcesem."), QMessageBox::Ok);
}

void YTDownloader::updateThisProgram()
{
    outputlogs* logged = new outputlogs();
    logged->show();
    youtubedl ytdl;

    logged->setYtdl(ytdl.getYtdl());
    logged->connect(ytdl.getYtdl(), SIGNAL(readyRead()), logged, SLOT(readyRead()));
    logged->connect(ytdl.getYtdl(), SIGNAL(finished(int, QProcess::ExitStatus)), logged, SLOT(downloadFinished(int, QProcess::ExitStatus)));
    ytdl.updateYoutubeDL();
    connect(ytdl.getYtdl(), SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(endUpdate(int, QProcess::ExitStatus)));

}
