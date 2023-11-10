#include <iostream>
#include <string>
#include <vector>

class Utilisateur {
protected:
    int id;
    std::string nom;

public:
    // Constructor
    Utilisateur(int id, const std::string& nom) {
        this->id = id;
        this->nom = nom;
    }

    // Member functions to access the attributes
    int getId() const {
        return id;
    }

    std::string getNom() const {
        return nom;
    }

    // Member function to set the 'nom' attribute
    void setNom(const std::string& newNom) {
        nom = newNom;
    }

    // Function to add a new user
    static void ajouterUser(Utilisateur& user, std::vector<Utilisateur>& users) {
        users.push_back(user);
    }

    // Function to remove a user by their ID
    static void supprimerUser(int userId, std::vector<Utilisateur>& users) {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->getId() == userId) {
                users.erase(it);
                break;
            }
        }
    }

    // Function to search for a user by their ID
    static Utilisateur* rechercherUser(int userId, std::vector<Utilisateur>& users) {
        for (auto& user : users) {
            if (user.getId() == userId) {
                return &user;
            }
        }
        return nullptr; // User not found
    }

    // Function to display all users
    static void afficherUsers(const std::vector<Utilisateur>& users) {
        for (const auto& user : users) {
            std::cout << "User ID: " << user.getId() << ", User Name: " << user.getNom() << std::endl;
        }
    }
};

class Administrateur : public Utilisateur {
private:
    std::string role;
      
public:
    Administrateur(int id, const std::string& nom, const std::string& role) : Utilisateur(id, nom), role(role) {}

    const std::string& getRole() const {
        return role;
    }

    void setRole(const std::string& newRole) {
        role = newRole;
    }


};



class OutilInformatique {

protected:
    std::string type;
    std::string reference;
    std::string modele;
    int quantite;
    bool etat;            // Added attribute: state of the tool (true for functional, false for not functional)
    int id_fournisseur;   // Added attribute: ID of the supplier

public:
    OutilInformatique(const std::string& type, const std::string& reference, const std::string& modele, int quantite,
                      bool etat, int id_fournisseur)
        : type(type), reference(reference), modele(modele), quantite(quantite), etat(etat), id_fournisseur(id_fournisseur) {}

    // Member function to display the details of the tool
    void afficherOutil() const {
        std::cout << "Type: " << type << ", Reference: " << reference
                  << ", Modele: " << modele << ", Quantite: " << quantite
                  << ", Etat: " << (etat ? "Functional" : "Not Functional")
                  << ", ID Fournisseur: " << id_fournisseur << std::endl;
    }

    void setEtat(OutilInformatique& outil, bool etat) {
        outil.setEtat(etat);
        std::cout << "Setting the state of tool: " << outil.getReference() << " to "
                  << (etat ? "Functional" : "Not Functional") << std::endl;
    }


    // Getters for individual attributes
    const std::string& getType() const {
        return type;
    }

    const std::string& getReference() const {
        return reference;
    }

    const std::string& getModele() const {
        return modele;
    }

    int getQuantite() const {
        return quantite;
    }

     static OutilInformatique* rechercherParReference(const std::string& reference, std::vector<OutilInformatique>& tools) {
        for (auto& tool : tools) {
            if (tool.getReference() == reference) {
                return &tool;
            }
        }
        return nullptr; // Tool not found
    }


};

class PC : public OutilInformatique {
private:
    std::string os;
    std::string processor;
    int id_user{00000}; // Added initial value

public:
    PC(const std::string& type, const std::string& reference, const std::string& modele, int quantite,
        const std::string& os, const std::string& processor, int id_user = 00000)
        : OutilInformatique(type, reference, modele, quantite, true, 1), os(os), processor(processor), id_user(id_user) {}

    // Member function to display PC details, including additional attributes
    void afficherPC() const {
        afficherOutil();
        std::cout << "Operating System: " << os << ", Processor: " << processor
                  << ", ID User: " << id_user << std::endl;
    }

    // Getters for additional PC attributes
    const std::string& getOS() const {
        return os;
    }

    const std::string& getProcessor() const {
        return processor;
    }

    int getIdUser() const {
        return id_user;
    }
};

class Peripherique : public OutilInformatique {

private:
    std::string interfaceType;
    int id_user{00000};

public:
    Peripherique(const std::string& type, const std::string& reference, const std::string& modele, int quantite,
                 const std::string& interfaceType,int id_user = 00000)
        : OutilInformatique(type, reference, modele, quantite), interfaceType(interfaceType),id_user(id_user) {}

    // Member function to display peripheral details, including additional attributes
    void afficherPeripherique() const {
        afficherOutil();
        std::cout << "Interface Type: " << interfaceType 
             << ", ID User: " << id_user << std::endl;
    }

    // Getter for the additional peripheral attribute
    const std::string& getInterfaceType() const {
        return interfaceType;
    }

     int getIdUser() const {
        return id_user;
    }

};


class Serveur : public OutilInformatique {
      
private:
    int stockage;

public:
    Serveur(const std::string& reference, const std::string& modele, int quantite, int stockage)
        : OutilInformatique("Serveur", reference, modele, quantite), stockage(stockage) {}

    // Member function to display server details, including additional attributes
    void afficherServeur() const {
        afficherOutil();
        std::cout << "Stockage: " << stockage << " GB" << std::endl;
    }

    // Getter for the additional server attribute
    int getStockage() const {
        return stockage;
    }


};


class Routeur : public OutilInformatique {
private:
    int numero;

public:
    Routeur(const std::string& reference, const std::string& modele, int quantite, int numero)
        : OutilInformatique("Routeur", reference, modele, quantite), numero(numero) {}

    // Member function to display router details, including additional attributes
    void afficherRouteur() const {
        afficherOutil();
        std::cout << "Numero: " << numero << std::endl;
    }

    // Getter for the additional router attribute
    int getNumero() const {
        return numero;
    }


};

class Imprimante : public OutilInformatique {
private:
    std::string taille;

public:
    Imprimante(const std::string& reference, const std::string& modele, int quantite, const std::string& taille)
        : OutilInformatique("Imprimante", reference, modele, quantite), taille(taille) {}

    // Member function to display printer details, including additional attributes
    void afficherImprimante() const {
        afficherOutil();
        std::cout << "Taille: " << taille << std::endl;
    }

    // Getter for the additional printer attribute
    const std::string& getTaille() const {
        return taille;
    }


};

class Cable : public OutilInformatique {

private:
    float longueur;
    float diametre;

public:
    Cable(const std::string& reference, const std::string& modele, int quantite, float longueur, float diametre)
        : OutilInformatique("Cable", reference, modele, quantite), longueur(longueur), diametre(diametre) {}

    // Member function to display cable details, including additional attributes
    void afficherCable() const {
        afficherOutil();
        std::cout << "Longueur: " << longueur << " meters, Diametre: " << diametre << " mm" << std::endl;
    }

    // Getters for the additional cable attributes
    float getLongueur() const {
        return longueur;
    }

    float getDiametre() const {
        return diametre;
    }


};

class Tablette : public OutilInformatique {

private:
    int size;

public:
    Tablette(const std::string& reference, const std::string& modele, int quantite, int size)
        : OutilInformatique("Tablette", reference, modele, quantite), size(size) {}

    // Member function to display tablet details, including additional attributes
    void afficherTablette() const {
        afficherOutil();
        std::cout << "Taille: " << size << " inches" << std::endl;
    }

    // Getter for the additional tablet attribute
    int getSize() const {
        return size;
    }


};

class Ordinateur : public OutilInformatique {

private:
    std::string processeur;
    int ram;

public:
    Ordinateur(const std::string& reference, const std::string& modele, int quantite, const std::string& processeur, int ram)
        : OutilInformatique("Ordinateur", reference, modele, quantite), processeur(processeur), ram(ram) {}

    // Member function to display computer details, including additional attributes
    void afficherOrdinateur() const {
        afficherOutil();
        std::cout << "Processeur: " << processeur << ", RAM: " << ram << " GB" << std::endl;
    }

    // Getters for the additional computer attributes
    const std::string& getProcesseur() const {
        return processeur;
    }

    int getRam() const {
        return ram;
    }


};

class Societe {
private:
    std::vector<OutilInformatique*> tab;
    std::vector<Fournisseur> fournisseurs;
    std::vector<Utilisateur> utilisateurs;

public:
    // Constructor
    Societe() {}

    // Function to add an OutilInformatique to the vector
    void ajouterOutil(OutilInformatique* outil) {
        tab.push_back(outil);
    }


    // Method to display all utilisateurs
    void afficherUtilisateurs() const {
        for (const auto& utilisateur : utilisateurs) {
            std::cout << "ID Utilisateur: " << utilisateur.getId() << ", Nom: " << utilisateur.getNom() << std::endl;
        }
    }
};


 // Method to display all fournisseurs
    void afficherFournisseurs() const {
        for (const auto& fournisseur : fournisseurs) {
            std::cout << "ID Fournisseur: " << fournisseur.getId() << ", Nom: " << fournisseur.getNom() << std::endl;
        }
    }

    // Function to display the tools in the vector
    void afficher() {
        for (const auto& outil : tab) {
            outil->afficherOutil();
        }
    }
};

class Fournisseur {
private:
    int id_fournisseur;
    int numero_fournisseur;

public:
    Fournisseur(int id, int numero) : id_fournisseur(id), numero_fournisseur(numero) {}

    // Member function to display the details of the supplier
    void afficherFournisseur() const {
        std::cout << "ID Fournisseur: " << id_fournisseur << ", Numero Fournisseur: " << numero_fournisseur << std::endl;
    }

    // Getters for individual attributes
    int getIdFournisseur() const {
        return id_fournisseur;
    }

    int getNumeroFournisseur() const {
        return numero_fournisseur;
    }

    // Static functions to manage suppliers
    static void ajouterFournisseur(Fournisseur fournisseur, std::vector<Fournisseur>& fournisseurs) {
        fournisseurs.push_back(fournisseur);
    }

    static void supprimerFournisseur(int fournisseurId, std::vector<Fournisseur>& fournisseurs) {
        for (auto it = fournisseurs.begin(); it != fournisseurs.end(); ++it) {
            if (it->getIdFournisseur() == fournisseurId) {
                fournisseurs.erase(it);
                break;
            }
        }
    }

    static Fournisseur* rechercherFournisseur(int fournisseurId, const std::vector<Fournisseur>& fournisseurs) {
        for (const auto& fournisseur : fournisseurs) {
            if (fournisseur.getIdFournisseur() == fournisseurId) {
                return const_cast<Fournisseur*>(&fournisseur);
            }
        }
        return nullptr; // Supplier not found
    }

    static void afficherFournisseurs(const std::vector<Fournisseur>& fournisseurs) {
        for (const auto& fournisseur : fournisseurs) {
            fournisseur.afficherFournisseur();
        }
    }
};

class ReparateurMaintenance {
private:
    std::string nom;
    std::vector<OutilInformatique> a_reparer;

public:
    ReparateurMaintenance(const std::string& nom) : nom(nom) {}

    // Member function to set the state of a tool


    // Add a tool to the 'a_reparer' vector
    void ajouterAReparer(const OutilInformatique& outil) {
        a_reparer.push_back(outil);
    }

    // Display the tools that need maintenance
    void afficherAReparer() const {
        std::cout << "Tools to be repaired by " << nom << ":" << std::endl;
        for (const OutilInformatique& outil : a_reparer) {
            outil.afficherOutil();
        }
    }

    // Getter for the name of the maintenance technician
    std::string getNom() const {
        return nom;
    }
};


int main() {
    

    return 0;
}
