#include<stdio.h>
#include<stdlib.h>

int	main()
{
	int choix;
	char prenom[20],nom[20];
	char cin[20];
	printf("======Lehma_Brothers_Bank======\n");
	printf("\n1.Introduire Un Compte Bancaire.\n");
	printf("\n2.Introduire Plusieurs Comptes Bancaires.\n");
	printf("\n3.Operations.\n");
	printf("\n4.Affichage.\n");
	printf("\n5.Fidelisation.\n");
	printf("\n6.Quitter.\n");	
	printf("\n==============================\n");
	printf("\n\n");
	printf("Taper Le Numero Du Service Qui Vous Convient :");
	scanf("%d",&choix);

	switch(choix)
	{
		case 1:printf("Entrer Votre Prenom:\n");
		       scanf("%s",prenom);
		       
		       printf("Entrer Votre Nom:\n");
		       scanf("%s",nom);
		       
		       printf("Entrer Votre CIN:\n");
		       scanf("%s",cin);
		       break;
	}	
	return 0;
}	
