#include "slider.h"
#include "sliderplugin.h"

#include <QtPlugin>

sliderPlugin::sliderPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void sliderPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool sliderPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *sliderPlugin::createWidget(QWidget *parent)
{
    return new slider(parent);
}

QString sliderPlugin::name() const
{
    return QLatin1String("Hal Slider");
}

QString sliderPlugin::group() const
{
    return QLatin1String("Linux Hal");
}

QIcon sliderPlugin::icon() const
{
    return QIcon();
}

QString sliderPlugin::toolTip() const
{
    return QLatin1String("");
}

QString sliderPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool sliderPlugin::isContainer() const
{
    return false;
}

QString sliderPlugin::domXml() const
{
    return QLatin1String("<widget class=\"slider\" name=\"slider\">\n</widget>\n");
}

QString sliderPlugin::includeFile() const
{
    return QLatin1String("slider.h");
}

