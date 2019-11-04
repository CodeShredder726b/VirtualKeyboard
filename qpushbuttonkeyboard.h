#ifndef QPUSHBUTTONKEYBOARD_H
#define QPUSHBUTTONKEYBOARD_H
#include <QPushButton>

class QPushButtonKeyboard : public QPushButton
{
    Q_OBJECT

public:
    QPushButtonKeyboard(QString notTranslatedText, QWidget * parent = NULL);

private slots:
    //void getKeyPress();

signals:
    //void pressedKey();

private:
    QWidget * m_parent;
    QString m_notTranslatedText;

protected:
    void mousePressEvent(QMouseEvent * event);
};

#endif // QPUSHBUTTONKEYBOARD_H
