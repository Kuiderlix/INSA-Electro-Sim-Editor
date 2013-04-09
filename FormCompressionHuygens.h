#ifndef FORMCOMPRESSIONHUYGENS_H
#define FORMCOMPRESSIONHUYGENS_H

#include <QtWidgets>
#include "compressionHuygens.h"


class FormCompressionHuygens : public QWidget
{
    Q_OBJECT
public:
    explicit FormCompressionHuygens(compressionHuygens * compreHuy, QWidget *parent = 0);
    
signals:
    
public slots:
    

private:
    compressionHuygens * compreHuy;
};

#endif // FORMCOMPRESSIONHUYGENS_H
