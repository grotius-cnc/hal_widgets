#include "label.h"
#include "labelplugin.h"

#include <QtPlugin>

labelPlugin::labelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void labelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool labelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *labelPlugin::createWidget(QWidget *parent)
{
    return new label(parent);
}

QString labelPlugin::name() const
{
    return QLatin1String("Hal Label");
}

QString labelPlugin::group() const
{
    return QLatin1String("Linux Hal");
}

QIcon labelPlugin::icon() const
{
    return QIcon();
}

QString labelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString labelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool labelPlugin::isContainer() const
{
    return false;
}

QString labelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"label\" name=\"label\">\n</widget>\n");
}

QString labelPlugin::includeFile() const
{
    return QLatin1String("label.h");
}

