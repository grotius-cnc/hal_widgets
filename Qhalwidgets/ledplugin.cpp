#include "led.h"
#include "ledplugin.h"

#include <QtPlugin>

ledPlugin::ledPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ledPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ledPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ledPlugin::createWidget(QWidget *parent)
{
    return new led(parent);
}

QString ledPlugin::name() const
{
    return QLatin1String("Hal Led");
}

QString ledPlugin::group() const
{
    return QLatin1String("Linux Hal");
}

QIcon ledPlugin::icon() const
{
    return QIcon();
}

QString ledPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ledPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ledPlugin::isContainer() const
{
    return false;
}

QString ledPlugin::domXml() const
{
    return QLatin1String("<widget class=\"led\" name=\"led\">\n</widget>\n");
}

QString ledPlugin::includeFile() const
{
    return QLatin1String("led.h");
}

