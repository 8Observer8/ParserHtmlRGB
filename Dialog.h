#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Downloader.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_getColorsPushButton_clicked();
    void showData( QString *content );
    void replyProgress( qint64 bytesReceived, qint64 bytesTotal );

private:
    Ui::Dialog *ui;
    Downloader m_downloader;
};

#endif // DIALOG_H
