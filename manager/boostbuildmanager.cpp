#include "boostbuildmanager.h"

#include <qfile.h>

#include <KPluginFactory>
#include <KPluginLoader>
#include <KLocale>
#include <KAction>
#include <KActionCollection>
#include <KAboutData>

#include <interfaces/icore.h>
#include <interfaces/iprojectcontroller.h>
#include <interfaces/iplugincontroller.h>
#include <interfaces/iproject.h>
#include <project/projectmodel.h>
#include <kdevelop/make/imakebuilder.h>
#include <kjob.h>

K_PLUGIN_FACTORY ( BoostBuildManagerFactory, registerPlugin<BoostBuildManager> ( ); )
K_EXPORT_PLUGIN ( BoostBuildManagerFactory ( KAboutData("kdevboostbuildmanager", 
                                                        "kdevboostbuild", 
                                                        ki18n("Boost.Build BuildSystem"), 
                                                        BOOST_BUILD_PLUGIN_VERSION, 
                                                        ki18n("Support for building and managing Boost.Build Buildsystems"),
                                                        KAboutData::License_GPL,ki18n("Copyright 2012 Adam Wood <adamwood@xephi.co.uk>"),
                                                        KLocalizedString(),
                                                        "",
                                                        "adamwood@xephi.co.uk" )) )

class BoostBuildManager::Private
{
public:
    Private() : m_builder(0) {}

    IMakeBuilder *m_builder;

//     QList< KDevelop::ProjectBaseItem* > m_testItems; // for debug
};

BoostBuildManager::BoostBuildManager ( QObject *parent, const QVariantList &args )
    : KDevelop::AbstractFileManagerPlugin ( BoostBuildManagerFactory::componentData(), parent )
    , d( new Private )
{
    Q_UNUSED ( args );
    //KDEV_USE_EXTENSION_INTERFACE ( KDevelop::IProjectFileManager )
    KDEV_USE_EXTENSION_INTERFACE ( KDevelop::IBuildSystemManager )
    //KDEV_USE_EXTENSION_INTERFACE ( KDevelop::ILanguageSupport )
    
    //setXMLFile( "kdevboostbuildmanager.rc" );
    //TODO: Use a boost builder so the make command is set correctly
    IPlugin* i = core()->pluginController()->pluginForExtension("org.kdevelop.IMakeBuilder" );
    Q_ASSERT(i);
    d->m_builder = i->extension<IMakeBuilder>();
    Q_ASSERT(d->m_builder);
}

BoostBuildManager::~BoostBuildManager()
{
    delete d;
}

// class BoostBuildFolderItem
//     : public KDevelop::ProjectBuildFolderItem
//     //, public DescriptorAttatched, public DefinesAttached, public IncludesAttached
// {
//     public:
//         BoostBuildFolderItem( KDevelop::IProject* project, const KUrl& folder, const QString& build, BoostBuildFolderItem* item)
//         : KDevelop::ProjectBuildFolderItem(project, folder){}
//         // Required, and must be non-inline, for dynamic_cast to work
//         virtual ~BoostBuildFolderItem(){}
// };

KDevelop::ProjectFolderItem* BoostBuildManager::import ( KDevelop::IProject* project )
{
    kWarning() << "Kdevelop asking for import" << project->projectFileUrl();
    KDevelop::ProjectFolderItem* root_folder = 0;
    KUrl folderUrl(project->folder());
    KUrl jamfile(folderUrl);
    jamfile.addPath("Jamroot");
    kWarning() << "file is" << jamfile.toLocalFile();
    root_folder = AbstractFileManagerPlugin::import( project );
    return root_folder;
}
/*
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
bool BoostBuildManager::reload ( KDevelop::ProjectFolderItem* item)
{
    kDebug() << "Kdevelop asking for reload" << item;
    return false;
}*/
KDevelop::IProjectBuilder* BoostBuildManager::builder() const
{
    kWarning() << "Kdevelop asking for builder";
    Q_ASSERT(d->m_builder);
    return d->m_builder;
}
KUrl BoostBuildManager::buildDirectory ( KDevelop::ProjectBaseItem* item) const
{
    KDevelop::ProjectFolderItem *fi=dynamic_cast<KDevelop::ProjectFolderItem*>(item);
    for(; !fi && item; )
    {
        item=dynamic_cast<KDevelop::ProjectBaseItem*>(item->parent());
        fi=dynamic_cast<KDevelop::ProjectFolderItem*>(item);
    }
    if(!fi) {
        return item->project()->folder();
    }
    return fi->url();
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
    kWarning() << "create target";
    return 0;
}
bool BoostBuildManager::addFilesToTarget ( const QList< KDevelop::ProjectFileItem* >& files, KDevelop::ProjectTargetItem* target )
{
    Q_UNUSED(files);
    Q_UNUSED(target);
    return false;
}
bool BoostBuildManager::removeTarget ( KDevelop::ProjectTargetItem* )
{
    return false;
}
bool BoostBuildManager::removeFilesFromTargets ( const QList< KDevelop::ProjectFileItem* >& files )
{
    Q_UNUSED(files);
    return false;
}
QList< KDevelop::ProjectTargetItem* > BoostBuildManager::targets ( KDevelop::ProjectFolderItem* folder ) const
{
    kWarning() << "targets for " << folder->url();
    return folder->targetList();
}
QString BoostBuildManager::name() const
{
    return "Boost.Build";
}
KDevelop::ParseJob* BoostBuildManager::createParseJob ( const KUrl& url )
{
    kWarning() << "create parseJob " << url;
    return 0;
}
KDevelop::IProjectFileManager::Features BoostBuildManager::features() const
{
    return Features ( Folders | Targets | Files );
}

KDevelop::ProjectFolderItem* BoostBuildManager::createFolderItem( KDevelop::IProject* project, const KUrl& url,
                                                                KDevelop::ProjectBaseItem* parent )
{
    if(!parent)
    {
        return new KDevelop::ProjectBuildFolderItem(project, url);
    }
    KUrl jamfilePath(url);
    jamfilePath.addPath("Jamfile");
    
    if(QFile::exists(jamfilePath.toLocalFile()))
        return new KDevelop::ProjectBuildFolderItem(project, url, parent);
    
    return new KDevelop::ProjectFolderItem( project, url, parent );
}

bool BoostBuildManager::isValid ( const KUrl& url, const bool isFolder, KDevelop::IProject* project ) const 
{
    const QString name = url.fileName();
    const QStringList invalidFolders = QStringList() << ".kdev4" << ".svn" << ".git" << "CVS"
                                                     << ".bzr" << "_darcs" << ".hg";
                           
    if (isFolder) {
        KUrl build_folder(project->folder());
        build_folder.addPath("build/");
        KUrl install_folder(project->folder());
        install_folder.addPath("install/");
        
        if(url == build_folder)
            return false;
        else if(url == install_folder)
            return false;
        else if(invalidFolders.contains( name ))
            return false;
        
    } else if (!isFolder && (name.endsWith("~")
                          || name.endsWith(".o") || name.endsWith(".a")
                          || name.startsWith("moc_") || name.endsWith(".moc")
                          || name.endsWith(".so") || name.contains(".so.")
                          || name.startsWith(".swp.")
                          || (name.startsWith('.') && name.endsWith(".kate-swp"))))
    {
        return false;
    } else if (isFolder && QFile::exists(url.toLocalFile() + "/.kdev_ignore")) {
        return false;
    }
    
    return true;
}


#include "boostbuildmanager.moc"
