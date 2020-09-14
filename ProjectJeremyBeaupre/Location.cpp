// But: Calculer le montant qu'un individu devra débourser pour faire un voyage dans une automobile louée
// L'algorithme devra tenir compte du kilométrage parcouru et de la durée du voyage qui sont sousmises par le requérant.
// Les différentes sources de dépenses sont :
// - coût de la location de 45$ par jour et comprend 250Km gratuit par jour.
// - La consommation du vihécule est de 7.6 litres aux 100Km.
// - 1 litre d'essence coûte 1.25$.
// - 0.05$ du kilomètre est exigé pour chaque kilomètre supplémentaire
// Auteur: Jérémy Beaupré
// Date: 14 septembre 2020

// Appelle des bibliotèque
#include <iostream>

using namespace std;

int main() //ouverture du main
{
	setlocale(LC_ALL, ""); // pour corrigé les problème d'accents 

	//Pour facilité le programme on va créer une constantes pour :
	//- Le prix de l'essence 
	//- la consommation de l'essence par le véhicule
	//- le plus 0.05$/km.
	//- Le prix de bases, soit 45$ par jour avec -250km au compteur 
	//ces dernières ne changeront pas particulièrement leur valeur donc le mieux c'est de les mettres dans un constante
	
	//Déclaration des constantes
	const float PRIX_ESSENCE = 1.25; // 1.25$ / litre
	const float PRIX_BASE = 45.00; // 45$ / jour
	const float DEDUCTION_KM = 250.00; // -250km / jour
	// Pour la consommation d'essence par le véhicule ont va changer un peux les valeur pour éviter les calcules inutiles
	// Pour commencer ont va réduit la consommation pour savoir combien de km fait le véhicule pour 1 litre
	// Pour ça ont fait ce calcule : 100 / 7.6 qui nous donne 13.157894 qu'on va arrondir à 13.16km/ 1 litres
	const float KM_PAR_LITRE = 13.16; // pour la consommation de 1 litre
	const float AJOUT_KM_SUPPL = 0.05; // + 0.05$ / km

	/*pour la déclaration des variables il va nous falloir au moins des variables pour :
	- Le cout de la dépenses
	- Le nombre de litres dépenser
	- Le nombre de kilomètre parcouru
	- Le nombre de jours de location
	- Les kilomètre supplémentaire
	*/
	//Déclaration des variables
	int jourDeLocation; // Nb total de jour de location
	float kilometrage; // Nb total de kilomètre
	float kiloSuppl; //pour les kilomètre supplémentaire
	float coutTotal;
	float essenceDepensee; // Essence totale dépensée durant la location

	// ont commence par salué l'utilisateur
	cout << "Bonjour à vous utilisateur." << endl << "Je vais calculer pour vous le coût total de votre locations." << endl << "Veuillez simplement à répondre à chaque question." << endl << endl;
	//Ensuite on demande à l'utilisateur le nombre de jour de location du véhicule
	cout << "Combien de jours à durée la location ?" << endl;
	cout << "-> ";
	cin >> jourDeLocation;

	// on vérifie juste que le chiffre n'est pas négatif à l'aide d'une boucle 
	while (jourDeLocation < 0) //Si le chiffre est négatif
	{
		cout << "Désolé, mais le nombre de jours ne peut pas être négatif." << endl << "Veuillez recommencer -> ";
		cin >> jourDeLocation;
	}

	//ensuite on demande combien de combien de kilomètres elle a parcouru durant sa location
	cout << "combien de kilomètre avez vous parcouru durant votre location (préciser à deux chiffre après la virgule, si possible)" << endl << "-> ";
	cin >> kilometrage;

	//encore on vérifier que le kilométrage n'est pas négatif avec un while
	while (kilometrage < 0)
	{
		cout << "Désolé, mais le kilométrage ne peut pas être négatif." << endl << "Veuillez recommencer -> ";
		cin >> kilometrage;
	}

    // À l'aide des deux information regroupé on peux faire tout les calcule qu'on a besoin
	// tout d'abord on calcule le plus facile, le cout de base 
	// on utilise la variable coutTotal pour ajouter le cout de base 
	coutTotal = jourDeLocation * PRIX_BASE; //soit 45$/jour

	//ensuite on calcul l'essence dépensé
	essenceDepensee = kilometrage / KM_PAR_LITRE; //pour obtenir le nombre de litre dépensé par kilomètre

	//ensuite on ajoute au cout total le cout de l'essence 
	coutTotal = coutTotal + (essenceDepensee * PRIX_ESSENCE);

	//Maintenant ont calcule le coût des kilomètres supplémentaire
	kiloSuppl = kilometrage - (jourDeLocation * DEDUCTION_KM);
	//Si j'aimais l'utilisateur à fait moins de kilomètres par jour que les 250km gratuit (ce qui est très possible) cela voudra dire que le nombre sera négatif. Si c'est le cas alors ont mettra le nombre de kilomètre supplémentaire à 0
	if (kiloSuppl < 0) // si les kilomètre supplémentaire sont négatif.
	{
		kiloSuppl = 0; //on met les kilomètre supplémentaire à 0.
	}
	//ensuite on calcule le cout des kilomètre supplémentaire
	coutTotal = coutTotal + (kiloSuppl * AJOUT_KM_SUPPL);

	// maintenant on indique les renseignement à l'utilisateur surtout le prix
	cout << "Votre coût total est de " << coutTotal << "$." << endl << endl;
	cout << "Coût de base pour le(s) " << jourDeLocation << " jour(s) de location : " << jourDeLocation * PRIX_BASE << "$." << endl;
	cout << "Coût de l'essence dépensée (soit " << kilometrage / KM_PAR_LITRE << " litres) : " << essenceDepensee * PRIX_ESSENCE << "$." << endl;
	cout << "Coût des kilomètres supplémentaire : ";
	if (kiloSuppl == 0)
	{
		cout << "Il n'y a pas de coût puisque qu'il n'y a pas de kilomètre supplémentaire." << endl;
	}
	else
	{
		cout << kiloSuppl * AJOUT_KM_SUPPL << "$ (pour " << kiloSuppl << " kilomètres supplémentaire)." << endl;
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