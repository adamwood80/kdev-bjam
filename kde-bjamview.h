#ifndef KDE-BJAMVIEW_H
#define KDE-BJAMVIEW_H

#include <QObject>
#include <KXMLGUIClient>

class kde-bjamView : public QObject, public KXMLGUIClient
{
	Q_OBJECT
	public:
		explicit kde-bjamView(KTextEditor::View *view = 0);
		~kde-bjamView();
	private slots:
		void insertkde-bjam();
	private:
		KTextEditor::View *m_view;
};

#endif
