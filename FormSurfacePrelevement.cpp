#include "FormSurfacePrelevement.h"

FormSurfacePrelevement::FormSurfacePrelevement(surfacePrelevement * surface, int mode, QWidget* parent) :
    FormElementBase(surface,mode,parent)
{
    this->surface=surface;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Surface Prelevement");


    QFormLayout * layout = new QFormLayout;

    typeSurfaceWidget = new QComboBox();
    typeSurfaceWidget->addItems(QStringList() << "Huygens" << "Surface_de_prelevement_DG" << "Kirchhoff");
    layout->addRow("Type Surface:",typeSurfaceWidget);
    this->connect(typeSurfaceWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(activeResteForm(int)));


    nomFichierWidget = new QLineEdit();
    layout->addRow("Nom Fichier:",nomFichierWidget);

    resteForm = new QWidget();
    resteForm->setVisible(false);
    QFormLayout * layoutResteForm = new QFormLayout;
    layoutResteForm->setMargin(0);

    insideOutsideWidget = new QSpinBox();
    layoutResteForm->addRow("InsideOutside:",insideOutsideWidget);

    nbFacesWidget = new QComboBox();
    nbFacesWidget->addItems(QStringList() << "5 Faces" << "6 Faces");
    layoutResteForm->addRow("Nb faces:",nbFacesWidget);

    compressionLongueurWidget = new QDoubleSpinBox();
    layoutResteForm->addRow("Compression Longueur:",compressionLongueurWidget);

    compressionLargeurWidget = new QDoubleSpinBox();
    layoutResteForm->addRow("Compression Largeur:",compressionLargeurWidget);

    compressionHauteurWidget = new QDoubleSpinBox();
    layoutResteForm->addRow("Compression Hauteur:",compressionHauteurWidget);

    resteForm->setLayout(layoutResteForm);

    layout->addRow(resteForm);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);


    init();

}

void FormSurfacePrelevement::valider()
{
    FormElementBase::valider();

    surface->SetTypeSurface(typeSurfaceWidget->currentIndex()+1);
    surface->SetNomFichier(nomFichierWidget->text().toStdString());
    surface->SetInsideOutside(insideOutsideWidget->value());
    surface->SetNbFaces(nbFacesWidget->currentIndex()+5);
    surface->SetCompressionHauteur(compressionHauteurWidget->value());
    surface->SetCompressionLargeur(compressionLargeurWidget->value());
    surface->SetCompressionLongueur(compressionLongueurWidget->value());

    emit elementValide(surface);
}

void FormSurfacePrelevement::reset()
{
    FormElementBase::reset();
    this->surface = new surfacePrelevement();
    setElement(this->surface);
    init();
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

void FormSurfacePrelevement::init()
{
    FormElementBase::init();
    typeSurfaceWidget->setCurrentIndex(surface->GetTypeSurface()-1);
    nomFichierWidget->setText(QString(surface->GetNomFichier().c_str()));
    insideOutsideWidget->setValue(surface->GetInsideOutside());
    nbFacesWidget->setCurrentIndex(surface->GetNbFaces()-5);
    compressionLongueurWidget->setValue(surface->GetCompressionLongueur());
    compressionLargeurWidget->setValue(surface->GetCompressionLargeur());
    compressionHauteurWidget->setValue(surface->GetCompressionHauteur());
}
