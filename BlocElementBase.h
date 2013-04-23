#ifndef BLOCELEMENTBASE_H
#define BLOCELEMENTBASE_H

#include "blocConfiguration.h"
#include "elementBase.h"

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

protected:

    QList<elementBase*> listElement;

};

#endif // BLOCELEMENTBASE_H
