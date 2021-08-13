#include "button.h"
#include "buttonplugin.h"

#include <QtPlugin>

buttonPlugin::buttonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void buttonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool buttonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *buttonPlugin::createWidget(QWidget *parent)
{
    return new button(parent);
}

QString buttonPlugin::name() const
{
    return QLatin1String("button");
}

QString buttonPlugin::group() const
{
    return QLatin1String("Linux Hal");
}

QIcon buttonPlugin::icon() const
{
    return QIcon();
}

QString buttonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString buttonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool buttonPlugin::isContainer() const
{
    return false;
}

QString buttonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"button\" name=\"button\">\n</widget>\n");
}

QString buttonPlugin::includeFile() const
{
    return QLatin1String("button.h");
}

