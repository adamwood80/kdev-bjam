#include "kde-bjamplugin.h"
#include "kde-bjamview.h"

#include <KTextEditor/Document>
#include <KTextEditor/View>

#include <KPluginFactory>
#include <KPluginLoader>
#include <KLocale>
#include <KAction>
#include <KActionCollection>

K_PLUGIN_FACTORY(kde-bjamPluginFactory, registerPlugin<kde-bjamPlugin>("ktexteditor_kde-bjam");)
K_EXPORT_PLUGIN(kde-bjamPluginFactory("ktexteditor_kde-bjam", "ktexteditor_plugins"))

kde-bjamPlugin::kde-bjamPlugin(QObject *parent, const QVariantList &args)
: KTextEditor::Plugin(parent)
{
	Q_UNUSED(args);
}

kde-bjamPlugin::~kde-bjamPlugin()
{
}

void kde-bjamPlugin::addView(KTextEditor::View *view)
{
	kde-bjamView *nview = new kde-bjamView(view);
	m_views.append(nview);
}

void kde-bjamPlugin::removeView(KTextEditor::View *view)
{
	for(int z = 0; z < m_views.size(); z++)
	{
		if(m_views.at(z)->parentClient() == view)
		{
			kde-bjamView *nview = m_views.at(z);
			m_views.removeAll(nview);
			delete nview;
		}
	}
}

void kde-bjamPlugin::readConfig()
{
}

void kde-bjamPlugin::writeConfig()
{
}

kde-bjamView::kde-bjamView(KTextEditor::View *view)
: QObject(view)
, KXMLGUIClient(view)
, m_view(view)
{
	setComponentData(kde-bjamPluginFactory::componentData());
	
	KAction *action = new KAction(i18n("KTextEditor - kde-bjam"), this);
	actionCollection()->addAction("tools_kde-bjam", action);
	//action->setShortcut(Qt::CTRL + Qt::Key_XYZ);
	connect(action, SIGNAL(triggered()), this, SLOT(insertkde-bjam()));
	
	setXMLFile("kde-bjamui.rc");
}

kde-bjamView::~kde-bjamView()
{
}

void kde-bjamView::insertkde-bjam()
{
	m_view->document()->insertText(m_view->cursorPosition(), i18n("Hello, World!"));
}

#include "kde-bjamview.moc"
