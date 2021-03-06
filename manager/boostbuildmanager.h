#ifndef BOOSTBUILDPLUGIN_H
#define BOOSTBUILDPLUGIN_H

#include <project/interfaces/ibuildsystemmanager.h>
#include <project/abstractfilemanagerplugin.h>
#include <language/interfaces/ilanguagesupport.h>
#include <project/interfaces/iprojectbuilder.h>


class BoostBuildManager
    : public KDevelop::AbstractFileManagerPlugin
    , public KDevelop::IBuildSystemManager
    //, public KDevelop::ILanguageSupport
{
Q_OBJECT
Q_INTERFACES( KDevelop::IBuildSystemManager )
//Q_INTERFACES( KDevelop::ILanguageSupport )
    public:
        // Constructor
        explicit BoostBuildManager ( QObject *parent = 0, const QVariantList &args = QVariantList() );
        // Destructor
        virtual ~BoostBuildManager();

        //AbstractFileManagerPlugin
        virtual Features features() const;
//         virtual QList<KDevelop::ProjectFolderItem*> parse ( KDevelop::ProjectFolderItem* dom );
        virtual KDevelop::ProjectFolderItem* import ( KDevelop::IProject *project );
        virtual bool isValid(const KUrl& url, const bool isFolder, KDevelop::IProject* project) const;
//         virtual KDevelop::ProjectFolderItem* addFolder ( const KUrl& folder, KDevelop::ProjectFolderItem* parent );
//         virtual KDevelop::ProjectFileItem* addFile ( const KUrl&, KDevelop::ProjectFolderItem* );
//         virtual bool renameFile ( KDevelop::ProjectFileItem*, const KUrl& );
//         virtual bool renameFolder ( KDevelop::ProjectFolderItem*, const KUrl& );
//         virtual bool moveFilesAndFolders ( const QList< KDevelop::ProjectBaseItem* > &items, KDevelop::ProjectFolderItem *newParent );
//         virtual bool removeFilesAndFolders ( const QList<KDevelop::ProjectBaseItem*> &items );
//         virtual bool reload ( KDevelop::ProjectFolderItem* );

        //IBuildSystemManager
        virtual KDevelop::IProjectBuilder* builder() const;
        virtual KUrl buildDirectory ( KDevelop::ProjectBaseItem* ) const;
        virtual KUrl::List includeDirectories ( KDevelop::ProjectBaseItem * ) const;
        virtual QHash<QString, QString> defines ( KDevelop::ProjectBaseItem * ) const;
        virtual KDevelop::ProjectTargetItem* createTarget ( const QString&, KDevelop::ProjectFolderItem* ) ;
        virtual bool addFilesToTarget ( const QList<KDevelop::ProjectFileItem*> &files, KDevelop::ProjectTargetItem* target );
        virtual bool removeTarget ( KDevelop::ProjectTargetItem* ) ;
        virtual bool removeFilesFromTargets ( const QList<KDevelop::ProjectFileItem*> &files );
        virtual QList<KDevelop::ProjectTargetItem*> targets ( KDevelop::ProjectFolderItem* folder ) const;

        //cmakemanager found this helpful
        //QList<KDevelop::ProjectTargetItem*> targets() const;

        //ILanguageSupport
        virtual QString name() const;
        virtual KDevelop::ParseJob *createParseJob ( const KUrl &url );

//     void readConfig (KConfig *);
//     void writeConfig (KConfig *);

protected:
    virtual KDevelop::ProjectFolderItem* createFolderItem( KDevelop::IProject* project, const KUrl& url, KDevelop::ProjectBaseItem* parent );
        
private:
    class Private;
    Private *d;
};

#endif
