/// QML Type Registration Helper
#include <QtQml>
#include <QFAppDispatcher>
#include "qfmiddleware.h"
#include "qfdispatcher.h"
#include "qfapplistener.h"
#include "qfappscript.h"
#include "qfapplistenergroup.h"
#include "qfappscriptgroup.h"
#include "priv/qfappscriptrunnable.h"
#include "qffilter.h"
#include "qfkeytable.h"
#include "qfactioncreator.h"
#include "qfobject.h"
#include "qfmiddlewarelist.h"
#include "qfstore.h"
#include "qfhydrate.h"

static QObject *appDispatcherProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    QFAppDispatcher* object = new QFAppDispatcher();
    object->setEngine(engine);

    return object;
}

static QObject* hydrateProvider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    QFHydrate* object = new QFHydrate();
    return object;
}


void registerQuickFluxQmlTypes(const char* uri)
{
    static bool registered = false;
    if (registered) {
        return;
    }

    registered = true;

    qmlRegisterSingletonType<QFAppDispatcher>(uri, 1, 0, "AppDispatcher", appDispatcherProvider);
    qmlRegisterType<QFAppListener>(uri, 1, 0, "AppListener");
    qmlRegisterType<QFAppScript>(uri, 1, 0, "AppScript");
    qmlRegisterType<QFAppListenerGroup>(uri, 1, 0, "AppListenerGroup");
    qmlRegisterType<QFAppScriptGroup>(uri, 1, 0, "AppScriptGroup");

#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    qmlRegisterAnonymousType<QFAppScriptRunnable>(uri, 1);
#else
    qmlRegisterType<QFAppScriptRunnable>();
#endif

    qmlRegisterType<QFKeyTable>(uri, 1, 0, "KeyTable");
    qmlRegisterType<QFActionCreator>(uri, 1, 0, "ActionCreator");
    qmlRegisterType<QFFilter>(uri, 1, 0, "Filter");

    /* 1.1 */
    qmlRegisterType<QFActionCreator>(uri, 1, 1, "ActionCreator");
    qmlRegisterType<QFAppListener>(uri, 1, 1, "AppListener");
    qmlRegisterType<QFAppScript>(uri, 1, 1, "AppScript");
    qmlRegisterType<QFAppListenerGroup>(uri, 1, 1, "AppListenerGroup");
    qmlRegisterType<QFAppScriptGroup>(uri, 1, 1, "AppScriptGroup");
    qmlRegisterType<QFFilter>(uri, 1, 1, "Filter");
    qmlRegisterType<QFKeyTable>(uri, 1, 1, "KeyTable");
    qmlRegisterType<QFActionCreator>(uri, 1, 1, "ActionCreator");

    /* New components in 1.1 */
    qmlRegisterSingletonType<QFHydrate>(uri, 1, 1, "Hydrate", hydrateProvider);
    qmlRegisterType<QFDispatcher>(uri, 1, 1, "Dispatcher");
    qmlRegisterType<QFStore>(uri, 1, 1, "Store");
    qmlRegisterType<QFMiddlewareList>(uri, 1, 1, "MiddlewareList");
    qmlRegisterType<QFMiddleware>(uri, 1, 1, "Middleware");
    //    qmlRegisterType<QFObject>(uri, 1, 1, "Object");
}

// Allow to disable QML types auto registration as required by #9
// #ifndef QUICK_FLUX_DISABLE_AUTO_QML_REGISTER
// Q_COREAPP_STARTUP_FUNCTION(registerQuickFluxQmlTypes)
// #endif
