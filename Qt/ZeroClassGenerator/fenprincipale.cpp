#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    setWindowTitle("Zero Class Generator");

    m_vboxLayoutPrincipale = new QVBoxLayout;

    //Définition de la classe
    m_formLayoutDefClasse = new QFormLayout;
    m_groupBoxDefClasse = new QGroupBox(tr("Définition de la classe"));
    m_nomClasse = new QLineEdit;
    m_classeMere = new QLineEdit;
    m_formLayoutDefClasse->addRow("&Nom :", m_nomClasse);
    m_formLayoutDefClasse->addRow("Classe &mère :", m_classeMere);
    m_groupBoxDefClasse->setLayout(m_formLayoutDefClasse);
    m_vboxLayoutPrincipale->addWidget(m_groupBoxDefClasse);

    //Options
    m_optionsVBoxLayout = new QVBoxLayout;
    m_groupBoxOptions = new QGroupBox(tr("Options"));
    m_protegerHeader = new QRadioButton(tr("Protéger le &header contre les inclusions multiples"));
    m_protegerHeader->setChecked(true);
    m_genererConstructeur = new QRadioButton("Générer un &constructeur par défaut");
    m_genererDestructeur = new QRadioButton("Générer un &destructeur");
    m_optionsVBoxLayout->addWidget(m_protegerHeader);
    m_optionsVBoxLayout->addWidget(m_genererConstructeur);
    m_optionsVBoxLayout->addWidget(m_genererDestructeur);
    m_groupBoxOptions->setLayout(m_optionsVBoxLayout);
    m_vboxLayoutPrincipale->addWidget(m_groupBoxOptions);

    //Commentaires
    m_formLayoutCommentaires = new QFormLayout;
    m_groupBoxCommentaires = new QGroupBox(tr("Ajouter des commentaires"));
    m_groupBoxCommentaires->setCheckable(true);
    m_groupBoxCommentaires->setChecked(false);
    m_auteur = new QLineEdit;
    m_dateCreation = new QDateTimeEdit(QDate::currentDate());
    m_roleClasse = new QTextEdit;
    m_formLayoutCommentaires->addRow("&Auteur :", m_auteur);
    m_formLayoutCommentaires->addRow("Da&te de création :", m_dateCreation);
    m_formLayoutCommentaires->addRow("&Rôle de la classe :", m_roleClasse);
    m_groupBoxCommentaires->setLayout(m_formLayoutCommentaires);
    m_vboxLayoutPrincipale->addWidget(m_groupBoxCommentaires);

    //Les boutons
    m_boutonsHBoxLayout = new QHBoxLayout();
    m_generer = new QPushButton("&Générer");
    m_quitter = new QPushButton("&Quitter");
    m_boutonsHBoxLayout->addWidget(m_generer);
    m_boutonsHBoxLayout->addWidget(m_quitter);
    m_boutonsHBoxLayout ->setAlignment(Qt::AlignRight);
    m_vboxLayoutPrincipale->addLayout(m_boutonsHBoxLayout);

    setLayout(m_vboxLayoutPrincipale);
    setWindowIcon(QIcon("icone.png"));
    resize(400, 450);
}
