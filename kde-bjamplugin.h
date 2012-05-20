#ifndef KDE-BJAMPLUGIN_H
#define KDE-BJAMPLUGIN_H

#include <KTextEditor/Plugin>

namespace KTextEditor
{
	class View;
}

class kde-bjamView;

class kde-bjamPlugin
  : public KTextEditor::Plugin
{
  public:
    // Constructor
    explicit kde-bjamPlugin(QObject *parent = 0, const QVariantList &args = QVariantList());
    // Destructor
    virtual ~kde-bjamPlugin();

    void addView (KTextEditor::View *view);
    void removeView (KTextEditor::View *view);
 
    void readConfig();
    void writeConfig();
 
//     void readConfig (KConfig *);
//     void writeConfig (KConfig *);
 
  private:
    QList<class kde-bjamView*> m_views;
};

#endif
