#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    //Paramétrage de la fenêtre
    setWindowTitle(tr("Zero Class Generator"));
    setWindowIcon(QIcon("icone.png"));
    resize(400, 600);

    QVBoxLayout *vboxOnglets = new QVBoxLayout;
    m_onglets = new QTabWidget(this);
    m_page1 = new QWidget;

    m_vboxLayoutPrincipale = new QVBoxLayout;

    //Définition de la classe
    m_formLayoutDefClasse = new QFormLayout;
    m_groupBoxDefClasse = new QGroupBox(tr("Définition de la classe"));

    //On ajoute une QRegExpValidator pour contrôler le nom des classes.
    m_nomClasse = new QLineEdit;
    QRegExp rx("^[a-zA-Z]+$");
    QRegExpValidator * nomClasseValidator = new QRegExpValidator(rx, m_nomClasse);
    m_nomClasse->setValidator(nomClasseValidator);
    m_classeMere = new QLineEdit;
    QRegExpValidator * classeMereValidator = new QRegExpValidator(rx, m_classeMere);
    m_classeMere->setValidator(classeMereValidator);

    m_formLayoutDefClasse->addRow(tr("* &Nom : "), m_nomClasse);
    m_formLayoutDefClasse->addRow(tr("Classe &mère :"), m_classeMere);
    m_groupBoxDefClasse->setLayout(m_formLayoutDefClasse);
    m_vboxLayoutPrincipale->addWidget(m_groupBoxDefClasse);

    //Ajouter des classes et attributs
    m_classesAttributsHBoxLayout = new QHBoxLayout;
    m_groupBoxClassesAttributs = new QGroupBox(tr("Sélectionnez les classes et les attributs à ajouter : "));
    m_classesAAjouter = new QListWidget();
    m_classesAAjouter->setSelectionMode(QAbstractItemView::ExtendedSelection);
    new QListWidgetItem("personnage.h", m_classesAAjouter);
    new QListWidgetItem("arme.h", m_classesAAjouter);
    new QListWidgetItem("magie.h", m_classesAAjouter);
    new QListWidgetItem("nain.h", m_classesAAjouter);
    new QListWidgetItem("magicien.h", m_classesAAjouter);
    new QListWidgetItem("elf.h", m_classesAAjouter);
    m_classesAttributsHBoxLayout->addWidget(m_classesAAjouter);

    //Ajouter des attributs
    m_attributsAAjouter = new QListWidget();
    m_attributsAAjouter->setSelectionMode(QAbstractItemView::ExtendedSelection);
    new QListWidgetItem("QString m_nom", m_attributsAAjouter);
    new QListWidgetItem("int m_vie", m_attributsAAjouter);
    new QListWidgetItem("double m_force", m_attributsAAjouter);
    new QListWidgetItem("double m_age", m_attributsAAjouter);
    new QListWidgetItem("QString m_race", m_attributsAAjouter);
    new QListWidgetItem("QString m_arme", m_attributsAAjouter);
    m_classesAttributsHBoxLayout->addWidget(m_attributsAAjouter);
    m_genererAccesseur = new QCheckBox(tr("Générer les &accesseurs aux attributs."));
    m_groupBoxClassesAttributs->setLayout(m_classesAttributsHBoxLayout);

    m_vboxLayoutPrincipale->addWidget(m_groupBoxClassesAttributs);

    //Options
    m_optionsVBoxLayout = new QVBoxLayout;
    m_groupBoxOptions = new QGroupBox(tr("Options"));
    m_protegerHeader = new QCheckBox(tr("Protéger le &header contre les inclusions multiples."));
    m_protegerHeader->setChecked(true);
    m_headerGuard = new QLineEdit();
    m_genererConstructeur = new QCheckBox(tr("Générer un &constructeur par défaut."));
    m_genererDestructeur = new QCheckBox(tr("Générer un &destructeur."));

    m_optionsVBoxLayout->addWidget(m_protegerHeader);
    m_optionsVBoxLayout->addWidget(m_headerGuard);
    m_optionsVBoxLayout->addWidget(m_genererConstructeur);
    m_optionsVBoxLayout->addWidget(m_genererDestructeur);
    m_optionsVBoxLayout->addWidget(m_genererAccesseur);
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
    m_ajouterLicenceGPL = new QCheckBox(tr("Ajouter la &licence GPL"));
    m_formLayoutCommentaires->addRow(tr("&Auteur :"), m_auteur);
    m_formLayoutCommentaires->addRow(tr("Da&te de création :"), m_dateCreation);
    m_formLayoutCommentaires->addRow(tr("&Rôle de la classe :"), m_roleClasse);
    m_formLayoutCommentaires->addRow(m_ajouterLicenceGPL);
    m_groupBoxCommentaires->setLayout(m_formLayoutCommentaires);
    m_vboxLayoutPrincipale->addWidget(m_groupBoxCommentaires);

    //Les boutons
    m_boutonsHBoxLayout = new QHBoxLayout();
    m_generer = new QPushButton(tr("&Générer"));
    m_quitter = new QPushButton(tr("&Quitter"));
    m_boutonsHBoxLayout->addWidget(m_generer);
    m_boutonsHBoxLayout->addWidget(m_quitter);
    m_boutonsHBoxLayout ->setAlignment(Qt::AlignRight);
    m_vboxLayoutPrincipale->addLayout(m_boutonsHBoxLayout);

    m_page1->setLayout(m_vboxLayoutPrincipale);

    m_onglets->addTab(m_page1, tr("Configuration"));

    vboxOnglets->addWidget(m_onglets);

    this->setLayout(vboxOnglets);

    connect(m_generer, SIGNAL(clicked()), this, SLOT(genererCode()));
    connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_nomClasse, SIGNAL(textEdited(QString)), this, SLOT(saisirHeaderGuard(QString)));
    connect(m_protegerHeader, SIGNAL(stateChanged(int)), this, SLOT(activerHeaderGuard(int)));
}

void FenPrincipale::genererCode()
{
    if(m_nomClasse->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Le nom de la classe est obligatoire."));
        return;
    }
    else
    {

        QString codeGenere = "";

        QList<QListWidgetItem*> listeAttributsSelectionnees;
        listeAttributsSelectionnees = m_attributsAAjouter->selectedItems();

        //On génére les commentaires.
        if(m_groupBoxCommentaires->isChecked())
        {
            codeGenere += "/*\n";

            if(!m_auteur->text().isEmpty())
            {
                codeGenere += tr("Auteur : ");
                codeGenere += m_auteur->text();
                codeGenere += "\n";
            }

            if(!m_dateCreation->text().isEmpty())
            {
                codeGenere += tr("Date de création : ");
                codeGenere += m_dateCreation->text();
                codeGenere += "\n";
            }

            if(!m_roleClasse->toPlainText().isEmpty())
            {
                codeGenere += "\n"+tr("Rôle : ")+"\n";
                codeGenere += m_roleClasse->toPlainText();
                codeGenere += "\n";
            }

            if(m_ajouterLicenceGPL->isChecked())
            {
                codeGenere += "\n"+tr("Licence GPL : ")+"\n\n";
                codeGenere += "This program is free software: you can redistribute it and/or modify "
                              "it under the terms of the GNU General Public License as published by "
                              "the Free Software Foundation, either version 3 of the License, or "
                              "(at your option) any later version.\n"
                              "This program is distributed in the hope that it will be useful, "
                              "but WITHOUT ANY WARRANTY; without even the implied warranty of "
                              "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See th e"
                              "GNU General Public License for more details.\n"
                              "You should have received a copy of the GNU General Public License "
                              "along with this program.  If not, see <https://www.gnu.org/licenses/>";
                codeGenere += "\n";
            }

            codeGenere += "*/\n\n";
        }

        if(!m_nomClasse->text().isEmpty())
        {

            //On protége le header.
            if(m_protegerHeader->isChecked())
            {
                codeGenere += "#ifndef ";
                codeGenere += m_headerGuard->text().toUpper();
                codeGenere += "\n";

                codeGenere += "#define ";
                codeGenere += m_headerGuard->text().toUpper();
                codeGenere += "\n\n";
            }

            //On ajoute la classe QString car on peut en avoir besoin pour les attributs.
            codeGenere += "#include <QString>\n";

            //On ajoute la classe mère
            if(!m_classeMere->text().isEmpty())
            {
                codeGenere += "#include \"";
                codeGenere += m_classeMere->text()+".h";
                codeGenere += "\"\n";
            }

            //On ajoute les classes sélectionnées
            QList<QListWidgetItem*> listeClassesSelectionnees;
            listeClassesSelectionnees = m_classesAAjouter->selectedItems();

            if(listeClassesSelectionnees.size() > 0)
            {

                for (int i = 0; i < listeClassesSelectionnees.size(); ++i) {
                    codeGenere += "#include \"";
                    codeGenere += listeClassesSelectionnees[i]->text();
                    codeGenere += "\"\n";
                }
            }

            codeGenere += "\n";

            //On génére la structure de la classe.
            codeGenere += "class ";
            codeGenere += m_nomClasse->text();

            if(!m_classeMere->text().isEmpty())
            {
                codeGenere += " : public ";
                codeGenere += m_classeMere->text();
            }

            codeGenere += "\n";
            codeGenere += "{\n";
            codeGenere += "    public:";

            //On génére le constructeur.
            if(m_genererConstructeur->isChecked())
            {
                codeGenere += "\n        ";
                codeGenere += m_nomClasse->text();
                codeGenere += "();";
            }

            //On génére le destructeur.
            if(m_genererDestructeur->isChecked())
            {
                codeGenere += "\n        ~";
                codeGenere += m_nomClasse->text();
                codeGenere += "();";
            }

            //On génére les accesseurs.
            if(m_genererAccesseur->isChecked())
            {

                if(listeAttributsSelectionnees.size() > 0)
                {

                    codeGenere += "\n";

                    for (int i = 0; i < listeAttributsSelectionnees.size(); ++i) {
                        codeGenere += "\n        ";
                        QString attribut = listeAttributsSelectionnees[i]->text();
                        QStringList accesseur = attribut.split("m_");
                        codeGenere += accesseur[0]+accesseur[1];
                        codeGenere += "();";
                    }
                }
            }

            codeGenere += "\n\n    ";
            codeGenere += "protected :";
            codeGenere += "\n\n    ";
            codeGenere += "private :\n";

            if(listeAttributsSelectionnees.size() > 0)
            {

                for (int i = 0; i < listeAttributsSelectionnees.size(); ++i) {
                    codeGenere += "\n        ";
                    codeGenere += listeAttributsSelectionnees[i]->text();
                    codeGenere += ";";
                }

                codeGenere += "\n";
            }

            codeGenere += "\n};\n";

            //On protége le header.
            if(m_protegerHeader->isChecked() && !m_headerGuard->text().isEmpty())
            {
                codeGenere += "\n";
                codeGenere += "#endif // ";
                codeGenere += m_headerGuard->text().toUpper();
            }
        }

        m_fenCodeGenere = new FenCodeGenere(codeGenere, genererCPP(), m_nomClasse->text(), this);
        m_fenCodeGenere->exec();
    }
}

void FenPrincipale::saisirHeaderGuard(QString nomClasse)
{
    if(m_protegerHeader->isChecked())
    {
        nomClasse = "HEADER_"+nomClasse.toUpper();
        m_headerGuard->setText(nomClasse);

        if(nomClasse == "HEADER_")
        {
            m_headerGuard->clear();
        }
    }
}

void FenPrincipale::activerHeaderGuard(int state)
{
    if(state == Qt::Unchecked)
    {
        m_headerGuard->clear();
        m_headerGuard->setDisabled(true);
    }
    else if(state == Qt::Checked)
    {
        m_headerGuard->setDisabled(false);

        QString nomClasse = "HEADER_"+m_nomClasse->text().toUpper();
        m_headerGuard->setText(nomClasse);
    }
}

QString FenPrincipale::genererCPP()
{
    QString codeGenere = "";

    //Ajout de l'include de la classe associée au CPP.
    if(!m_nomClasse->text().isEmpty())
    {
        codeGenere += "#include \""+m_nomClasse->text()+".h\"\n";
    }

    //Ajout du constructeur
    if(m_genererConstructeur->isChecked())
    {
        codeGenere += "\n";
        codeGenere += m_nomClasse->text()+"::"+m_nomClasse->text()+"()\n{\n";
        codeGenere += "\n}\n";
    }

    //Ajout du destructeur
    if(m_genererDestructeur->isChecked())
    {
        codeGenere += "\n";
        codeGenere += m_nomClasse->text()+"::~"+m_nomClasse->text()+"()\n{\n";
        codeGenere += "\n}\n";
    }

    //On génére les accesseurs
    if(m_genererAccesseur->isChecked())
    {

        QList<QListWidgetItem*> listeAttributsSelectionnees;
        listeAttributsSelectionnees = m_attributsAAjouter->selectedItems();

        if(listeAttributsSelectionnees.size() > 0)
        {
            codeGenere += "\n";

            for (int i = 0; i < listeAttributsSelectionnees.size(); ++i)
            {
                QString attribut = listeAttributsSelectionnees[i]->text();
                QStringList accesseur = attribut.split("m_");
                QStringList type = attribut.split(" ");
                codeGenere += type[0]+" "+m_nomClasse->text()+"::"+accesseur[1]+"()\n{\n";
                codeGenere += "    return m_"+accesseur[1]+";\n";

                if(i < (listeAttributsSelectionnees.size()-1))
                {
                    codeGenere += "}\n\n";
                }
                else
                {
                    codeGenere += "}\n";
                }
            }
        }
    }

     return codeGenere;
}
