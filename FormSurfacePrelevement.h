#ifndef FORMSURFACEPRELEVEMENT_H
#define FORMSURFACEPRELEVEMENT_H

#include "FormElementBase.h"
#include "surfacePrelevement.h"

class FormSurfacePrelevement : public FormElementBase
{
    Q_OBJECT
public:
    FormSurfacePrelevement(surfacePrelevement * surface, int mode, QWidget* parent=0);

signals:

public slots:
    void valider();

    void activeResteForm(int val);

private:

    surfacePrelevement * surface;
    QWidget * resteForm;
};

#endif // FORMSURFACEPRELEVEMENT_H
