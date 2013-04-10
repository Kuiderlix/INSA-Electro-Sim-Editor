#include "FormSurfacePrelevement.h"

FormSurfacePrelevement::FormSurfacePrelevement(surfacePrelevement * surface, int mode, QWidget* parent) :
    FormElementBase(surface,mode,parent)
{
    this->surface=surface;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Surface Prelevement");


    QFormLayout * layout = new QFormLayout;

    QComboBox * typeSurfaceWidget = new QComboBox();
    typeSurfaceWidget->addItems(QStringList() << "1" << "2" << "3" << "4");
    layout->addRow("Type Surface:",typeSurfaceWidget);
    this->connect(typeSurfaceWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(activeResteForm(int)));


    QLineEdit * nomFichierWidget = new QLineEdit();
    layout->addRow("Nom Fichier:",nomFichierWidget);

    resteForm = new QWidget();
    resteForm->setVisible(false);
    QFormLayout * layoutResteForm = new QFormLayout;
    layoutResteForm->setMargin(0);

    QSpinBox * insideOutsideWidget = new QSpinBox();
    layoutResteForm->addRow("InsideOutside:",insideOutsideWidget);

    QDoubleSpinBox * compressionLongueurWidget = new QDoubleSpinBox();
    layoutResteForm->addRow("Compression Longueur:",compressionLongueurWidget);

    QDoubleSpinBox * compressionLargeurWidget = new QDoubleSpinBox();
    layoutResteForm->addRow("Compression Largeur:",compressionLargeurWidget);

    QDoubleSpinBox * compressionHauteurWidget = new QDoubleSpinBox();
    layoutResteForm->addRow("Compression Hauteur:",compressionHauteurWidget);

    resteForm->setLayout(layoutResteForm);

    layout->addRow(resteForm);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}

void FormSurfacePrelevement::activeResteForm(int val)
{
    if (val==1)
    {
        resteForm->setVisible(true);
    }
    else
    {
        resteForm->setVisible(false);
    }
}
