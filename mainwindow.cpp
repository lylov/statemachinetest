#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStateMachine();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//#include <QState>

void MainWindow::initStateMachine()
{
    m_machine = new QStateMachine();

    QState *s1 = new QState();
    QState *s2 = new QState();
    QState *s3 = new QState();

    s1->addTransition( ui->pushButton, SIGNAL( clicked() ), s2 );
    s2->addTransition( ui->pushButton, SIGNAL( clicked() ), s3 );
    s3->addTransition( ui->pushButton, SIGNAL( clicked() ), s1 );

    m_machine->addState(s1);
    m_machine->addState(s2);
    m_machine->addState(s3);
    m_machine->setInitialState(s1);


    s1->assignProperty(ui->label, "text", "In state s1");
    s2->assignProperty(ui->label, "text", "In state s2");
    s3->assignProperty(ui->label, "text", "In state s3");
    //Finally, we start the state machine:
    m_machine->start();

}



//QObject::connect(s3, SIGNAL(entered()), button, SLOT(showMaximized()));
//QObject::connect(s3, SIGNAL(exited()), button, SLOT(showMinimized()));
