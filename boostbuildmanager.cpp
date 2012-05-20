#include "boostbuildmanager.h"

#include <KTextEditor/Document>
#include <KTextEditor/View>

#include <KPluginFactory>
#include <KPluginLoader>
#include <KLocale>
#include <KAction>
#include <KActionCollection>

K_PLUGIN_FACTORY ( BoostBuildManagerFactory, registerPlugin<BoostBuildManager> ( "kdevelop_boost_build" ); )
K_EXPORT_PLUGIN ( BoostBuildManagerFactory ( "kdevelop_boost_build", "kdevelop_plugins" ) )

BoostBuildManager::BoostBuildManager ( QObject *parent, const QVariantList &args )
    : KDevelop::IPlugin ( BoostBuildManager::componentData(), parent )
{
    KDEV_USE_EXTENSION_INTERFACE ( KDevelop::IBuildSystemManager )
    KDEV_USE_EXTENSION_INTERFACE ( KDevelop::IProjectFileManager )
    KDEV_USE_EXTENSION_INTERFACE ( KDevelop::ILanguageSupport )
    Q_UNUSED ( args );
}

BoostBuildManager::~BoostBuildManager()
{
}
KDevelop::ProjectFolderItem* BoostBuildManager::import ( KDevelop::IProject* project )
{
    return 0;
}
KDevelop::ProjectFolderItem* BoostBuildManager::addFolder ( const KUrl& folder, KDevelop::ProjectFolderItem* parent )
{
    return 0;
}
KDevelop::ProjectFileItem* BoostBuildManager::addFile ( const KUrl&, KDevelop::ProjectFolderItem* )
{
    return 0;
}
bool BoostBuildManager::renameFile ( KDevelop::ProjectFileItem*, const KUrl& )
{
    return false;
}
bool BoostBuildManager::renameFolder ( KDevelop::ProjectFolderItem*, const KUrl& )
{
    return false;
}
bool BoostBuildManager::moveFilesAndFolders ( const QList< KDevelop::ProjectBaseItem* >& items, KDevelop::ProjectFolderItem* newParent )
{
    return false;
}
bool BoostBuildManager::removeFilesAndFolders ( const QList< KDevelop::ProjectBaseItem* >& items )
{
    return false;
}
bool BoostBuildManager::reload ( KDevelop::ProjectFolderItem* )
{
    return false;
}
KDevelop::IProjectBuilder* BoostBuildManager::builder() const
{
    return 0;
}
KUrl BoostBuildManager::buildDirectory ( KDevelop::ProjectBaseItem* ) const
{
    return KUrl();
}
KUrl::List BoostBuildManager::includeDirectories ( KDevelop::ProjectBaseItem* ) const
{
    return KUrl::List();
}
QHash< QString, QString > BoostBuildManager::defines ( KDevelop::ProjectBaseItem* ) const
{
    return QHash< QString, QString >();
}
KDevelop::ProjectTargetItem* BoostBuildManager::createTarget ( const QString&, KDevelop::ProjectFolderItem* )
{
    return 0;
}
bool BoostBuildManager::addFilesToTarget ( const QList< KDevelop::ProjectFileItem* >& files, KDevelop::ProjectTargetItem* target )
{
    return false;
}
bool BoostBuildManager::removeTarget ( KDevelop::ProjectTargetItem* )
{
    return false;
}
bool BoostBuildManager::removeFilesFromTargets ( const QList< KDevelop::ProjectFileItem* >& files )
{
    return false;
}
QList< KDevelop::ProjectTargetItem* > BoostBuildManager::targets ( KDevelop::ProjectFolderItem* folder ) const
{
    return QList< KDevelop::ProjectTargetItem* >();
}
QString BoostBuildManager::name() const
{
    return "Boost.Build";
}
KDevelop::ParseJob* BoostBuildManager::createParseJob ( const KUrl& url )
{
    return 0;
}
QList< KDevelop::ProjectFolderItem* > BoostBuildManager::parse ( KDevelop::ProjectFolderItem* dom )
{
    return QList< KDevelop::ProjectFolderItem* >();
}


#include "boostbuildmanager.moc"
