#ifndef BOOSTBUILDPLUGIN_H
#define BOOSTBUILDPLUGIN_H

#include <project/interfaces/ibuildsystemmanager.h>
#include <interfaces/iplugin.h>
#include <language/interfaces/ilanguagesupport.h>


class BoostBuildManager
    : public KDevelop::IPlugin
    , public KDevelop::IBuildSystemManager
    , public KDevelop::ILanguageSupport
{
    public:
        // Constructor
        explicit BoostBuildManager ( QObject *parent = 0, const QVariantList &args = QVariantList() );
        // Destructor
        virtual ~BoostBuildManager();

        //IProjectFileManager
        virtual Features features() const
        {
            return Features ( Folders | Targets | Files );
        }
        virtual QList<KDevelop::ProjectFolderItem*> parse ( KDevelop::ProjectFolderItem* dom );
        virtual KDevelop::ProjectFolderItem* import ( KDevelop::IProject *project );
        virtual KDevelop::ProjectFolderItem* addFolder ( const KUrl& folder, KDevelop::ProjectFolderItem* parent );
        virtual KDevelop::ProjectFileItem* addFile ( const KUrl&, KDevelop::ProjectFolderItem* );
        virtual bool renameFile ( KDevelop::ProjectFileItem*, const KUrl& );
        virtual bool renameFolder ( KDevelop::ProjectFolderItem*, const KUrl& );
        virtual bool moveFilesAndFolders ( const QList< KDevelop::ProjectBaseItem* > &items, KDevelop::ProjectFolderItem *newParent );
        virtual bool removeFilesAndFolders ( const QList<KDevelop::ProjectBaseItem*> &items );
        virtual bool reload ( KDevelop::ProjectFolderItem* );

        //IBuildSystemManager
        virtual KDevelop::IProjectBuilder* builder() const;
        virtual KUrl buildDirectory ( KDevelop::ProjectBaseItem* ) const;
        virtual KUrl::List includeDirectories ( KDevelop::ProjectBaseItem * ) const;
        virtual QHash<QString, QString> defines ( KDevelop::ProjectBaseItem * ) const;
        virtual KDevelop::ProjectTargetItem* createTarget ( const QString&, KDevelop::ProjectFolderItem* ) ;
        virtual bool addFilesToTarget ( const QList<KDevelop::ProjectFileItem*> &files, KDevelop::ProjectTargetItem* target );
        virtual bool removeTarget ( KDevelop::ProjectTargetItem* ) ;
        virtual bool removeFilesFromTargets ( const QList<KDevelop::ProjectFileItem*> &files );
        QList<KDevelop::ProjectTargetItem*> targets ( KDevelop::ProjectFolderItem* folder ) const;

        //cmakemanager found this helpful
        //QList<KDevelop::ProjectTargetItem*> targets() const;

        //ILanguageSupport
        virtual QString name() const;
        virtual KDevelop::ParseJob *createParseJob ( const KUrl &url );

//     void readConfig (KConfig *);
//     void writeConfig (KConfig *);

    private:
};

#endif
