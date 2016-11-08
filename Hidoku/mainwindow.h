#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QCloseEvent>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QSound>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    bool verify(int size);
    void fillTable();
    void levelup();
    void MessageBox ();
    void TheEndGame();
    void slotButtonClicked ();
    void readFromFile(QString path);
    void splitField();
    void createFormMod(int sz);
    void resizeField();
    void closeEvent(QCloseEvent *bar);
    ~MainWindow();

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    void on_actionNew_Game_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_Game_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_Hidoku_triggered();
    void on_actionChange_the_look_2_triggered();

    void on_actionSound_on_off_triggered();

private:
    Ui::MainWindow *ui;

    QStandardItemModel model;
    QString sender_button;
    QStringList allFieldList;
    QSound *soundButton;
    int level;
    int intRow;
    int intColumn;
    int sizeFile;
    int sizeField;
    int mas1[9][9];
    int sizeMas;
    int valueStyle; 
    bool soundCheck;

};

#endif // TABLEMODEL_H
