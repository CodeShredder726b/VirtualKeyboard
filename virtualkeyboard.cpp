#include "virtualkeyboard.h"
#include "qpushbuttonkeyboard.h"

#include <QLayout>

VirtualKeyboard::VirtualKeyboard(bool numericOnly)
    : m_isNumpad(numericOnly),
      m_lineEdit(NULL)
{
    this->createKeyboard();

    /* TODO password line edit only *** */

    //this->m_clipboard->clear();
}

VirtualKeyboard::~VirtualKeyboard()
{}

void VirtualKeyboard::show(QLineEdit * selectedLineEdit)
//void VirtualKeyboard::show(QWidget * activeForm)
{
    m_lineEdit = selectedLineEdit;
    QWidget::show();
}

void VirtualKeyboard::createKeyboard(void)
{
    QVBoxLayout * qvboxLayout = new QVBoxLayout();
    QHBoxLayout * qhboxLayout = new QHBoxLayout();

    /* TODO set echo mode for passwords */
    //qlineEdit->echoMode()
    m_lineEdit = new QLineEdit();
    qhboxLayout->addWidget(m_lineEdit);

    qvboxLayout->insertLayout(0, qhboxLayout);

    if(this->isNumpad())
    {

    }
    else
    {
        /* row 1 */
        qhboxLayout = new QHBoxLayout();
        qhboxLayout->addWidget(createKey("q", "q"));
        qhboxLayout->addWidget(createKey("w", "w"));
        qhboxLayout->addWidget(createKey("e", "e"));
        qhboxLayout->addWidget(createKey("r", "r"));
        qhboxLayout->addWidget(createKey("t", "t"));
        qhboxLayout->addWidget(createKey("z", "z"));
        qhboxLayout->addWidget(createKey("u", "u"));
        qhboxLayout->addWidget(createKey("i", "i"));
        qhboxLayout->addWidget(createKey("o", "o"));
        qhboxLayout->addWidget(createKey("p", "p"));
        qhboxLayout->addWidget(createKey("<=", "<="));

        qvboxLayout->insertLayout(1, qhboxLayout);

        /* row 2 */
        qhboxLayout = new QHBoxLayout();
        qhboxLayout->addWidget(createKey("a", "a"));
        qhboxLayout->addWidget(createKey("s", "s"));
        qhboxLayout->addWidget(createKey("d", "d"));
        qhboxLayout->addWidget(createKey("f", "f"));
        qhboxLayout->addWidget(createKey("g", "g"));
        qhboxLayout->addWidget(createKey("h", "h"));
        qhboxLayout->addWidget(createKey("j", "j"));
        qhboxLayout->addWidget(createKey("k", "k"));
        qhboxLayout->addWidget(createKey("l", "l"));
        qhboxLayout->addWidget(createKey("ENTER", "ENTER"));

        qvboxLayout->insertLayout(2, qhboxLayout);

        /* row 3 */
        qhboxLayout = new QHBoxLayout();
        qhboxLayout->addWidget(createKey("y", "y"));
        qhboxLayout->addWidget(createKey("x", "x"));
        qhboxLayout->addWidget(createKey("c", "c"));
        qhboxLayout->addWidget(createKey("v", "v"));
        qhboxLayout->addWidget(createKey("b", "b"));
        qhboxLayout->addWidget(createKey("n", "n"));
        qhboxLayout->addWidget(createKey("m", "m"));
        qhboxLayout->addWidget(createKey(",", ","));
        qhboxLayout->addWidget(createKey(".", "."));

        qvboxLayout->insertLayout(3, qhboxLayout);

        /* row 4 */
        qhboxLayout = new QHBoxLayout();
        qhboxLayout->addWidget(createKey("123", "123"));
        qhboxLayout->addWidget(createKey("Space", "Space"));
        qhboxLayout->addWidget(createKey("ABC", "ABC"));

        qvboxLayout->insertLayout(4, qhboxLayout);
    }
    qvboxLayout->setMargin(3);

    this->setLayout(qvboxLayout);
}

QPushButton * VirtualKeyboard::createKey(QString keyValue, QString notTranslatedValue)
{
    QPushButtonKeyboard * button = new QPushButtonKeyboard(notTranslatedValue, this);

    button->setText(keyValue);
    button->setObjectName(keyValue);
    //button->setMinimumSize(...,...);
    //button->setMaximumSize(...,...);
    button->setVisible(true);
    return button;
}
