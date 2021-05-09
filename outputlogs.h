#include <QProcess>
#include <QDialog>
#include <QTextEdit>
#include <QMessageBox>
#include <QIcon>

class outputlogs : public QDialog
{
    Q_OBJECT

public:
    explicit outputlogs(QWidget* parent = 0);
    ~outputlogs();
    void setText(QString text);

    void setYtdl(QProcess* ytdl);
    void setSpotDL(QProcess* spotdl);
    QTextEdit* logi;

public slots:
    void readyRead();
    void readyReadSpotify();
    void downloadFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QProcess* ytdl;
    QProcess* spotdl;

};

//Program inspired by rrooij
