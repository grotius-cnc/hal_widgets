#include "componentplugin.h"
#include "buttonplugin.h"
#include "labelplugin.h"
#include "ledplugin.h"
#include "sliderplugin.h"
#include "gcodeplugin.h"
#include "halwidgets.h"

halwidgets::halwidgets(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new componentPlugin(this));
    m_widgets.append(new buttonPlugin(this));
    m_widgets.append(new labelPlugin(this));
    m_widgets.append(new ledPlugin(this));
    m_widgets.append(new sliderPlugin(this));
    m_widgets.append(new gcodePlugin(this));

}

QList<QDesignerCustomWidgetInterface*> halwidgets::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(halwidgetsplugin, halwidgets)
#endif // QT_VERSION < 0x050000
