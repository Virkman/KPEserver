//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_LOGINDIALOG_H
#define KPESERVER_LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>

/*!
 * Makes class LoginDialog a child to its parent, QDialog
*/
class LoginDialog : public QDialog {
/*!
 * Turns Login Dialog into a QObject
*/
Q_OBJECT

private:
    /*!
    * A label for the username component.
    */
    QLabel *labelUsername;

/*!
 * A label for the password.
 */
    QLabel *labelPassword;

/*!
 * An editable combo box for allowing the user
 * to enter his username or select it from a list.
 */
    //QComboBox *comboUsername;
    QLineEdit *editUsername;
/*!
 * A field to let the user enters his password.
 */
    QLineEdit *editPassword;

/*!
 * The standard dialog button box.
 */
    QDialogButtonBox *buttons;

    // attempts, 3 strikes and out!!
    int att;

    bool DE2off;

/*!
 * A method to set up all dialog components and
 * initialize them.
 */
    void setUpGUI();

public:
    explicit LoginDialog(QWidget *parent = 0);



    /*!
    * Sets the current password to propose to the user for the login.
    * password the password to fill into the dialog form
    */
    void clearInput();
    void showMe();


signals:

/*!
 * A signal emitted when the login is performed.
 * username the username entered in the dialog
 * password the password entered in the dialog
 * index the number of the username selected in the combobox
 */
    void acceptLogin(QString &username, QString &password);

public slots:

    /*!
    * A lot to adjust the emitting of the signal.
    */
    void slotAcceptLogin();

};

#endif //KPESERVER_LOGINDIALOG_H
