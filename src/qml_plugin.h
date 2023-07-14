#pragma once

#include <QQmlExtensionPlugin>

class QuickFluxQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    // QQmlExtensionInterface interface
    void registerTypes(const char *uri);
};
