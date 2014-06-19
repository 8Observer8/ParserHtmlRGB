#include <vector>

#include <QMessageBox>
#include <QDebug>

#include "Dialog.h"
#include "ui_Dialog.h"
#include "freeFunctions.h"
#include "LogicError.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect( &m_downloader, SIGNAL( signalWithContent( QString* ) ),
             this, SLOT( showData( QString* ) ) );
    connect( &m_downloader, SIGNAL( downloadProgress( qint64, qint64 ) ),
             this, SLOT( replyProgress( qint64, qint64 ) ) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_getColorsPushButton_clicked()
{
    QString url = ui->urlLineEdit->text( );
    if ( url.isEmpty( ) ) {
        QMessageBox::information( this, tr( "Error" ), "I need fill the url field" );
        return;
    }

    try {
        m_downloader.fetch( url );
    } catch ( const LogicError &e ) {
        QString errorText( e.what( ) );
        QMessageBox::information( this, tr( "Error" ), errorText );
        return;
    } catch ( ... ) {
        QMessageBox::information( this,
                                  tr( "Error" ),
                                  tr("Error: unknown exception in the function \
                                     Dialog::on_getColorsPushButton_clicked()") );
        return;
    }
}

void Dialog::showData( QString *content )
{
    std::vector<QString> colors;

    try {
        parseColors( *content, colors );
    } catch ( const LogicError &e ) {
        QString errorText( e.what( ) );
        QMessageBox::information( this, tr( "Error" ), errorText );
        return;
    } catch ( ... ) {
        QMessageBox::information( this,
                                  tr( "Error" ),
                                  tr("Error: unknown exception in \
                                     the function Dialog::showData()") );
        return;
    }

    if ( colors.size( ) == 0 ) {
        ui->outputTextEdit->append( tr( "Nothing was found" ) );
    }

    for ( std::size_t i = 0; i < colors.size( ); i++ ) {
        ui->outputTextEdit->append( colors[i] );
    }
}

void Dialog::replyProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar->setValue( bytesReceived );
    ui->progressBar->setMaximum( bytesTotal );

    qDebug() << bytesReceived;
    qDebug() << bytesTotal;
}
