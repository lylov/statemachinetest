#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private:
    void initStateMachine();
	void initRegimStateMachine(QState *stopState, QPushButton *startBttn, QPushButton *nextBttn, QPushButton *stopBttn, QLabel* label);

private:
    QStateMachine *m_machine;
};

#endif // MAINWINDOW_H
