#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class VirtualKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit VirtualKeyboard(bool numericOnly);
    ~VirtualKeyboard();

    QLineEdit * getLineEdit(void) {return (this->m_lineEdit);}
    bool        isNumpad(void) {return (this->m_isNumpad);}

private:
    QLineEdit * m_lineEdit;
    QLabel *    m_clipboard;
    bool        m_isNumpad;

    QPushButton * createKey(QString keyValue, QString notTranslatedValue);

signals:

public slots:
    void show(QLineEdit * selectedLineEdit);
//    void show(QWidget * activeForm);
    void createKeyboard(void);
};

#endif // VIRTUALKEYBOARD_H
