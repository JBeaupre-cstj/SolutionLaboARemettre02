// But: Calculer le montant qu'un individu devra d�bourser pour faire un voyage dans une automobile lou�e
// L'algorithme devra tenir compte du kilom�trage parcouru et de la dur�e du voyage qui sont sousmises par le requ�rant.
// Les diff�rentes sources de d�penses sont :
// - co�t de la location de 45$ par jour et comprend 250Km gratuit par jour.
// - La consommation du vih�cule est de 7.6 litres aux 100Km.
// - 1 litre d'essence co�te 1.25$.
// - 0.05$ du kilom�tre est exig� pour chaque kilom�tre suppl�mentaire
// Auteur: J�r�my Beaupr�
// Date: 14 septembre 2020

// Appelle des bibliot�que
#include <iostream>

using namespace std;

int main() //ouverture du main
{
	setlocale(LC_ALL, ""); // pour corrig� les probl�me d'accents 

	//Pour facilit� le programme on va cr�er une constantes pour :
	//- Le prix de l'essence 
	//- la consommation de l'essence par le v�hicule
	//- le plus 0.05$/km.
	//- Le prix de bases, soit 45$ par jour avec -250km au compteur 
	//ces derni�res ne changeront pas particuli�rement leur valeur donc le mieux c'est de les mettres dans un constante
	
	//D�claration des constantes
	const float PRIX_ESSENCE = 1.25; // 1.25$ / litre
	const float PRIX_BASE = 45.00; // 45$ / jour
	const float DEDUCTION_KM = 250.00; // -250km / jour
	// Pour la consommation d'essence par le v�hicule ont va changer un peux les valeur pour �viter les calcules inutiles
	// Pour commencer ont va r�duit la consommation pour savoir combien de km fait le v�hicule pour 1 litre
	// Pour �a ont fait ce calcule : 100 / 7.6 qui nous donne 13.157894 qu'on va arrondir � 13.16km/ 1 litres
	const float KM_PAR_LITRE = 13.16; // pour la consommation de 1 litre
	const float AJOUT_KM_SUPPL = 0.05; // + 0.05$ / km

	/*pour la d�claration des variables il va nous falloir au moins des variables pour :
	- Le cout de la d�penses
	- Le nombre de litres d�penser
	- Le nombre de kilom�tre parcouru
	- Le nombre de jours de location
	- Les kilom�tre suppl�mentaire
	*/
	//D�claration des variables
	int jourDeLocation; // Nb total de jour de location
	float kilometrage; // Nb total de kilom�tre
	float kiloSuppl; //pour les kilom�tre suppl�mentaire
	float coutTotal;
	float essenceDepensee; // Essence totale d�pens�e durant la location

	// ont commence par salu� l'utilisateur
	cout << "Bonjour � vous utilisateur." << endl << "Je vais calculer pour vous le co�t total de votre locations." << endl << "Veuillez simplement � r�pondre � chaque question." << endl << endl;
	//Ensuite on demande � l'utilisateur le nombre de jour de location du v�hicule
	cout << "Combien de jours � dur�e la location ?" << endl;
	cout << "-> ";
	cin >> jourDeLocation;

	// on v�rifie juste que le chiffre n'est pas n�gatif � l'aide d'une boucle 
	while (jourDeLocation < 0) //Si le chiffre est n�gatif
	{
		cout << "D�sol�, mais le nombre de jours ne peut pas �tre n�gatif." << endl << "Veuillez recommencer -> ";
		cin >> jourDeLocation;
	}

	//ensuite on demande combien de combien de kilom�tres elle a parcouru durant sa location
	cout << "combien de kilom�tre avez vous parcouru durant votre location (pr�ciser � deux chiffre apr�s la virgule, si possible)" << endl << "-> ";
	cin >> kilometrage;

	//encore on v�rifier que le kilom�trage n'est pas n�gatif avec un while
	while (kilometrage < 0)
	{
		cout << "D�sol�, mais le kilom�trage ne peut pas �tre n�gatif." << endl << "Veuillez recommencer -> ";
		cin >> kilometrage;
	}

    // � l'aide des deux information regroup� on peux faire tout les calcule qu'on a besoin
	// tout d'abord on calcule le plus facile, le cout de base 
	// on utilise la variable coutTotal pour ajouter le cout de base 
	coutTotal = jourDeLocation * PRIX_BASE; //soit 45$/jour

	//ensuite on calcul l'essence d�pens�
	essenceDepensee = kilometrage / KM_PAR_LITRE; //pour obtenir le nombre de litre d�pens� par kilom�tre

	//ensuite on ajoute au cout total le cout de l'essence 
	coutTotal = coutTotal + (essenceDepensee * PRIX_ESSENCE);

	//Maintenant ont calcule le co�t des kilom�tres suppl�mentaire
	kiloSuppl = kilometrage - (jourDeLocation * DEDUCTION_KM);
	//Si j'aimais l'utilisateur � fait moins de kilom�tres par jour que les 250km gratuit (ce qui est tr�s possible) cela voudra dire que le nombre sera n�gatif. Si c'est le cas alors ont mettra le nombre de kilom�tre suppl�mentaire � 0
	if (kiloSuppl < 0) // si les kilom�tre suppl�mentaire sont n�gatif.
	{
		kiloSuppl = 0; //on met les kilom�tre suppl�mentaire � 0.
	}
	//ensuite on calcule le cout des kilom�tre suppl�mentaire
	coutTotal = coutTotal + (kiloSuppl * AJOUT_KM_SUPPL);

	// maintenant on indique les renseignement � l'utilisateur surtout le prix
	cout << "Votre co�t total est de " << coutTotal << "$." << endl << endl;
	cout << "Co�t de base pour le(s) " << jourDeLocation << " jour(s) de location : " << jourDeLocation * PRIX_BASE << "$." << endl;
	cout << "Co�t de l'essence d�pens�e (soit " << kilometrage / KM_PAR_LITRE << " litres) : " << essenceDepensee * PRIX_ESSENCE << "$." << endl;
	cout << "Co�t des kilom�tres suppl�mentaire : ";
	if (kiloSuppl == 0)
	{
		cout << "Il n'y a pas de co�t puisque qu'il n'y a pas de kilom�tre suppl�mentaire." << endl;
	}
	else
	{
		cout << kiloSuppl * AJOUT_KM_SUPPL << "$ (pour " << kiloSuppl << " kilom�tres suppl�mentaire)." << endl;
	}

	return 0;
}

/* PLAN DE TEST
test 1 :
jour = 15
kilo = 8900
cout total = 1777.86$

test 2 : 
jour = 5
kilo = 1250
cout total = 343.73$

test 3 :
jour = -5 
erreur*
jour = 10

kilo -360
erreur*
kilo = 1863
cout total = 626.96$ 


*/