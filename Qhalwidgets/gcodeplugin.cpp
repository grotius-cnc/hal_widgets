#include "gcode.h"
#include "gcodeplugin.h"

#include <QtPlugin>

gcodePlugin::gcodePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void gcodePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool gcodePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *gcodePlugin::createWidget(QWidget *parent)
{
    return new gcode(parent);
}

QString gcodePlugin::name() const
{
    return QLatin1String("gcode");
}

QString gcodePlugin::group() const
{
    return QLatin1String("Linux Hal");
}

QIcon gcodePlugin::icon() const
{
    return QIcon();
}

QString gcodePlugin::toolTip() const
{
    return QLatin1String("");
}

QString gcodePlugin::whatsThis() const
{
    return QLatin1String("");
}

bool gcodePlugin::isContainer() const
{
    return false;
}

QString gcodePlugin::domXml() const
{
    return QLatin1String("<widget class=\"gcode\" name=\"gcode\">\n</widget>\n");
}

QString gcodePlugin::includeFile() const
{
    return QLatin1String("gcode.h");
}

