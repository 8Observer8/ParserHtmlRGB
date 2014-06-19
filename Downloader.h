#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <memory>
#include <string>

#include <QObject>
#include <QString>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetWorkAccessManager>

#include "EmptyArgument.h"

class Downloader : public QObject
{
    Q_OBJECT

public:

    void fetch( const QString &url )
        throw( EmptyArgument )
    {
        std::string functionName = "fetch()";

        // Check the input argument
        if ( url.isEmpty( ) ) {
            throw EmptyArgument( functionName );
        }

        m_reply.reset(m_manager->get( QNetworkRequest( QUrl( url ) ) ) );
        connect( m_reply.get( ), SIGNAL( finished( ) ),
                 this, SLOT( replyFinished( ) ) );
        connect( m_reply.get( ), SIGNAL( downloadProgress( qint64, qint64 ) ),
                 this, SLOT( slotDownloadProgress(qint64, qint64 ) ) );
    }

signals:
    void signalWithContent( QString * );
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

private slots:
    void replyFinished( )
    {
        QByteArray data = m_reply->readAll( );
        QString content( data );
        emit signalWithContent( &content );
    }

    void slotDownloadProgress( qint64 bytesReceived, qint64 bytesTotal )
    {
        emit downloadProgress( bytesReceived, bytesTotal );
    }

private:
    std::shared_ptr<QNetworkAccessManager> m_manager =
            std::make_shared<QNetworkAccessManager>( this );

    std::shared_ptr<QNetworkReply> m_reply;
};

#endif // DOWNLOADER_H
