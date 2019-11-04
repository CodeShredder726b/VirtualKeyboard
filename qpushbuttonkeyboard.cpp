#include "qpushbuttonkeyboard.h"
#include "virtualkeyboard.h"

#define DEFAULT_STYLE_BUTTON       "color:white;border: 1px solid #000000;border-radius:6px;"
#define DEFAULT_BACKGROUND_BUTTON  "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #8C8F8C, stop: 1 #000000);"

QPushButtonKeyboard::QPushButtonKeyboard(QString notTranslatedText, QWidget * parent)
    : QPushButton(parent),
      m_parent(parent),
      m_notTranslatedText(notTranslatedText)
{
    //this->setStyleSheet(QString(DEFAULT_STYLE_BUTTON) + QString(DEFAULT_BACKGROUND_BUTTON));

    //connect(this, SIGNAL(pressedKey(bool)), SLOT(getKeyPress(bool)));
}

void QPushButtonKeyboard::mousePressEvent(QMouseEvent * event)
{
    VirtualKeyboard * kybd = (VirtualKeyboard *)this->m_parent;
    QString t = kybd->getLineEdit()->text();

    if(m_notTranslatedText == "ENTER")
    {
        kybd->getLineEdit()->setText("copy to edit");
    }
    else if(m_notTranslatedText == "<=")
    {
        t.chop(1);
        kybd->getLineEdit()->setText(t);
    }
    else if(m_notTranslatedText == "Space")
    {
        kybd->getLineEdit()->setText(t + " ");
    }
    else
    {
        kybd->getLineEdit()->setText(t + m_notTranslatedText);
    }
}
