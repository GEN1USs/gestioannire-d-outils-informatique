Computer Tool Manager (Gestionnaire d'Outils Informatique)
Project Overview
The Computer Tool Manager, or "Gestionnaire d'Outils Informatique," is a software project designed to manage various types of computer tools and devices used within an organization or company. This system allows users to keep track of tools such as servers, routers, printers, cables, tablets, and computers, including their details and quantities.

The project aims to provide a comprehensive tool management solution for organizations, enabling them to:

Maintain a record of all computer tools and equipment.
Easily add new tools to the inventory.
Update and modify the information associated with each tool.
Remove tools from the inventory when they are no longer in use.
Search for specific tools based on their attributes.
Display a list of all available tools in the inventory.
Project Components
The project consists of the following major components:

Utilisateur (User) Class: This class represents the basic user entity and includes attributes like user ID and name. It also provides functionality to add, delete, search for, and display users. Additionally, the Utilisateur class serves as the parent class for the Administrateur class.

Administrateur (Administrator) Class: A child class of Utilisateur, the Administrateur class introduces an additional attribute, "role." It inherits the basic functionality of the Utilisateur class and can manage user data with an added role.

OutilInformatique (Computer Tool) Class: This class serves as the base class for all computer tools and devices. It includes common attributes like tool type, reference, model, and quantity. The class also provides a method to display the details of each tool.

Serveur (Server) Class: A child class of OutilInformatique, it adds a "stockage" (storage) attribute and specific methods for servers.

Routeur (Router) Class: A child class of OutilInformatique, it introduces a "numero" (number) attribute and specific methods for routers.

Imprimante (Printer) Class: A child class of OutilInformatique, it includes a "taille" (size) attribute and specific methods for printers.

Cable (Cable) Class: A child class of OutilInformatique, it introduces "longueur" (length) and "diametre" (diameter) attributes and specific methods for cables.

Tablette (Tablet) Class: A child class of OutilInformatique, it includes a "size" attribute and specific methods for tablets.

Ordinateur (Computer) Class: A child class of OutilInformatique, it adds "processeur" (processor) and "ram" attributes and specific methods for computers.

Societe (Company) Class: This class manages a vector of computer tools and provides a method, "afficher," to display the details of all tools in the inventory.

How to Use
To use the Computer Tool Manager, follow these steps:

Create instances of different types of tools using the respective classes (e.g., Serveur, Routeur, etc.).
Add these tools to the Societe class using the ajouterOutil() function.
Use the afficher() function in the Societe class to display the tools in the inventory.
Contributors
[Firas Farhani]
[Jesser ben nasr ,Khaled henchir ,Chaima beya benzarti]
