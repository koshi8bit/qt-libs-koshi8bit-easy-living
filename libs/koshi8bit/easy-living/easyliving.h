#ifndef EASYLIVING_H
#define EASYLIVING_H

#include <QObject>
#include <QString>
#include <QLocale>
#include <QDebug>
#include <QDateTime>
#include <QDir>
#include <QProcess>
#include <QTimer>
#include <QJsonDocument>

#include "operationresult.h"

#include "koshi8bit-easy-living_global.h"

//errors
#define EL_FORMAT_ERR(message) (QStringList() << "ACHTUNG! " << Q_FUNC_INFO << ": " << message).join("")

#define EL_F Q_FUNC_INFO
#define EL_NAME(Variable) (#Variable)

//raw string
//R"(raw\string)"

class KOSHI8BIT_EASY_LIVING_EXPORT EasyLiving : public QObject
{
    Q_OBJECT

public:
    enum DoubleSeporatorSign
    {
        Comma,
        Point
    };
    Q_ENUM(DoubleSeporatorSign)

    EasyLiving();

    //double
    static QLocale localeMy;
    //fixme double value, int precision = 3, bool scientificNotation = false, bool showGroupSeparator = false, bool seporatorPoint = false)
    static QString formatDouble(double value, int precision = 3, bool scientificNotation = false, bool showGroupSeparator = true, DoubleSeporatorSign seporatorSign = DoubleSeporatorSign::Comma, int padding=0, QChar fillWidth=' ');
    static QString formatDouble(double value, int precision, int padding, QChar fillWidth=' ');
    //    QT_DEPRECATED_X(
    //        "Testing QT_DEPRECATED_X"
    //        )
    static bool isBetween(double value, double min, double max);
    static bool isEqualDouble(double a, double b);

    static int sign(double x);
    static double crop(double value, double outputRange);
    static double crop(double value, double min, double max);


    //dateTime
    static bool isBetween(QDateTime value, QDateTime min, QDateTime max);
    static QString dateTimeDelta(QDateTime begin, QDateTime end, bool daysOnly = true, bool showMs = false);
    static void dateTimeDelta(QDateTime begin, QDateTime end, int &years, int &month, int &days,
                              int &hours, int &minutes, int &seconds, int &milliseconds, bool daysOnly = true);


    static QString formatDateTimeISO8601(bool showMS);
    static QString formatDate();

    static QString formatDateFile();
    static QString formatTimeFile(bool showMS);
    static QString formatDateTimeFileSeporator();
    static QString formatDateTimeFile(bool showMS = false);

    static QString formatDateUi();
    static QString formatTimeUi(bool showMS = false);
    static QString formatDateTimeUiSeporator(QString seporator = "@");
    static QString formatDateTimeUi(bool showMS = false);

    //bool
    static bool isChecked(int arg1);

    //files
    static bool fileExists(QString path);
    static bool dirExists(QString path);
    static bool createDir(QString path);
    static bool isWritable(QString path);
    static bool writeFile(QString path, QString text, bool append = false, bool addDateTime = false, QString codec = "");
    static QString readFile(QString path, bool *ok=nullptr);
    static QString pathConcat(QString path1, QString path2);

    static bool exec(QString exe, QStringList arguments);
    static bool exec(QString cmdLine);

    //JSON
    static OperationResult readJson(QString path);
    static OperationResult writeJson(QString path, QJsonDocument doc);

    //ui
    static QString extracted(QString &text, QString &version);
    static QString setWindowTitle(QString text, QString version);

private:
    static void del(long long &delta, int &v, int divider);
    static void messageAppend(QString &message, int value, QString postfix, bool forseAppend = false);
    static QString formatDoublePadding(QString str, int padding=0, QChar fillWidth=' ');
};

#endif // EASYLIVING_H
