#ifndef BLOCELEMENTBASE_H
#define BLOCELEMENTBASE_H

#include "blocConfiguration.h"
#include "elementBase.h"
#include <QColor>

class BlocElementBase : public blocConfiguration
{
public:
    BlocElementBase();

    int getNbElement() const {
        return listElement.size();
    }

    void setElement(int i, elementBase* elem){
        if(i> listElement.size())return;
        listElement[i] = elem;
    }

    void removeElement(elementBase * elem)
    {
        listElement.removeOne(elem);
    }

    void removeElement(int i)
    {
        listElement.removeAt(i);
    }

    void addElement(elementBase* elem){
        listElement.push_back(elem);
    }

    QList<elementBase*> * getListElementPointer() {return &listElement;}

protected:
    QList<elementBase*> listElement;

};

#endif // BLOCELEMENTBASE_H
