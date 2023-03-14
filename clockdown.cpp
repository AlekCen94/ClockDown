#include "clockdown.h"
#include "ui_clockdown.h"
#include <QDebug>

ClockDown::ClockDown(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClockDown)
{
    ui->setupUi(this);

    m_timer = new QTimer();
    m_process = new QProcess(this);
    m_pause = false;
    QStringList m_comands;
    m_comands << "shutdown -s" << "rundll32.exe powrprof.dll, SetSuspendState Sleep" << "shutdown -r";

    ui->m_comboBoxComand->addItems(m_comands);



    connect(m_timer.data(),SIGNAL(timeout()),this,SLOT(countDown()));
    connect(ui->m_startButton,SIGNAL(clicked()),this,SLOT(clickStart()));
}

ClockDown::~ClockDown()
{
    delete ui;
}

void ClockDown::countDown()
{
    if(m_hours == 0 && m_minutes == 0 && m_seconds == 0) {
        m_pause = false;
        m_process->start(ui->m_comboBoxComand->currentText());
        m_timer->stop();

    }
    else
    {
        if(m_seconds!=0)
        {
            m_seconds --;
            ui->m_secondDisplay->display((int)m_seconds);
        }
        else
        {
            if(m_minutes!=0)
            {
                m_minutes --;
                m_seconds = 59;
                ui->m_minuteDisplay->display((int)m_minutes);
                ui->m_secondDisplay->display((int)m_seconds);
            }
            else
            {
                if(m_hours!=0)
                {
                    m_hours --;
                    m_minutes = 59;
                    m_seconds = 59;
                    ui->m_hourDisplay->display((int)m_hours);
                    ui->m_minuteDisplay->display((int)m_minutes);
                    ui->m_secondDisplay->display((int)m_seconds);
                }
            }
        }
    }
}

void ClockDown::clickStart()
{
   if(ui->m_startButton->text() == "Start")
   {
       if(!m_pause)
       {
           m_seconds = ui->m_secondSpinBox->value();
           m_minutes = ui->m_minuteSpinBox->value();
           m_hours = ui->m_hourSpinBox->value();


           m_pause = true;
       }

    ui->m_startButton->setText("Pause");
    ui->m_comboBoxComand->setEnabled(false);

    ui->m_hourDisplay->display(m_hours);
    ui->m_minuteDisplay->display(m_minutes);
    ui->m_secondDisplay->display(m_seconds);

    m_timer->start(1000);
   }
   else
   {
       ui->m_startButton->setText("Start");
       m_timer->stop();
       ui->m_comboBoxComand->setEnabled(true);
   }
}

