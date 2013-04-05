#include "FormSurfacePrelevement.h"

FormSurfacePrelevement::FormSurfacePrelevement(surfacePrelevement * surface, int mode, QWidget* parent) :
    FormElementBase(surface,mode,parent)
{
    this->surface=surface;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->setMargin(0);
    QGroupBox * groupGeo = new QGroupBox("Surface Prelevement");


    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutTypeSurface = new QHBoxLayout;
    layoutTypeSurface->addWidget(new QLabel("Type Surface:"));
    QComboBox * typeSurfaceWidget = new QComboBox();
    typeSurfaceWidget->addItems(QStringList() << "1" << "2" << "3" << "4");
    layoutTypeSurface->addWidget(typeSurfaceWidget);
    layout->addLayout(layoutTypeSurface);
    this->connect(typeSurfaceWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(activeResteForm(int)));


    QHBoxLayout * layoutNomFichier = new QHBoxLayout;
    layoutNomFichier->addWidget(new QLabel("Nom Fichier:"));
    QLineEdit * nomFichierWidget = new QLineEdit();
    layoutNomFichier->addWidget(nomFichierWidget);
    layout->addLayout(layoutNomFichier);

    resteForm = new QWidget();
    resteForm->setVisible(false);
    QVBoxLayout * layoutResteForm = new QVBoxLayout;
    layoutResteForm->setContentsMargins(0,0,0,0);


    QHBoxLayout * layoutInsideOutside = new QHBoxLayout;
    layoutInsideOutside->addWidget(new QLabel("InsideOutside:"));
    QSpinBox * insideOutsideWidget = new QSpinBox();
    layoutInsideOutside->addWidget(insideOutsideWidget);
    layoutResteForm->addLayout(layoutInsideOutside);

    QHBoxLayout * layoutCompressionLongueur = new QHBoxLayout;
    layoutCompressionLongueur->addWidget(new QLabel("Compression Longueur:"));
    QDoubleSpinBox * compressionLongueurWidget = new QDoubleSpinBox();
    layoutCompressionLongueur->addWidget(compressionLongueurWidget);
    layoutResteForm->addLayout(layoutCompressionLongueur);

    QHBoxLayout * layoutCompressionLargeur = new QHBoxLayout;
    layoutCompressionLargeur->addWidget(new QLabel("Compression Largeur:"));
    QDoubleSpinBox * compressionLargeurWidget = new QDoubleSpinBox();
    layoutCompressionLargeur->addWidget(compressionLargeurWidget);
    layoutResteForm->addLayout(layoutCompressionLargeur);

    QHBoxLayout * layoutCompressionHauteur = new QHBoxLayout;
    layoutCompressionHauteur->addWidget(new QLabel("Compression Hauteur:"));
    QDoubleSpinBox * compressionHauteurWidget = new QDoubleSpinBox();
    layoutCompressionHauteur->addWidget(compressionHauteurWidget);
    layoutResteForm->addLayout(layoutCompressionHauteur);

    resteForm->setLayout(layoutResteForm);

    layout->addWidget(resteForm);

    layout->addWidget(getWidgetElementBase());

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
