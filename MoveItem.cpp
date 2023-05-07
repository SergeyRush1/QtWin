#include "moveitem.h"

MoveItem::MoveItem(QObject* parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF(-30, -30, 120, 120);
}

void MoveItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
   




    painter->setPen(Qt::black);
   // painter->setBrush(Qt::green);
    painter->drawEllipse(25, 25, 10, 10);
    painter->setPen(Qt::green);
    painter->drawEllipse(-30, -30, 120, 120);
   // painter->drawRect(-30, -30, 60, 60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    /* ������������� ������� ������������ ��������
     * � ����������� �����, ������������ ����������
     * ������� ������ ������������ ��������
     * � ������������ ������� ����������� �����
     * */
    this->setPos(mapToScene(event->pos()));
    
    
    QString x = QString::number(mapToScene(event->pos()).x());
    emit testSignal(x);
  // int position = event->pos().x();
    //emit


}





void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    /* ��� ������� ����� �� ����������� �������
     * �������� ������ �� ����, ������� ������ ���� ��������
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
   
    
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    /* ��� ���������� ����� ��������
     * �������� �� ������� ������ �������
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
void MoveItem::testSlots2(QString a) {
    this->setPos(0,0);

}
