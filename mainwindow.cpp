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
    
	QState *stopState = new QState(m_machine);
    m_machine->addState(stopState);

	initRegimStateMachine(stopState, ui->pushButtonStartR1, ui->pushButtonNextStateR1, ui->pushButtonStopR1, ui->labelR1);
	initRegimStateMachine(stopState, ui->pushButtonStartR2, ui->pushButtonNextStateR2, ui->pushButtonStopR2, ui->labelR2);
    m_machine->setInitialState(stopState);
/*	QState *stopR1 = new QState();

    QState *s1R1 = new QState();
    QState *s2R1 = new QState();
    QState *s3R1 = new QState();

    stop->addTransition( ui->pushButtonStartR1, SIGNAL( clicked() ), s1R1 );
    s1->addTransition( ui->pushButtonNextStateR1, SIGNAL( clicked() ), s2R1 );
    s1->addTransition( ui->pushButtonStopR1, SIGNAL( clicked() ), stopR1 );
    s2->addTransition( ui->pushButtonNextStateR1, SIGNAL( clicked() ), s3R1 );
    s2->addTransition( ui->pushButtonStopR1, SIGNAL( clicked() ), stopR1 );
    s3->addTransition( ui->pushButtonNextStateR1, SIGNAL( clicked() ), stopR1 );
    s3->addTransition( ui->pushButtonStopR1, SIGNAL( clicked() ), stopR1 );

    m_machine->addState(stopR1);
    m_machine->addState(s1R1);
    m_machine->addState(s2R1);
    m_machine->addState(s3R1);
    m_machine->setInitialState(stopR1);


    stopR1->assignProperty(ui->label, "text", "In state stop");
    s1R1->assignProperty(ui->label, "text", "In state s1");
    s2R1->assignProperty(ui->label, "text", "In state s2");
    s3R1->assignProperty(ui->label, "text", "In state s3");
    //Finally, we start the state machine:
*/
    m_machine->start();
}

void MainWindow::initRegimStateMachine(QState *stopState, QPushButton *startBttn, QPushButton *nextBttn, QPushButton *stopBttn, QLabel* label)
{
    QState *s1State = new QState(m_machine);
    QState *s2State = new QState(m_machine);
    QState *s3State = new QState(m_machine);

    stopState->addTransition( startBttn, SIGNAL( clicked() ), s1State );
    s1State->addTransition( nextBttn, SIGNAL( clicked() ), s2State );
    s1State->addTransition( stopBttn, SIGNAL( clicked() ), stopState );
    s2State->addTransition( nextBttn, SIGNAL( clicked() ), s3State );
    s2State->addTransition( stopBttn, SIGNAL( clicked() ), stopState );
    s3State->addTransition( nextBttn, SIGNAL( clicked() ), stopState );
    s3State->addTransition( stopBttn, SIGNAL( clicked() ), stopState );

    m_machine->addState(s1State);
    m_machine->addState(s2State);
    m_machine->addState(s3State);

    stopState->assignProperty(label, "text", "In state stop");
    s1State->assignProperty(label, "text", "In state s1");
    s2State->assignProperty(label, "text", "In state s2");
    s3State->assignProperty(label, "text", "In state s3");
    //Finally, we start the state machine:
}



//QObject::connect(s3, SIGNAL(entered()), button, SLOT(showMaximized()));
//QObject::connect(s3, SIGNAL(exited()), button, SLOT(showMinimized()));
