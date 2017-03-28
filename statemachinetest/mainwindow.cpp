#include "stdafx.h"
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
    

	initRegimStateMachine(ui->pushButtonStartR1, ui->pushButtonNextStateR1, ui->pushButtonStopR1, ui->pushButtonPauseR1, ui->labelR1);
	initRegimStateMachine(ui->pushButtonStartR2, ui->pushButtonNextStateR2, ui->pushButtonStopR2, ui->pushButtonPauseR2, ui->labelR2);
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

void MainWindow::initRegimStateMachine(QPushButton *startBttn, QPushButton *nextBttn, QPushButton *stopBttn, QPushButton *pauseBttn, QLabel* label)
{
	QState *stopState = new QState(m_machine);
    QState *s1State = new QState(m_machine);
    QState *s2State = new QState(m_machine);
    QState *s3State = new QState(m_machine);
	QState *pauseState = new QState(m_machine);

    stopState->addTransition( startBttn, SIGNAL( clicked() ), s1State );
    s1State->addTransition( nextBttn, SIGNAL( clicked() ), s2State );
    s1State->addTransition( pauseBttn, SIGNAL( clicked() ), pauseState );
    s1State->addTransition( stopBttn, SIGNAL( clicked() ), stopState );
    s2State->addTransition( nextBttn, SIGNAL( clicked() ), s3State );
    s2State->addTransition( pauseBttn, SIGNAL( clicked() ), pauseState );
    s2State->addTransition( stopBttn, SIGNAL( clicked() ), stopState );
    s3State->addTransition( nextBttn, SIGNAL( clicked() ), stopState );
    s3State->addTransition( pauseBttn, SIGNAL( clicked() ), pauseState );
    s3State->addTransition( stopBttn, SIGNAL( clicked() ), stopState );
    
	pauseState->addTransition( pauseBttn, SIGNAL( clicked() ), s1State );
	pauseState->addTransition( stopBttn, SIGNAL( clicked() ), stopState );
	pauseState->addTransition( startBttn, SIGNAL( clicked() ), s1State );

    m_machine->addState(stopState);
    m_machine->addState(s1State);
    m_machine->addState(s2State);
    m_machine->addState(s3State);
    m_machine->addState(pauseState);

    stopState->assignProperty(label, "text", "In state stopped");
    s1State->assignProperty(label, "text", "In state s1");
    s2State->assignProperty(label, "text", "In state s2");
    s3State->assignProperty(label, "text", "In state s3");
    pauseState->assignProperty(label, "text", "In state pause");
    //Finally, we start the state machine:
    m_machine->setInitialState(stopState);
}



//QObject::connect(s3, SIGNAL(entered()), button, SLOT(showMaximized()));
//QObject::connect(s3, SIGNAL(exited()), button, SLOT(showMinimized()));
