#include "level_4.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <qdebug.h>
#include <QFile>
#include <QTextStream>
#include "string"


using namespace std;

/*!
 * \brief Level_4::Level_4
 * Initialize Level1 - Screen/Scene Setup...
 */
Level_4::Level_4()
{
    /*!Set Application-Name*/
    setWindowTitle(tr("Hole in One - Level 4"));

    //Screen setup. No scroll bar available
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    //Scene setup
    level4 = new QGraphicsScene();
    level4->setSceneRect(0,0,1024,768);
    setScene(level4);

    showLevel();
}

/*!
 * \brief Level_4::update
 * update function for moveable objects like our ball - sets the graphics of the ball to the position
 * of the box2D body.
 */
void Level_4::update(){
    myWorld4->Step(framerate, 20, 20);

    win = ball->drawBall1(); //nur bewegende Elemente in Update

        if (win==true){
        Level_4::pauseLevel();

        msgbox = new MeinElement(level4,QPointF(375,275),300,175);

        QGraphicsTextItem * winText = new QGraphicsTextItem;
        winText->setPos(400,300);
        winText->setPlainText("You have finished Level 4!");
        level4->addItem(winText);
        saveLevel();
        if(newhighscore){
            QGraphicsTextItem* highscoretext=new QGraphicsTextItem();
            highscoretext->setPos(400,350);
            highscoretext->setPlainText("New Highscore!!");
            level4->addItem(highscoretext);

        }
        QGraphicsTextItem * timeText = new QGraphicsTextItem;
        timeText->setPos(400,400);
        QString time = QString("Time: %3 s").arg(leveltime);
        timeText->setPlainText( time);
        level4->addItem(timeText);
        QPushButton* quitLevel = new QPushButton("Quit");
        quitLevel->move(400,440);
        level4->addWidget(quitLevel);
        connect(quitLevel, SIGNAL(clicked()),this,SLOT(closeLevel()));

    }
}

void Level_4::closeLevel(){
    emit levelcompleted();
    this->close();
}

/*!
 * \brief Level_4::startLevel
 * Set the flag of the QGraphicsItem, after start was clicked.
 * draw the graphics if the body was moved before start was clicked.
 */
void Level_4::startLevel(){

    recyclebin1->drawGraphics();
    recyclebin1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    recyclebin2->drawGraphics();
    recyclebin2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);

    ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);

    if(counterRec==1){
        addblock1->drawGraphics();
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterRec==2){
        addblock1->drawGraphics();
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        addblock2->drawGraphics();
        addblock2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock2->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterCircle==1){
        addcircle1->drawGraphics();
        addcircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterCircle==2){
        addcircle1->drawGraphics();
        addcircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addcircle2->drawGraphics();
        addcircle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterTriangle==1){
        if(addtriangle1!=NULL){
           addtriangle1->drawGraphics();
           addtriangle1->graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
           }
    }
    if(counterTriangle==2){

        if(addtriangle1!=NULL){
           addtriangle1->drawGraphics();
           addtriangle1->graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
           }
        if(addtriangle2!=NULL){
           addtriangle2->drawGraphics();
           addtriangle2->graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
           }
    }

    timer=new QTimer(this);
    timer->setInterval(1.0/120.0*1000.0);
    timer->connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);
    bt__rect->setEnabled(false);
    bt__circle->setEnabled(false);
    bt__triangle->setEnabled(false);

    leveltime_elapsed.start();

}

/*!
 * \brief Level_4::pauseLevel
 * pauses game when button pause is clicked
 */
void Level_4::pauseLevel(){
    if(timer!=NULL){
        timer->stop();
    }
    Level_4::getTime();
    Level_4::highscoreCounter();
    bt_pause->setEnabled(false);
    bt__resume->setEnabled(true);
    bt_start->setEnabled(false);


}

/*!
 * \brief Level_4::resumeLevel
 * resumes game when button resume is clicked
 */
void Level_4::resumeLevel()
{
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);

}

/*!
 * \brief Level_4::addRectangle
 * Create new rectangle and count the rectangle items. limited to number.
 */
void Level_4::addRectangle()
{
    counterRec++;

    switch(counterCircle){
        case 1:
            addcircle1->graphics->setSelected(false);
            break;
        case 2:
            addcircle1->graphics->setSelected(false);
            addcircle2->graphics->setSelected(false);
            break;
        }
        switch(counterTriangle){
        case 1:
            addtriangle1->graphics->setSelected(false);
            break;
        case 2:
            addtriangle1->graphics->setSelected(false);
            addtriangle2->graphics->setSelected(false);
            break;



        }

    if (counterRec==1){
        addblock1 = new Block(myWorld4, level4, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");
        addblock1->graphics->setSelected(true);
        bt__rect->sethoverpic(QPixmap(":/images/images/rec1hover.png"));
        bt__rect->setdefaultpic(QPixmap(":/images/images/rec1default.png"));


    }

    else if(counterRec==2){
        addblock2 = new Block(myWorld4, level4, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");
        addblock2->graphics->setSelected(true);
        addblock1->graphics->setSelected(false);
        bt__rect->sethoverpic(QPixmap(":/images/images/rec0.png"));
        bt__rect->setdefaultpic(QPixmap(":/images/images/rec0.png"));
        bt__rect->setEnabled(false);

    }

}

/*!
 * \brief Level_4::addCircle
 * Create new Circle and count the circle items. Limited to number.
 */

void Level_4::addCircle(){
    counterCircle++;

    b2CircleShape circle;

    switch(counterTriangle){
    case 1:
        addtriangle1->graphics->setSelected(false);
        break;
    case 2:
        addtriangle1->graphics->setSelected(false);
        addtriangle2->graphics->setSelected(false);
        break;

        break;

    }

    switch(counterRec){
    case 1:
        addblock1->graphics->setSelected(false);
        break;
    case 2:
        addblock1->graphics->setSelected(false);
        addblock2->graphics->setSelected(false);
        break;


    }

    if(counterCircle==1){
        circle.m_radius = 21.0;
        addcircle1 = new Circle(myWorld4, level4, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");
        addcircle1->graphics->setSelected(true);
        bt__circle->sethoverpic(QPixmap(":/images/images/circle1hover.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circle1default.png"));

        addcircle1->draw();

    }

    if(counterCircle==2){
        circle.m_radius = 21.0;
        addcircle2 = new Circle(myWorld4, level4, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");
        addcircle1->graphics->setSelected(false);
        addcircle2->graphics->setSelected(true);
        bt__circle->sethoverpic(QPixmap(":/images/images/circ0.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circ0.png"));
        bt__circle->setEnabled(false);
        addcircle2->draw();

    }

}

/*!
 * \brief Level_4::addTriangle
 * Create new Triangle and count the triangle items. Limited to number.
 */
void Level_4::addTriangle()
{
    counterTriangle++;

    switch(counterRec){
    case 1:
        addblock1->graphics->setSelected(false);
        break;
    case 2:
        addblock1->graphics->setSelected(false);
        addblock2->graphics->setSelected(false);
        break;


    }

    switch(counterCircle){
    case 1:
        addcircle1->graphics->setSelected(false);
        break;
    case 2:
        addcircle1->graphics->setSelected(false);
        addcircle2->graphics->setSelected(false);
        break;
    }

    if(counterTriangle==1){
        addtriangle1 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0), 0, b2_staticBody, 1.0,"tool");
        addtriangle1->graphics->setSelected(true);
        bt__triangle->sethoverpic(QPixmap(":/images/images/tri1hover.png"));
        bt__triangle->setdefaultpic(QPixmap(":/images/images/tri1default.png"));
       // addtriangle1->draw();


    }

    if(counterTriangle==2){
        addtriangle2 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0), 0, b2_staticBody, 1.0,"tool");
        addtriangle2->graphics->setSelected(true);
        addtriangle1->graphics->setSelected(false);
        bt__triangle->sethoverpic(QPixmap(":/images/images/tri0.png"));
        bt__triangle->setdefaultpic(QPixmap(":/images/images/tri0.png"));

        bt__triangle->setEnabled(false);
       // addtriangle2->draw();

    }

}

/*!
 * \brief Level_4::getTime
 * Stop time and convert it to ms.
 */
void Level_4::getTime(){
    leveltime = leveltime_elapsed.elapsed(); //leveltime in msec
    leveltime = ((double)((long)(leveltime)))/1000; //leveltime in sec
}

/*!
 * \brief Level_4::highscoreCounter
 * Calculate the highscore.
 */
void Level_4::highscoreCounter(){

    counterTogether = counterRec + counterCircle + counterTriangle;

    if ( (counterTogether==6)||(counterTogether==5) ){
        highscore = 1;
    }

    else if( (counterTogether==4)||(counterTogether==3) ){
        highscore = 2;
    }

    else if( (counterTogether==1)||(counterTogether==2)||(counterTogether==0) ){
        highscore = 3;
    }

    highscore=highscore/leveltime*3000;;

}

/*!
 * \brief Level_4::reset
 * Clear scene and load Level again.
 */
void Level_4::reset(){
    pauseLevel();
   level4->clear();
   counterRec = 0;
   counterCircle = 0;
   counterTriangle = 0;

   showLevel();

}

/*!
 * \brief Level_4::quitLevel
 * quits game and writes time/score into highscore table
 */
void Level_4::saveLevel()
{
    QList <QString> levelenab;
        QFile file("level.txt");
        file.open(QIODevice::ReadWrite |QIODevice::Text);
        if(file.exists("level.txt")){

            levelenab.clear();
            while(!file.atEnd()){
                levelenab.append(file.readLine());
            }
           file.resize(0);

        }

        if(levelenab.size()>14){
            if(levelenab.at(16).toInt()<=highscore){
                QStringList timescortest=levelenab.at(14).split(" ");
                if(timescortest.at(0).toDouble()>leveltime){
                    levelenab.replace(14,QString::number(leveltime)+" s\n");
                    levelenab.replace(15,QString::number(counterTogether)+"\n");
                    levelenab.replace(16,QString::number(highscore)+"\n");
                    newhighscore=true;
                }else{
                    newhighscore=false;
                }

            }else{
                newhighscore=false;
            }

        }
        else{

            levelenab.insert(14,QString::number(leveltime)+" s\n");
            levelenab.insert(15,QString::number(counterTogether)+"\n");
            levelenab.insert(16,QString::number(highscore)+"\n");
            newhighscore=true;
        }

        QTextStream out(&file);
        foreach (QString data, levelenab) {
            out<<data;
        }


        file.close();

}

/*!
 * \brief Level_4::showLevel
 * Create all Objects for Level 1.
 * Connect Buttons with SLOT.
 */
void Level_4::showLevel(){

     //set Background Image
     QPixmap background(":/pic/Game_background_spwn.png");
     background.scaled(QSize(1021,766));
     backgnd = level4->addPixmap(background);
     backgnd->setPos(0,0); //Set Graphic to top left corner
     backgnd->setFlag(QGraphicsItem::ItemIsMovable, false);

     //Start Button
     bt_start=new picButton(QPixmap(":/images/images/startdefault.png"), QPixmap(":/images/images/starthover.png"));
     bt_start->move(726.0,640.0);
     connect(bt_start,SIGNAL(clicked()),this,SLOT(startLevel()), Qt::QueuedConnection);
     level4->addWidget(bt_start);

     //Pause Button
     bt_pause=new picButton(QPixmap(":/images/images/pauseenabled.png"), QPixmap(":/images/images/pausehover.png"));
     bt_pause->setEnabled(false);
     bt_pause->move(865.0,640.0);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(getTime()),Qt::QueuedConnection);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(highscoreCounter()),Qt::QueuedConnection);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(pauseLevel()),Qt::QueuedConnection);
     level4->addWidget(bt_pause);

     //Resume Button
     bt__resume=new picButton(QPixmap(":/images/images/resumeenabled.png"), QPixmap(":/images/images/resumehover.png"));
     bt__resume->setEnabled(false);
     bt__resume->move(726.0, 685.0);
     connect(bt__resume,SIGNAL(clicked()),this,SLOT(resumeLevel()));
     level4->addWidget(bt__resume);

     //Reset
     bt__reset=new picButton(QPixmap(":/images/images/resetenabled.png"), QPixmap(":/images/images/resethover.png"));
     bt__reset->setEnabled(true);
     bt__reset->move(865.0, 685.0);
     connect(bt__reset, SIGNAL(clicked()), this, SLOT(reset()), Qt::QueuedConnection);
     level4->addWidget(bt__reset);

     //Rect Button
     bt__rect=new picButton(QPixmap(":/images/images/rec2default.png"), QPixmap(":/images/images/rec2hover.png"));
     bt__rect->setEnabled(true);
     bt__rect->move(219.0,640.0);
     connect(bt__rect,SIGNAL(clicked()),this,SLOT(addRectangle()), Qt::QueuedConnection);
     level4->addWidget(bt__rect);

     //Circle Button
     bt__circle=new picButton(QPixmap(":/images/images/circ2default.png"), QPixmap(":/images/images/circ2hover.png"));
     bt__circle->setEnabled(true);
     bt__circle->move(378.0,640.0);
     connect(bt__circle,SIGNAL(clicked()),this,SLOT(addCircle()), Qt::QueuedConnection);
     level4->addWidget(bt__circle);

     //Triangle Button
     bt__triangle=new picButton(QPixmap(":/images/images/tri2default.png"), QPixmap(":/images/images/tri2hover.png"));
     bt__triangle->setEnabled(true);
     bt__triangle->move(537.0,640.0);
     connect(bt__triangle,SIGNAL(clicked()),this,SLOT(addTriangle()), Qt::QueuedConnection);
     level4->addWidget(bt__triangle);

     //Rotate Left
     bt__left=new picButton(QPixmap(":/images/images/rotleftdefault.png"), QPixmap(":/images/images/rotlefthover.png"));
     bt__left->setEnabled(true);
     bt__left->move(30.0,654.0);
     bt__left->setShortcut(Qt::Key_Left);
     connect(bt__left,SIGNAL(clicked()),this,SLOT(rotateLeft()), Qt::QueuedConnection);
     level4->addWidget(bt__left);

     //Rotate Right
     bt__right=new picButton(QPixmap(":/images/images/rotrightdefault.png"), QPixmap(":/images/images/rotrighthover.png"));
     bt__right->setEnabled(true);
     bt__right->move(30.0,699.0);
     bt__right->setShortcut(Qt::Key_Right);
     connect(bt__right,SIGNAL(clicked()),this,SLOT(rotateRight()), Qt::QueuedConnection);
     level4->addWidget(bt__right);

     //Levelmenue
     bt_levelmenue=new picButton(QPixmap(":/images/images/levelmenue_bt.png"), QPixmap(":/images/images/levelmenue_hover.png"));
     bt_levelmenue->setEnabled(true);
     bt_levelmenue->move(30.0,609.0);
     connect(bt_levelmenue,SIGNAL(clicked()),this,SLOT(closeLevel()), Qt::QueuedConnection);
     level4->addWidget(bt_levelmenue);


     b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!
     myWorld4 = new b2World(gravity);

     float32 timeStep = 1.0/100.0;     //the length of time passed to simulate (seconds)
     int32 velocityIterations = 8.0;   //how strongly to correct velocity
     int32 positionIterations = 3.0;   //how strongly to correct position

     myWorld4->Step(timeStep, velocityIterations, positionIterations);

     b2CircleShape circle;
     circle.m_radius = 21.0;

     umrandung1 = new MeinElement(myWorld4,level4, b2Vec2 (-30.0,0.0), 10, 1024, b2_staticBody, 1.0);
     umrandung2 = new MeinElement(myWorld4,level4, b2Vec2 (1002.0,0.0), 0, 1024, b2_staticBody, 1.0);

     ball  = new Paperball(myWorld4, level4, QPointF(540.0,20.0), 0*(3.14/180.0), b2_dynamicBody, circle);

     trampoline1 = new Trampoline(myWorld4,level4,b2Vec2(200,220),0,100,40,b2_staticBody,1.0,"obs");
     trampoline2 = new Trampoline(myWorld4,level4,b2Vec2(100,220),0,100,40,b2_staticBody,1.0,"obs");

     obstaclesrec1=new Block(myWorld4,level4,b2Vec2(1000,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec2=new Block(myWorld4,level4,b2Vec2(300,100),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec2=new Block(myWorld4,level4,b2Vec2(400,100),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec3=new Block(myWorld4,level4,b2Vec2(500,100),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec4=new Block(myWorld4,level4,b2Vec2(600,100),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec5=new Block(myWorld4,level4,b2Vec2(100,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec6=new Block(myWorld4,level4,b2Vec2(200,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec7=new Block(myWorld4,level4,b2Vec2(300,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec8=new Block(myWorld4,level4,b2Vec2(500,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec9=new Block(myWorld4,level4,b2Vec2(600,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec10=new Block(myWorld4,level4,b2Vec2(700,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec11=new Block(myWorld4,level4,b2Vec2(800,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec12=new Block(myWorld4,level4,b2Vec2(900,225),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec13=new Block(myWorld4,level4,b2Vec2(350,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec14=new Block(myWorld4,level4,b2Vec2(450,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec15=new Block(myWorld4,level4,b2Vec2(550,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec16=new Block(myWorld4,level4,b2Vec2(300,500),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec17=new Block(myWorld4,level4,b2Vec2(100,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec18=new Block(myWorld4,level4,b2Vec2(0,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec19=new Block(myWorld4,level4,b2Vec2(750,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec20=new Block(myWorld4,level4,b2Vec2(850,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec21=new Block(myWorld4,level4,b2Vec2(950,400),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec22=new Block(myWorld4,level4,b2Vec2(200,500),0,100,40,b2_staticBody,1.0,"obs");

     obstacletriangle1=new Triangle(myWorld4,level4,QPointF(300,280),QPointF(400,280),QPointF(400,380),1.57,b2_staticBody,1.0,"obs");
     obstacletriangle2=new Triangle(myWorld4,level4,QPointF(400,280),QPointF(500,280),QPointF(500,380),3.1415,b2_staticBody,1.0,"obs");

     recyclebin1 = new RecycleBin(myWorld4, level4, QPointF(500,508),QPointF(510,508),QPointF(530,568),QPointF(520,568), 0.0, b2_staticBody);
     recyclebin2 = new RecycleBin(myWorld4, level4, QPointF(550,568),QPointF(570,508),QPointF(580,508),QPointF(560,568), 0.0, b2_staticBody);
     recyclebin3 = new RecycleBinGraphics(level4);

     bottom= new MeinElement(myWorld4, level4, b2Vec2(0.0,level4->height()-200), level4->width(), 22, b2_staticBody, 0.1);

     ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
     ball->drawBall1();

     bottom->drawBottom();
     umrandung1->graphics->hide();
     umrandung2->graphics->hide();

}

/*!
 * \brief Level_4::rotateLeft
 * possibility to rotate objects to the left
 */
void Level_4::rotateLeft(){
    qreal angle;
    if(counterRec==1){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level4->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld4, level4, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
    }
    if(counterRec==2){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level4->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld4, level4, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle-0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level4->removeItem(addblock2->graphics);
            addblock2->body->GetWorld()->DestroyBody(addblock2->body);
            addblock2 =new Block(myWorld4, level4, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
            addblock2->graphics->setSelected(true);
        }

    }
    if(counterTriangle==1){
        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1--;

            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }
            else if(counterTriangleangle1==0){
                angle=0;
            }

            level4->removeItem(addtriangle1->graphics);
            addtriangle1->body->GetWorld()->DestroyBody(addtriangle1->body);
            addtriangle1 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
            addtriangle1->graphics->setSelected(true);
        }
    }

    if(counterTriangle==2){


        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1--;
            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }else if(counterTriangleangle1==0){
                angle=0;
            }

            level4->removeItem(addtriangle1->graphics);
            addtriangle1->body->GetWorld()->DestroyBody(addtriangle1->body);
            addtriangle1 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
            addtriangle1->graphics->setSelected(true);

        }else if(addtriangle2->graphics->isSelected()){
            counterTriangleangle2--;
            if(abs(counterTriangleangle2)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle2)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle2)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle2)==4){
                angle=0;
                counterTriangleangle2=0;
            }
            else if(counterTriangleangle2==0){
                angle=0;
             }

            level4->removeItem(addtriangle2->graphics);
            addtriangle2->body->GetWorld()->DestroyBody(addtriangle2->body);
            addtriangle2 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
            addtriangle2->graphics->setSelected(true);

       }
    }
}

/*!
 * \brief Level_4::rotateRight
 * possibility to rotate right
 */
void Level_4::rotateRight(){
    qreal angle;
    if(counterRec==1){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
            //QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level4->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld4, level4, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
    }
    if(counterRec==2){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level4->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld4, level4, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle+0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level4->removeItem(addblock2->graphics);
            addblock2->body->GetWorld()->DestroyBody(addblock2->body);
            addblock2 =new Block(myWorld4, level4, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
            addblock2->graphics->setSelected(true);
        }

    }
    if(counterTriangle==1){
        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1++;
            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }else if(counterTriangleangle1==0){
                angle=0;
            }

            level4->removeItem(addtriangle1->graphics);
            addtriangle1->body->GetWorld()->DestroyBody(addtriangle1->body);
            addtriangle1 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
            addtriangle1->graphics->setSelected(true);
        }

    }
    if(counterTriangle==2){


        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1++;
            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }else if(counterTriangleangle1==0){
                angle=0;
            }

            level4->removeItem(addtriangle1->graphics);
            addtriangle1->body->GetWorld()->DestroyBody(addtriangle1->body);
            addtriangle1 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
            addtriangle1->graphics->setSelected(true);

        }else if(addtriangle2->graphics->isSelected()){
            counterTriangleangle2++;
            if(abs(counterTriangleangle2)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle2)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle2)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle2)==4){
                angle=0;
                counterTriangleangle2=0;
            }
            else if(counterTriangleangle2==0){
                angle=0;
             }

            level4->removeItem(addtriangle2->graphics);
            addtriangle2->body->GetWorld()->DestroyBody(addtriangle2->body);
            addtriangle2 = new Triangle(myWorld4, level4, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
            addtriangle2->graphics->setSelected(true);
       }
    }
}
