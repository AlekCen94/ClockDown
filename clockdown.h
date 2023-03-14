#ifndef CLOCKDOWN_H
#define CLOCKDOWN_H

#include <QWidget>
#include <qtimer.h>
#include <QProcess>
#include <QPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class ClockDown; }
QT_END_NAMESPACE

class ClockDown : public QWidget
{
    Q_OBJECT

public:
    ClockDown(QWidget *parent = nullptr);  ///< Default constructor.
    ~ClockDown();                         ///< Destructor.

private:
    Ui::ClockDown *ui;

protected:
    int m_hours;  ///< Hours.

    int m_minutes; ///< Minutes.

    int m_seconds; ///< Seconds.

    QPointer<QTimer> m_timer;  ///< Timer object.

    QPointer<QProcess> m_process;  ///< Proces object.

    bool m_pause;                  ///< Bool value for pause.

protected slots:
    void countDown();         ///< Slot for count down timer.
    void clickStart();        ///< Slot for start button.
};
#endif // CLOCKDOWN_H
