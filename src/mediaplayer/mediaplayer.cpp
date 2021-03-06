#include "mediaplayer.hpp"

#ifdef USE_DBUS

MediaPlayer::MediaPlayer(spt::Spotify *spotify, QObject *parent)
	: spotify(spotify), parent(parent),
	dBus(QDBusConnection::sessionBus()), QDBusAbstractAdaptor(parent)
{
}

void MediaPlayer::Quit() const
{
	QCoreApplication::quit();
}

void MediaPlayer::Raise() const
{
	if (parent != nullptr)
		((QWidget *) parent)->raise();
}

bool MediaPlayer::canQuit() const
{
	return true;
}

QString MediaPlayer::identity() const
{
	return "spotify-qt";
}

QStringList MediaPlayer::supportedUriSchemas() const
{
	return QStringList("spotify");
}

QStringList MediaPlayer::supportedMimeTypes() const
{
	return QStringList();
}

bool MediaPlayer::hasTrackList() const
{
	return false;
}

#endif