#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),level(0),intRow(0),intColumn(0),valueStyle(0),soundCheck(true)
{
    ui->setupUi(this);
    ui->tableView->setModel(&model);
    soundButton= new QSound(".//click2.wav");
    readFromFile(".//field.txt");
    resizeField();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeField()
{
    switch(sizeField)
    {
        case 36:
        {
            model.clear();
            createFormMod(6);
            this->setFixedSize(380,489);//6x6
            break;
        }
        case 49:
        {
            model.clear();
            createFormMod(7);
            this->setFixedSize(440,549);//7x7
            break;
        }
        case 64:
        {
            model.clear();
            createFormMod(8);
            this->setFixedSize(500,609);//8x8
            break;
        }
        case 81:
        {
            model.clear();
            createFormMod(9);
            this->setFixedSize(560,669);//9x9
            break;
        }
    }

}
void MainWindow::createFormMod(int sz)
{
    model.setColumnCount(sz);
    model.setRowCount(sz);
    for(int i=0; i<sz;++i)
    {
        for(int j=0; j<sz;++j)
        {
            QStandardItem *itm = new QStandardItem("");
            itm->setEnabled(false);
            itm->setBackground(Qt::darkGray);
            model.setItem(i,j , itm);
        }
        ui->tableView->setColumnWidth( i, 2*ui->tableView->rowHeight(i) );
        ui->tableView->setRowHeight( i, 2*ui->tableView->rowHeight(i) );
    }

}


void MainWindow::readFromFile(QString path)
{
        QFile myFile(path);
        QTextStream data(&myFile);

        if(!myFile.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(this,"Error","Path not correct!");
            return;
        }

       QString allFieldString = data.readAll();//читаю всьо
       sizeFile=allFieldString.count(';');
       //qDebug()<<"sizeFile:"<<sizeFile;
       allFieldList=allFieldString.split(";", QString::SkipEmptyParts);//розбиваю " ; "
       splitField();
       myFile.close();

}


void MainWindow::splitField()
{
     int kst=0;
     if(level<sizeFile)
     {
          QString oneFieldString=allFieldList[level];
          sizeField=oneFieldString.count(" ");
          QStringList itemList=oneFieldString.split(" ", QString::SkipEmptyParts);
          /*
         if(sizeField==36){ sizeMas=6; }
         if(sizeField==49){ sizeMas=7; }
         if(sizeField==64){ sizeMas=8; }
         if(sizeField==81){ sizeMas=9; }
         */
         //qDebug()<<"sizeField :"<<sizeField;
         switch(sizeField)
         {
         case 36:
             sizeMas=6;
             break;
         case 49:
             sizeMas=7;
             break;
         case 64:
             sizeMas=8;
             break;
         case 81:
             sizeMas=9;
             break;
         }

         //for(int i=0; i<model.rowCount(); ++i)
         for(int i=0;i<sizeMas;++i)
         {
             // for(int j=0;j<model.columnCount();++j)
              for(int j=0;j<sizeMas;++j)
              {
                     mas1[i][j]=itemList[kst].toInt();
                     kst ++;
              }
         }

     }

}


void MainWindow::on_pushButton_0_clicked()
{
    slotButtonClicked();
    levelup();
    if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_1_clicked()
{
    slotButtonClicked();
    levelup();
    if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_2_clicked()
{
    slotButtonClicked();
    levelup();
    if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_3_clicked()
{
     slotButtonClicked();
     levelup();
     if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_4_clicked()
{
     slotButtonClicked();
     levelup();
     if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_5_clicked()
{
     slotButtonClicked();
     levelup();
     if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_6_clicked()
{
    slotButtonClicked();
    levelup();
    if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_7_clicked()
{
     slotButtonClicked();
     levelup();
     if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_8_clicked()
{
    slotButtonClicked();
    levelup();
    if( soundCheck ) { soundButton->play(); }
}


void MainWindow::on_pushButton_9_clicked()
{
     slotButtonClicked();
     levelup();
     if( soundCheck ) { soundButton->play(); }
}


void MainWindow::closeEvent(QCloseEvent *bar)
{
    emit ui->actionExit->triggered();
    bar->ignore();
}


 void MainWindow::slotButtonClicked ()
{

     QModelIndex index;

     index= ui->tableView->currentIndex();

     if(intColumn==index.column() && intRow==index.row())
     {
         sender_button+=((QPushButton*)sender())->text();
         if(sender_button.size()>2)
         {
             sender_button.clear();
             sender_button+=((QPushButton*)sender())->text();
         }
     }
     else
     {
         sender_button.clear();
         sender_button+=((QPushButton*)sender())->text();
     }

     model.setData(index, sender_button);

     intColumn=index.column();
     intRow=index.row();
}


 void MainWindow::fillTable()
 {

     QString strItemTable;
     for(int i=0;i<model.columnCount();++i)
     {
         for(int j=0;j<model.rowCount();++j)
         {
             strItemTable = QString::number(mas1[i][j]);
             //qDebug()<<"mas1: "<<mas1[i][j];
             if(strItemTable!="0")
             {
                 QStandardItem *itm = new QStandardItem(strItemTable);
                 itm->setEnabled(false);
                 itm->setBackground(Qt::CrossPattern);
                 //itm->setBackground(Qt::Dense7Pattern);
                 model.setItem(i,j , itm);
             }
             else
             {
                  strItemTable=" ";
                  QStandardItem *itm2 = new QStandardItem(strItemTable);
                  model.setItem(i,j , itm2);

             }

         }
     }


 }


void MainWindow::on_actionNew_Game_triggered()
{

    level=0;
    splitField();
    resizeField();
    fillTable();

}


void MainWindow::MessageBox()
{

    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon(QPixmap(":/new/12.png")));
    msgBox.setWindowTitle(tr("Hidoku"));
    msgBox.setText(tr("         Victory!!!         "));
    msgBox.setInformativeText(tr("        Next level   "));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
void MainWindow::TheEndGame()
{

    QMessageBox end;
    end.setWindowIcon(QIcon(QPixmap(":/new/12.png")));
    end.setWindowTitle(tr("Hidoku"));
    end.setText(tr("         End game!!!         "));
    end.setStandardButtons(QMessageBox::Ok);
    end.exec();
}


void MainWindow::levelup()
{
    if(verify(sizeMas))
    {

        if(level < sizeFile-1)
        {
            if(soundCheck)
            {
              QSound *soundUpLvl= new QSound(".//win2.wav");
              soundUpLvl->play();
            }
            MessageBox();
            level++;
            splitField();
            resizeField();
            fillTable();



        }else
        {
            QSound *soundEnd= new QSound(".//win.wav");
            soundEnd->play();

            TheEndGame();
            level=0;
            splitField();
            resizeField();
            //fillTable();
        }
    }

}


void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Open File"), QString(),
                "Text Files (*.txt);; Data Files (*.ssv)");

    if(!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), QString(tr("Could not open file %1").arg(filename)));
            return;
        }

        QTextStream data(&file);
        QString dataString;
        data<<level<<" "<< sizeMas<< '\n';//записую в файл левел і розмір масива
        for(int j=0; j<model.rowCount(); ++j)
        {
            for(int i=0; i<model.columnCount(); ++i)
            {

                dataString=model.data( model.index(j, i) ).toString()+" ";


                if(dataString =="  ")
                    dataString="0 ";

                data << dataString;

            }
            data << '\n';
        }
        file.close();
    }
}


void MainWindow::on_actionLoad_Game_triggered()
{


    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                "Text Files (*.txt);; Data Files (*.ssv);; Any file (*.* *)");
    if( !filename.isEmpty() )
    {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), QString(tr("Could not open file %1").arg(filename)));
            return;
        }

        QTextStream data(&file);
        QString dataString;
        QStringList dataList;

        dataString=data.readLine();
        dataList=dataString.split(" ", QString::SkipEmptyParts);
        level=dataList[0].toInt();
        splitField();
        resizeField();
        splitField();//заповнив mas1 щоб потім порівняти mas1 і saveMas
        sizeMas=dataList[1].toInt();
        int saveMas[sizeMas][sizeMas];
        int kst=2;
        for(int i = 0; i< sizeMas; ++i)
        {
            dataString = data.readLine();
            dataList+=dataString.split(" ", QString::SkipEmptyParts);


                for(int j=0;j<sizeMas;++j)
                {
                     saveMas[i][j]=dataList[kst].toInt();
                     kst ++;
                }

        }

        QString strItemTable;
        for(int i=0;i<sizeMas;++i)
        {
            for(int j=0;j<sizeMas;++j)
            {



                    strItemTable = QString::number(saveMas[i][j]);
                    if(strItemTable!="0")
                    {
                        if(mas1[i][j]==saveMas[i][j])
                        {
                            QStandardItem *itm = new QStandardItem(strItemTable);
                            itm->setEnabled(false);
                            itm->setBackground(Qt::CrossPattern);
                            //itm->setBackground(Qt::Dense7Pattern);
                            model.setItem(i,j , itm);

                        }else
                        {
                         QStandardItem *itm = new QStandardItem(strItemTable);
                         model.setItem(i,j , itm);
                        }

                    }
                    else
                    {
                        strItemTable=" ";
                        QStandardItem *itm = new QStandardItem(strItemTable);
                        model.setItem(i,j , itm);
                    }


            }
        }

        file.close();
    }
}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox quitMsg;
    quitMsg.setWindowTitle("Hidoku");
    quitMsg.setWindowIcon(QIcon(QPixmap(":/new/12.png")));
    quitMsg.setText("You are going to get aut. Do you want to continue? ");
    quitMsg.setStandardButtons(QMessageBox::Yes |
    QMessageBox::Cancel);
    quitMsg.setButtonText(QMessageBox::Yes,"Exit");
     quitMsg.setButtonText(QMessageBox::Cancel,"Cancel");
    quitMsg.setDefaultButton(QMessageBox::Cancel);
    if (quitMsg.exec() == QMessageBox::Yes)
    QApplication::instance ()->quit();
}

bool MainWindow::verify(int size)
{
    int max=size-1;
    int value;

    int mas[size][size];


     for(int i=0; i<size; ++i)//for(int i=0; i<model.rowCount(); ++i)
     {
         for(int j=0; j<size; ++j)//for(int j=0; j<model.columnCount(); ++j)
         {
             mas[i][j]=model.data( model.index(i, j) ).toInt();
         }
     }



     for(int i=0;i<max+1;++i)
     {
         for(int j=0;j<max+1;++j)
         {
             value=mas[i][j];
             //qDebug()<<"Mas ["<<i<<"] ["<<j<<"]= "<<"Value: "<<value+1;

             if( value == 0 ) { return false ; }
             if( value == sizeField ) { continue ; }



             if((i > 0  &&  j > 0) && (i < max && j < max))
             {

                 if((value+1!=mas[i][j+1]) && (value+1!=mas[i+1][j+1]) && (value+1!=mas[i+1][j]) && (value+1!=mas[i+1][j-1])
                     && (value+1!=mas[i][j-1]) && (value+1!=mas[i-1][j-1]) && (value+1!=mas[i-1][j]) && (value+1!=mas[i-1][j+1]))
                 {  
                    return false;
                 }
             }else if((j==0 && i!=0) && i<max )//ліва лінія
                {
                    if((value+1!=mas[i][j+1]) && (value+1!=mas[i+1][j+1]) && (value+1!=mas[i+1][j])
                                                    && (value+1!=mas[i-1][j]) && (value+1!=mas[i-1][j+1]))
                    {
                        return false;
                    }

                }else if((i==0 && j!=0) && j<max)//верхня лінія
                    {
                        if((value+1!=mas[i][j+1]) && (value+1!=mas[i+1][j+1]) && (value+1!=mas[i+1][j])
                                                    && (value+1!=mas[i+1][j-1]) && (value+1!=mas[i][j-1]))
                        {
                            return false ;
                        }

                    }else if((i==max && j!=0) && j<max)//нижня лінія
                        {
                            if((value+1!=mas[i][j+1]) && (value+1!=mas[i][j-1]) && (value+1!=mas[i-1][j-1])
                                                     && (value+1!=mas[i-1][j]) && (value+1!=mas[i-1][j+1]))
                            {
                                return false;
                            }

                        }else if((j==max && i!=0) && i<max)//права лінія
                            {
                                if((value+1!=mas[i+1][j]) && (value+1!=mas[i+1][j-1]) && (value+1!=mas[i][j-1])
                                                      && (value+1!=mas[i-1][j-1]) && (value+1!=mas[i-1][j]))
                                {
                                    return false;
                                }

                            }else if(i==0 && j==0)//верхній лівий кут
                                {
                                    if((value+1!=mas[i][j+1]) && (value+1!=mas[i+1][j+1]) && (value+1!=mas[i+1][j]))
                                    {
                                        return false;
                                    }

                                }else if(i==0 && j==max)//верхній правий кут
                                    {
                                        if((value+1!=mas[i+1][j]) && (value+1!=mas[i+1][j-1]) && (value+1!=mas[i][j-1]))
                                        {
                                            return false;
                                        }

                                    }else if(i==max && j==0)//нижній лівий кут
                                        {
                                            if((value+1!=mas[i][j+1]) && (value+1!=mas[i-1][j]) && (value+1!=mas[i-1][j+1]))
                                            {
                                                return false;
                                            }

                                        }else if(i==max && j==max)//нижній правий кут
                                            {
                                                if((value+1!=mas[i][j-1]) && (value+1!=mas[i-1][j-1]) && (value+1!=mas[i-1][j]))
                                                {
                                                    return false;
                                                }
                                            }

         }
     }
     return true;
}




void MainWindow::on_actionAbout_Hidoku_triggered()
{
    QMessageBox aboutBox;
    aboutBox.setIcon(QMessageBox::Information);
    aboutBox.setWindowTitle(tr("Hidoku"));
    aboutBox.setWindowIcon(QIcon(QPixmap(":/new/12.png")));
    aboutBox.setText(tr("Hidoku API v1.0"));
    aboutBox.setInformativeText(tr("Author Buta Roman KN-41\nbutaroman@mail.ru\nFebruary 2015 "));
    aboutBox.setStandardButtons(QMessageBox::Ok);
    aboutBox.exec();
}

void MainWindow::on_actionChange_the_look_2_triggered()
{
    if(valueStyle==7)
        valueStyle=0;
    switch(valueStyle)
    {

    case 0:
        {
            this->setStyleSheet("background-image: url(:/new/13.jpg);"
                                "selection-background-color: rgb(32, 252, 255)");
            break;
        }
    case 1:
        {
            this->setStyleSheet("background-image: url(:/new/14.jpg)");
            break;
        }

    case 2:
        {
            this->setStyleSheet(" background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0.506, y2:0.00631818, stop:0.238636 rgba(255, 0, 0, 252), stop:1 rgba(255, 255, 255, 255));"
                                "selection-background-color: rgb(255, 255, 255);"
                                "selection-color: rgb(0, 0, 0)");
            break;
        }
    case 3:
        {
            this->setStyleSheet(" background-color: qlineargradient(spread:pad, x1:0.403, y1:0.363636, x2:1, y2:1, stop:0 rgba(255, 193, 6, 255), stop:1 rgba(255, 255, 255, 255));"
                                "selection-background-color: rgb(255, 255, 255);"
                                "selection-color: rgb(0, 0, 0)");
            break;

        }
    case 4:
        {
            this->setStyleSheet(" background-color: rgb(255, 255, 255);"
                                "selection-background-color: rgb(145, 145, 145);"
                                "selection-color: rgb(0, 0, 0)");
            break;

        }
    case 5:
        {
            this->setStyleSheet(" background-color: rgb(212, 212, 212);"
                                " selection-color: rgb(255, 255, 255);"
                                " selection-background-color: rgb(130, 130, 130)");
            break;
        }

    case 6:
        {
            this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0.323, y1:0.340545, x2:0.818364, y2:0.767, stop:0 rgba(104, 104, 104, 255), stop:1 rgba(195, 195, 195, 255));"
                                "selection-color: rgb(255, 255, 255);"
                                "selection-background-color: rgb(48, 48, 48)");
            break;
        }
    }

    valueStyle++;

}

void MainWindow::on_actionSound_on_off_triggered()
{
    if(soundCheck==true)
    {
        soundCheck=false;
    }
    else
    {
        soundCheck=true;
    }

}
