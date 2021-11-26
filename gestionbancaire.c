#include <stdio.h>
#include <string.h>



typedef struct dataClient 
{
    char nom[20];
    char prenom[20];
    char cin[10];
    float montant;

}dataClient;


dataClient Ctab[] =
{
		{"sami","berkia","AA1414",7000},
		{"nizar","berkia","BB1515",8090},
		{"ahmad","salim","CC1616",35700},
		{"salwa","houda","DD1717",500},
		{"nadia","hawdi","EE1818",1100},
		{"nassim","ousama","FF1919",10300},
		{"ahlam","zaimi","GG1100",4900},
		{"jalil","sabiry","EE1101",107600},
		
};

void AffichageDesComptes(int longeur)
{  
	int i ;
	
	for(i = 0 ; i < longeur ; i++)

		{
			printf(" %s       \t%s             \t%s       \t%.2f DH\n" , Ctab[i].nom , Ctab[i].prenom 
			, Ctab[i].cin , Ctab[i].montant );
		}
}


//==========================================================================================================
int main()
{

	int longeur = (sizeof(Ctab))/(sizeof(Ctab[0]));
	int choix , c , i ,choix_1 ;// le choix, numero de utilisateur, nombre de comptes pour creer
	char RtrMenu;
	char entered_Cin[8];
	
	debut:
	printf("==========================HSBC BANK==========================\n\n\n");
	printf("\t\t1. Introduire Un Seul Compte .\n\n\n");
	printf("\t\t----------------------------------\n");
	printf("\t\t2. Introduire Plusieur Comptes .\n\n\n");
	printf("\t\t----------------------------------\n");
	printf("\t\t3. Operations .\n\n\n");
	printf("\t\t----------------------------------\n");
	printf("\t\t4. Affichage des Comptes.\n\n\n");
	printf("\t\t----------------------------------\n");
	printf("\t\t0. Quitter .\n\n\n");		
	printf("=========================================================\n");		

		do{
			printf("Choisez Votre Choix :");
			scanf("%d" , &choix);
			
			system("cls");
			break;
			
		}while(choix != 0);
		
		switch(choix)
			{
			case 1 :{
				printf("\n\n\n===================Creation du Compte===================\n\n\n");
				
					printf("Votre Nom :");
					scanf("%s" , Ctab[longeur].nom);
					printf("Votre Prenom :");
					scanf("%s" , Ctab[longeur].prenom);
					printf("Votre Cin :");
					scanf("%s" , Ctab[longeur].cin);
					printf("\n\n");
				    printf("Votre Compte A Ete Cree Avec Succes ! \n");
				    
				    ++longeur;
				
	 // ******************RETOUR AU MENU******************							
						printf("\nAll Done :)");
				 		rtrmenu:  //checkpoint
						printf("\nRetour au Menu ( y ) :");
						scanf("%s" , &RtrMenu);
							if(RtrMenu =='y')
							{
							  system("cls");
							  goto debut;
							}
							else{
							  goto rtrmenu;
							}
	 // ****************FIN RETOUR AU MENU*****************
				break;
			}
			case 2:{
			     
					checkpoint2 :
				 	
			   		printf("\n\n\n===================Creation Plusieur Comptes===================\n\n\n");
    				printf("Combien du Comptes Voulez-vous creer (MAX = 3) ?\n");
    				scanf("%d" , &c);
    				if(c > 0 && c <= 3 )
					{
	    				for(i = 1 ; i <= c ; i++)
					{  
						printf("Entrer Les info du Compte No: %d \n", i);
						printf("========================================\n");
						printf("Votre Nom :");
						scanf("%s" , Ctab[longeur].nom);
						printf("Votre Prenom :");
						scanf("%s" , Ctab[longeur].prenom);
						printf("Votre Cin :");
						scanf("%s" , Ctab[longeur].cin);
						printf("========================================\n");
						printf("\n\n");
						++longeur ;
						if(i == c)
						{
						    break;
						}
				
					}
					}
				 	else
					 {
						
				 		goto checkpoint2;
				 	 }
					
				    printf("Vos comptes ont ete crees :) \n");
	 // ******************RETOUR AU MENU******************
					printf("\n");							
						printf("\nBravo:)");
				 		rtrmenu1:  //checkpoint
						printf("\nRetour au Menu ( y ) :");
						scanf("%s" , &RtrMenu);
							if(RtrMenu =='y')
							{
								system("cls");
								goto debut;
							}
							else{
								goto rtrmenu1;
							}
	 // ******************FIN RETOUR AU MENU*****************
			}
					
			case 3:
				{
				printf("\n\n\n===================Afficher Toute Les Comptes===================\n\n\n");
				
				AffichageDesComptes(longeur);
				
				printf("\n\n");
				
					printf("Rechercher Votre Compte .\n\n");
					printf("Entrer Votre CIN :");
					scanf("%s" , entered_Cin);
					
					printf("En Cours ... \n");
					
				for(i = 0; i<longeur ;i++){
                if(strcmp(Ctab[i].cin,entered_Cin) == 0){
                 
                 printf("==============================================\n");
                 printf("%s || %s || %s || %0.2f DH\n",Ctab[i].nom,Ctab[i].prenom,
				 Ctab[i].cin,Ctab[i].montant);
				 printf("==============================================\n\n");
				 printf("Confirmer Votre Choix Du Compte  (y/n) : ");
				 scanf("%s",&choix_1);
				 if(choix_1 == 'y'){
				 int n;
				 printf("============================================ \n");				 
				 printf("1 :> Deposer \n");
				 printf("2 :> Retirer \n");
				 printf("============================================ \n\n");
				 printf("Choisissez Votre Operation :>");	 
				 scanf("%d",&n);
				 if(n == 1){
					float depot;
					depot_checkpoint :
		            printf("Entrer Le Montant Que Vous Voulez  Deposer :");
		            scanf("%f",&depot);
		            if( depot < 0){
		             	printf("Montant Non Valid:/ \n");
		             		goto depot_checkpoint;
					}else{					
		            Ctab[i].montant = Ctab[i].montant + depot;
		            printf("%s || %s || %s || %0.2f DH\n\n",Ctab[i].nom,Ctab[i].prenom,
				    Ctab[i].cin,Ctab[i].montant);
				     }   
				    break;
					}	
					
					else if(n==2){
						float retrait;
						insufisant_checkpoint:
		             	printf("Entrer Le Montant Que Vous Voulez Retirer :>");
		             	scanf("%f",&retrait);
		             	if(retrait < 100 || retrait < 0){
		             	printf("Montant Non Valid:/ \n");
		             		goto insufisant_checkpoint;
					}else if(retrait > Ctab[i].montant){
					 	printf("Sold Insufisant :/ \n");
					 	
					 		goto insufisant_checkpoint;
					 }
					 else{
					 	printf("==========================================\n") ;
		                Ctab[i].montant = Ctab[i].montant - retrait;
		                printf("==============Votre Noveau Solde============== \n");
		                 printf("%s || %s || %s || %0.2f DH\n",Ctab[i].nom,Ctab[i].prenom,
				        Ctab[i].cin,Ctab[i].montant);
				        printf("==========================================\n\n") ;				        
				        break;
					}
				}
			}	 		
		} 
    } 
									
						
	 // ******************RETOUR AU MENU******************
						printf("\nAll Done :)");
				 		rtrmenu2:  //checkpoint
						printf("\nRetour au Menu ( y ) :");
						scanf("%s" , &RtrMenu);
							if(RtrMenu =='y' || RtrMenu =='Y')
							{
								system("cls");
								goto debut;
							}
							else{
								goto rtrmenu2;
							}
	 // ******************FIN RETOUR AU MENU******************
						
				}
				case 4:
				{
					 AffichageDesComptes(longeur);
					
	 // ******************RETOUR AU MENU******************
						printf("\nAll Done :)");
				 		rtrmenu3:  //checkpoint
						printf("\nRetour au Menu ( y ) :");
						scanf("%s" , &RtrMenu);
							if(RtrMenu =='y' || RtrMenu =='Y')
							{
								system("cls");
								goto debut;
							}
							else{
								goto rtrmenu3;
							}
	 // *****************FIN RETOUR AU MENU*****************
							}			
		} 

    return 0;
    
}


