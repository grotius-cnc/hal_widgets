#include "component.h"
#include "componentplugin.h"

#include <QtPlugin>

componentPlugin::componentPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void componentPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool componentPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *componentPlugin::createWidget(QWidget *parent)
{
    return new component(parent);
}

QString componentPlugin::name() const
{
    return QLatin1String("Hal Component");
}

QString componentPlugin::group() const
{
    return QLatin1String("Linux Hal");
}

QIcon componentPlugin::icon() const
{
    return QIcon();
}

QString componentPlugin::toolTip() const
{
    return QLatin1String("");
}

QString componentPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool componentPlugin::isContainer() const
{
    return false;
}

QString componentPlugin::domXml() const
{
    return QLatin1String("<widget class=\"component\" name=\"component\">\n</widget>\n");
}

QString componentPlugin::includeFile() const
{
    return QLatin1String("component.h");
}

