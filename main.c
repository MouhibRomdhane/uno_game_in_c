#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
//procedure de traduit les entiers au chaines
char *part1(int x)
{
    switch (x)
    {
    case 13:
        return "jok";
        break;
    case 14:
        return "+ 4";
        break;
    case 12:
        return "blk" ;
        break;
    case 10:
        return "rev";
        break;
    case 11:
        return "+ 2";
        break;
    case 0:
        return "00 ";
        break;
    case 1:
        return "01 ";
        break;
    case 2:
        return "02 " ;
        break;
    case 3:
        return "03 ";
        break;
    case 4:
        return "04 ";
        break;
    case 5:
        return "05 ";
        break;
    case 6:
        return "06 ";
        break;
    case 7:
        return "07 " ;
        break;
    case 8:
        return "08 ";
        break;
    case 9:
        return "09 ";
        break;
    }

}
char *part2(int x)
{
    char *res;
    switch (x)
    {
    case 0:
        return "red";
        break;
    case 1:
        return "gre";
        break;
    case 2:
        return "yal" ;
        break;
    case 3:
        return "blu";
        break;

    default:

        return "# #";
    }

}
void affmain(int m1,int m2,int c,int c1,int k)
{
    int i;
    char l1[300];
    char l2[300];
    char l3[300];
    char l4[300];
    char l5[300];
    char num[4];
    if (c==0)
    {
        strcpy(l1,"");
        strcpy(l2,"");
        strcpy(l3,"");
        strcpy(l4,"");
        strcpy(l5,"");
    }
    strcat(l1,"*---* ");
    strcat(l2,"|");
    strcat(l2,part1(m1));
    strcat(l2,"| ");
    strcat(l3,"|");
    strcat(l3,part2(m2));
    strcat(l3,"| ");
    strcat(l4,"*---* ");
    strcat(l5," (");
    itoa(c+1,num,10);
    strcat(l5,num);
    strcat(l5,")  ");

    if(c==c1-1)
    {
        printf("%s\n",l1);
        printf("%s\n",l2);
        printf("%s\n",l3);
        printf("%s\n",l4);
        if(k==1)
            printf("%s\n",l5);
    }

}
int valcarte(int n )
{
    int res;
    switch(n)
    {
    case 13 ... 14:
        res=50;
        break;
    case 10 ... 12:
        res=20;
        break;
    default :
        res=n;

    }
    return res;
}
void main()
{
    int choix;

    int corbeille[4][27];
    int menup;
    //nom du joueurs
    char nom1[10];
    char nom2[10];
    //nombre de tour
    int nbtour;
    //pour partager le temps du jeux
    int cond,cond2;
    //compteur de nobre de carte pour chaque couleur
    int rg,vr,bl,jo;
    //por verification du temps
    time_t begin,end;
    //uno
    char uno;
    //choix de jeux
    int choixcol,choixjeux,choixcart;
    //controle de ligne
    int clj,cl4;
    //verification sur la main
    int verif;
    //matrice des mains
    int main1[40][2];
    int main2[40][2];
    //des compteur
    int i,j,l,c;
    //matrice carte sur table
    int ctable[1][2];
    //compteur du nombre carte dans chaque main
    int ncm1,ncm2;
//calcule de scor
    int somm1=0;
    int somm2=0;
//remplir main du machine
    srand(time(NULL));
    //variable pour diviser le rolle du jouer
    int roll;
    //menu


    do
    {
        system("cls");

        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||                          BIENVENUE AU JEUX UNO                                  ||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("\n");
        printf("\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||                       Veuillez Choisir Une Option                               ||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||                        1-Jouer Contre La Machine                                ||\n");
        printf("||                        2-Jouer A Deux                                           ||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||                              3-Quitter                                          ||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||                              !!NOTEZ BIEN!!!                                    ||\n");
        printf("|| yal=jaune |red=rouge | gre=vert | blu=bleu | jok=joker | rev=Inversement de sens||\n");
        printf("||                             blk=passe ton tour                                  ||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("||---------------------------------------------------------------------------------||\n");
        printf("entrer votre choix=");
        scanf("%i",&choix);
        while (choix<1||choix>3)
        {
            printf("choix introuvable,rentre votre choix=");
            scanf("%i",&choix);
        }
        if (choix==2)
        {
            printf("entrer le nom du joueur 1=");
            fflush(stdin);
            fgets(nom1,10,stdin);
            printf("entrer le nom du joueur 2=");
            fflush(stdin);
            fgets(nom2,10,stdin);
        }
        if (choix==3)
        {
            system("cls");
            printf("                         ###   #   #  ####      ###   #   #  ####\n");
            printf("                         #  #   # #   #         #  #   # #   #   \n");
            printf("                         ###     #    ###       ###     #    ### \n");
            printf("                         #  #    #    #         #  #    #    #   \n");
            printf("                         ###     #    ####      ###     #    ####\n");
            Sleep(3000);
            system("cls");
            exit(0);
        }

        do
        {
            nbtour=0;

            somm1=0;
            somm2=0;

            do
            {
                int carte[4][27]= {{0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,14},
                    {0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,14},
                    {0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,14},
                    {0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,14},
                };

                nbtour++;
//remplire de corbeille par -1;
                for (i=0; i<4; i++)
                {
                    for (j=0; j<27; j++)
                    {
                        corbeille[i][j]=-1;
                    }
                }
//main de machine ou joueur 2
                i=0;
                do
                {
                    i++;
                    do
                    {
                        l=rand()%4;
                        c=rand()%27;
                    }
                    while(carte[l][c]==-1);

                    if (carte[l][c]>12)
                    {
                        main1[i-1][0]=carte[l][c];
                        main1[i-1][1]=4;
                    }
                    else
                    {
                        main1[i-1][0]=carte[l][c];
                        main1[i-1][1]=l;
                    }

                    carte[l][c]=-1;
                }
                while (i!=7);
                //main du joueur 1
                i=0;
                do
                {
                    i++;
                    do
                    {
                        l=rand()%4;
                        c=rand()%27;
                    }
                    while(carte[l][c]==-1);

                    if (carte[l][c]>12)
                    {
                        main2[i-1][0]=carte[l][c];
                        main2[i-1][1]=4;
                    }
                    else
                    {
                        main2[i-1][0]=carte[l][c];
                        main2[i-1][1]=l;
                    }

                    carte[l][c]=-1;
                }
                while (i!=7);
                ncm1=7,ncm2=7;
                //remplire de premier carte sur table
                do
                {
                    l=rand()%4;
                    c=rand()%27;
                }
                while (carte[l][c]==-1);
                corbeille[l][c]=carte[l][c];

                if(carte[l][c]>12)
                {
                    ctable[0][0]=carte[l][c];
                    ctable[0][1]=4;
                }
                else
                {
                    ctable[0][0]=carte[l][c];
                    ctable[0][1]=l;
                }
                carte[l][c]=-1;
                if (nbtour==1)
                    roll=1;
                else
                    roll=2;
                cond2=1;
                cond=1;
                clj=0;
                cl4=0;
                switch(choix)
                {
                case 1:
                    do
                    {

                        switch (roll)
                        {
                        case 1:
                            system("cls");
                            printf("Tour Numero %i\n",nbtour);
                            printf("la carte sur table=\n");
                            affmain(ctable[0][0],ctable[0][1],0,1,0) ;
                            //+2 carte pour la machine

                            if (ctable[0][0]==11&& cond==1)
                            {
                                for (i=ncm2; i<ncm2+2; i++)
                                {
                                    do
                                    {
                                        l=rand()%4;
                                        c=rand()%27;
                                    }
                                    while (carte[l][c]==-1);
                                    corbeille[l][c]=carte[l][c];

                                    if(carte[l][c]>12)
                                    {
                                        main2[i][0]=carte[l][c];
                                        main2[i][1]=4;
                                    }
                                    else
                                    {
                                        main2[i][0]=carte[l][c];
                                        main2[i][1]=l;
                                    }
                                }
                                ncm2=ncm2+2;
                                roll=1;
                                cond++;
                            }
                            //block et reverse
                            else if ((ctable[0][0]==12 || ctable[0][0]==10)&&(cond==1))
                            {
                                roll=1;
                                cond++;
                            }
                            //choisir le couleur pour le joueur 1 carte +4 et joker
                            else if ((ctable[0][0]==13&&ctable[0][1]==4)||(ctable[0][0]==14&&ctable[0][1]==4))
                            {
                                printf("Votre Main = \n");
                                for (i=0; i<ncm1; i++)
                                {
                                    affmain(main1[i][0],main1[i][1],i,ncm1,1)   ;

                                }
                                //si la carte est +4
                                if (ctable[0][0]==14)
                                {
                                    for (i=ncm2; i<ncm2+4; i++)
                                    {
                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=4;
                                        }
                                        else
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=l;
                                        }
                                    }
                                    ncm2=ncm2+4;
                                }
                                printf("choisir un couleur :rouge(1),vert(2),jaune(3),bleu(4):");
                                scanf("%i",&choixcol);
                                while((choixcol<1 )&&(choixcol>4))
                                {
                                    printf("!!choisir un nombre entre 1,2,3 et 4!!:");
                                    scanf("%i",&choixcol);
                                }
                                if(ctable[0][0]==14)
                                    roll=1;
                                else
                                    roll=2;
                                ctable[0][1]=choixcol-1;
                            }

                            else
                            {
                                //affichage de main
                                printf("Votre Main = \n");
                                for (i=0; i<ncm1; i++)
                                {
                                    affmain(main1[i][0],main1[i][1],i,ncm1,1)   ;

                                }
                                verif=0;
                                i=0;
                                while (i<ncm1 && verif==0)
                                {
                                    if(main1[i][0]==ctable[0][0]||main1[i][1]==ctable[0][1]||main1[i][0]==14||main1[i][0]==13)
                                        verif=1;
                                    i++;
                                }
                                if (verif==1)
                                {
                                    printf("------Tapper 1 pour jeter une carte -------");
                                    printf("------Tapper 2 pour passer le tour  -------:");

                                    scanf("%i",&choixjeux);
                                    while ((choixjeux<1) && (choixjeux>2))
                                    {
                                        printf("!! choisir entre 1 et 2!!:");
                                        scanf("%i",&choixjeux);
                                    }
                                }
                                else
                                {

                                    printf("------Tapper 1 pour passer le tour  -------:");

                                    scanf("%i",&choixjeux);
                                    choixjeux++;
                                    while (choixjeux!=2)
                                    {
                                        printf("!! il faut que choisie 1!!:");
                                        scanf("%i",&choixjeux);
                                        choixjeux++;
                                    }

                                }

                                //condition du choix de jeux

                                if(choixjeux==1)
                                {
                                    printf("choisir le carte en respectant les classes des carte=");
                                    scanf("%i",&choixcart);
                                    while ((choixcart)<1 && (choixcart>ncm1) )
                                    {
                                        printf("!! il faut respecter les classes des carte entre 1 et %i !!:",ncm1);
                                        scanf("%i",&choixcart);
                                    }

                                    do
                                    {
                                        verif=0;
                                        if (main1[choixcart-1][0]<13)
                                        {
                                            if(main1[choixcart-1][0]!=ctable[0][0]&& main1[choixcart-1][1]!=ctable[0][1])
                                                verif=1;
                                        }
                                        else if(main1[choixcart-1][0]==14)
                                        {
                                            i=0;
                                            while (i<ncm1 && verif==0)
                                            {
                                                if(main1[i][0]==ctable[0][0]||main1[i][1]==ctable[0][1])
                                                    verif=1;
                                                i++;
                                            }
                                        }
                                        if (verif==1)
                                        {
                                            printf("!!votre choix inopportune!!\n");
                                            printf("rentre votre choix=");
                                            scanf("%i",&choixcart);

                                        }

                                    }
                                    while (verif==1);
                                    if (main1[choixcart-1][1]!=4)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[main1[choixcart-1][1]][c]!=-1);
                                    }

                                    if(main1[choixcart-1][0]==14)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[cl4][c]!=-1);
                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=4;
                                        corbeille[cl4][c]=ctable[0][0];
                                        cl4++;
                                        roll=1;
                                        cond=1;
                                    }
                                    else if(main1[choixcart-1][0]==13)
                                    {
                                        do
                                        {
                                            c=rand()%27;


                                        }
                                        while (corbeille[clj][c]!=-1);
                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=4;
                                        corbeille[clj][c]=ctable[0][0];
                                        clj++;
                                        roll=1;
                                    }
                                    else if (main1[choixcart-1][0]>9&&main1[choixcart-1][0]<13)
                                    {
                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=main1[choixcart-1][1];
                                        corbeille[main1[choixcart-1][1]][c]=ctable[0][0];
                                        cond=1;
                                        roll=1;
                                    }
                                    else
                                    {


                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=main1[choixcart-1][1];
                                        corbeille[main1[choixcart-1][1]][c]=ctable[0][0];
                                        roll=2;
                                    }

                                    for(i=choixcart-1; i<ncm1-1; i++)
                                    {
                                        main1[i][0]=main1[i+1][0];
                                        main1[i][1]=main1[i+1][1];
                                    }
                                    ncm1=ncm1-1;
                                    //pour voir esque le pioshe est terminer
                                    l=0;
                                    c=0;
                                    verif=0;
                                    while(l<4&& verif==0)
                                    {
                                        while(c<27&&verif==0)
                                        {
                                            if(carte[l][c]!=-1)
                                                verif=1;
                                            c++;
                                        }
                                        l++;
                                    }
                                    //pour remplire les pioche par les carte dans la corbeille
                                    if (verif==0)
                                    {
                                        for(i=0; i<4; i++)
                                        {
                                            for(j=0; j<27; j++)
                                            {
                                                if(corbeille[i][j]!=-1)
                                                {
                                                    l=0;
                                                    c=0;
                                                    while(l<4&& verif==0)
                                                    {
                                                        while(c<27&&verif==0)
                                                        {
                                                            if(carte[l][c]==-1)
                                                            {
                                                                carte[l][c]=corbeille[i][j];
                                                                corbeille[i][j]=-1;
                                                                verif=1;
                                                            }

                                                            c++;
                                                        }
                                                        l++;
                                                    }
                                                }
                                            }
                                        }
                                    }

//l'orsque le joueur dit uno
                                    if(ncm1==1)
                                    {
                                        begin=time(NULL);
                                        printf("=");
                                        scanf("%c",&uno);
                                        end=time(NULL);
                                        while (uno!='u'&& uno!='U')
                                        {
                                            printf("=");
                                            scanf("%c",&uno);
                                            end=time(NULL);
                                        }
                                        if (difftime(end,begin)<3)
                                        {
                                            system("cls");
                                            printf("##     ##    ##    ##     ####### \n");
                                            printf("##     ##    ###   ##    ##     ## \n");
                                            printf("##     ##    ####  ##    ##     ## \n");
                                            printf("##     ##    ## ## ##    ##     ## \n");
                                            printf("##     ##    ##  ####    ##     ## \n");
                                            printf("##     ##    ##   ###    ##     ## \n");
                                            printf(" #######     ##    ##     ####### \n");
                                            Sleep(5000);
                                        }
                                        else
                                        {system("cls");
                                            printf("contre uno +2 cartes\n");
                                            Sleep(5555);
                                            for (i=ncm1; i<ncm1+2; i++)
                                            {


                                                do
                                                {
                                                    l=rand()%4;
                                                    c=rand()%27;
                                                }
                                                while (carte[l][c]==-1);
                                                corbeille[l][c]=carte[l][c];

                                                if(carte[l][c]>12)
                                                {
                                                    main1[i][0]=carte[l][c];
                                                    main1[i][1]=4;
                                                }
                                                else
                                                {
                                                    main1[i][0]=carte[l][c];
                                                    main1[i][1]=l;
                                                }
                                                carte[l][c]=-1;
                                            }
                                            ncm1=ncm1+2;
                                        }

                                    }

                                }

                                else
                                {
                                    for (i=ncm1; i<ncm1+1; i++)
                                    {


                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=4;
                                        }
                                        else
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=l;
                                        }
                                        carte[l][c]=-1;
                                    }
                                    ncm1=ncm1+1;
                                    roll=2;
                                }

                            }
                            break;
                        case 2:
                            system("cls");
                            printf("Tour Numero %i\n",nbtour);
                            printf("la carte sur table=\n");
                            affmain(ctable[0][0],ctable[0][1],0,1,0) ;
                            Sleep(5555);
                            //+2 carte pour le joueur

                            if (ctable[0][0]==11&&cond2==1)
                            {
                                for (i=ncm1; i<ncm1+2; i++)
                                {
                                    do
                                    {
                                        l=rand()%4;
                                        c=rand()%27;
                                    }
                                    while (carte[l][c]==-1);
                                    corbeille[l][c]=carte[l][c];

                                    if(carte[l][c]>12)
                                    {
                                        main1[i][0]=carte[l][c];
                                        main1[i][1]=4;
                                    }
                                    else
                                    {
                                        main1[i][0]=carte[l][c];
                                        main1[i][1]=l;
                                    }
                                }
                                ncm1=ncm1+2;
                                roll=2;
                                cond2++;
                            }
                            //block et reverse
                            else if ((ctable[0][0]==12 || ctable[0][0]==10)&&cond2==1)
                            {
                                roll=2;
                                cond2++;
                            }
                            //choisir le couleur pour le joueur 1 carte +4 et joker
                            else if ((ctable[0][0]==13&&ctable[0][1]==4)||(ctable[0][0]==14&&ctable[0][1]==4))
                            {
                                //si la carte est +4
                                if (ctable[0][0]==14)
                                {
                                    for (i=ncm1; i<ncm1+4; i++)
                                    {
                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=4;
                                        }
                                        else
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=l;
                                        }
                                    }
                                    ncm1=ncm1+4;
                                }
                                rg=0;
                                vr=0;
                                bl=0;
                                jo=0;
                                for (i=0; i<ncm2; i++)
                                {
                                    switch (main2[i][1])
                                    {
                                    case 0:
                                        rg++;
                                        break;
                                    case 1:
                                        vr++;
                                        break;
                                    case 2:
                                        jo++;
                                        break;
                                    case 3:
                                        bl++;
                                        break;
                                    case 4:
                                        break;
                                    }
                                }
                                if (rg>=vr && rg>=jo &&rg>=bl)
                                    choixcol=0;
                                else if(vr>=rg && vr>=jo &&vr>=bl)
                                    choixcol=1;
                                else if(jo>=vr && jo>=rg &&jo>=bl)
                                    choixcol=2;
                                else
                                    choixcol=3;

                                if(ctable[0][0]==14)
                                    roll=2;
                                else
                                    roll=1;
                                ctable[0][1]=choixcol;
                            }

                            else
                            {

                                /*
                                for (i=0; i<ncm2; i++)
                                {
                                    affmain(main2[i][0],main2[i][1],i,ncm2)   ;

                                }*/
                                i=0;
                                choixjeux=2;
                                while (i<ncm2 && choixjeux==2)
                                {
                                    if(ctable[0][0]==main2[i][0]||ctable[0][1]==main2[i][1]||main2[i][0]==14||main2[i][0]==13)
                                        choixjeux=1;
                                    i++;
                                }


                                //condition du choix de jeux

                                if(choixjeux==1)
                                {
                                    i=0;
                                    verif=0;
                                    while(i<ncm2&&verif==0)
                                    {
                                        if(main2[i][0]==ctable[0][0]||main2[i][1]==ctable[0][1]||main2[i][0]==13)
                                            verif=1;

                                        i++;
                                    }
                                    if (verif==1)
                                    {
                                        do
                                        {
                                            l=rand()%ncm2;


                                        }
                                        while(((main2[l][0]!=ctable[0][0])&&(main2[l][1]!=ctable[0][1])&&(main2[l][0]!=13))||main2[l][0]==14);
                                    }
                                    else

                                    {
                                        do
                                        {
                                            l=rand()%ncm2;

                                        }
                                        while(main2[l][0]!=14);
                                    }



                                    if (main2[l][1]!=4)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[main2[l][1]][c]!=-1);

                                    }

                                    if(main2[l][0]==14)
                                    {
                                        do
                                        {

                                            c=rand()%27;
                                        }
                                        while (corbeille[cl4][c]!=-1);
                                        ctable[0][0]=main2[l][0];
                                        ctable[0][1]=4;
                                        corbeille[cl4][c]=ctable[0][0];
                                        cl4++;
                                        roll=2;

                                    }
                                    else if(main2[l][0]==13)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[clj][c]!=-1);
                                        ctable[0][0]=main2[l][0];
                                        ctable[0][1]=4;
                                        corbeille[clj][c]=ctable[0][0];
                                        clj++;

                                    }
                                    else if (main2[l][0]>9&&main2[l][0]<13)
                                    {
                                        ctable[0][0]=main2[l][0];
                                        ctable[0][1]=main2[l][1];
                                        corbeille[main2[l][1]][c]=ctable[0][0];
                                        cond2=1;
                                        roll=2;
                                    }
                                    else
                                    {


                                        ctable[0][0]=main2[l][0];
                                        ctable[0][1]=main2[l][1];
                                        corbeille[main2[l][1]][c]=ctable[0][0];
                                        roll=1;
                                    }

                                    for(i=l; i<ncm2-1; i++)
                                    {

                                        main2[i][0]=main2[i+1][0];
                                        main2[i][1]=main2[i+1][1];
                                    }
                                    ncm2=ncm2-1;

                                    //pour voir esque le pioshe est terminer
                                    l=0;
                                    c=0;
                                    verif=0;
                                    while(l<4&& verif==0)
                                    {
                                        while(c<27&&verif==0)
                                        {
                                            if(carte[l][c]!=-1)
                                                verif=1;
                                            c++;
                                        }
                                        l++;
                                    }

                                    //pour remplire les pioche par les carte dans la corbeille
                                    if (verif==0)
                                    {
                                        for(i=0; i<4; i++)
                                        {
                                            for(j=0; j<27; j++)
                                            {
                                                if(corbeille[i][j]!=-1)
                                                {
                                                    l=0;
                                                    c=0;
                                                    while(l<4&& verif==0)
                                                    {
                                                        while(c<27&&verif==0)
                                                        {
                                                            if(carte[l][c]==-1)
                                                            {
                                                                carte[l][c]=corbeille[i][j];
                                                                corbeille[i][j]=-1;
                                                                verif=1;
                                                            }

                                                            c++;
                                                        }
                                                        l++;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    if (ncm2==1)
                                    {
                                        system("cls");
                                        printf("##     ##    ##    ##     ####### \n");
                                        printf("##     ##    ###   ##    ##     ## \n");
                                        printf("##     ##    ####  ##    ##     ## \n");
                                        printf("##     ##    ## ## ##    ##     ## \n");
                                        printf("##     ##    ##  ####    ##     ## \n");
                                        printf("##     ##    ##   ###    ##     ## \n");
                                        printf(" #######     ##    ##     ####### \n");

                                        Sleep(5000);

                                    }
                                }

                                else
                                {
                                    for (i=ncm2; i<ncm2+1; i++)
                                    {


                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=4;
                                        }
                                        else
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=l;
                                        }
                                        carte[l][c]=-1;
                                    }
                                    ncm2=ncm2+1;
                                    roll=1;
                                }

                            }
                            break;
                        }

                    }
                    while (ncm1!=0&&ncm2!=0);
                    if (ncm1!=0)
                    {
                        for (i=0; i<ncm1; i++)
                        {
                            somm1=somm1+valcarte(main1[i][0]);
                        }
                    }
                    else
                    {
                        for (i=0; i<ncm2; i++)
                        {
                            somm2=somm2+valcarte(main2[i][0]);
                        }
                    }
                    if (nbtour==2)
                    {
                        system("cls");
                        if(somm1>somm2)
                        {
                            printf("!!!!!! Felicitations Vous Avez Gagné!!!!!!\n");
                        }
                        else
                            printf("Voulez-vous continuer?\n")  ;
                        printf("---------- taper 1 si Oui---------") ;
                        printf("---------- taper 2 si Non---------:") ;
                        scanf("%i",&menup);
                        while(menup<1&&menup>2)
                        {
                            printf("\n!!! choisissez 1 ou bien 2!!!=");
                            scanf("%i",&menup);
                        }
                    }
                    break;
                case 2:
                    do
                    {
                        switch(roll)
                        {
                        case 1:
                            system("cls");
                            printf("Tour Numero %i \n",nbtour);
                            printf("Nombre de points de %s=%d\n",nom1,somm1);

                            printf("Nombre de points de %s=%i\n",nom2,somm2);

                            printf("Rolle de :%s \n",nom1);

                            printf("la carte sur table=\n");
                            affmain(ctable[0][0],ctable[0][1],0,1,0) ;
                            //+2 carte

                            if (ctable[0][0]==11&& cond==1)
                            {
                                for (i=ncm2; i<ncm2+2; i++)
                                {
                                    do
                                    {
                                        l=rand()%4;
                                        c=rand()%27;
                                    }
                                    while (carte[l][c]==-1);
                                    corbeille[l][c]=carte[l][c];

                                    if(carte[l][c]>12)
                                    {
                                        main2[i][0]=carte[l][c];
                                        main2[i][1]=4;
                                    }
                                    else
                                    {
                                        main2[i][0]=carte[l][c];
                                        main2[i][1]=l;
                                    }
                                }
                                ncm2=ncm2+2;
                                roll=1;
                                cond++;
                            }
                            //block et reverse
                            else if ((ctable[0][0]==12 || ctable[0][0]==10)&&(cond==1))
                            {
                                roll=1;
                                cond++;
                            }
                            //choisir le couleur pour le joueur 1 carte +4 et joker
                            else if ((ctable[0][0]==13&&ctable[0][1]==4)||(ctable[0][0]==14&&ctable[0][1]==4))
                            {
                                printf("Votre Main = \n");
                                for (i=0; i<ncm1; i++)
                                {
                                    affmain(main1[i][0],main1[i][1],i,ncm1,1)   ;

                                }
                                //si la carte est +4
                                if (ctable[0][0]==14)
                                {
                                    for (i=ncm2; i<ncm2+4; i++)
                                    {
                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=4;
                                        }
                                        else
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=l;
                                        }
                                    }
                                    ncm2=ncm2+4;
                                }
                                printf("choisir un couleur :rouge(1),vert(2),jaune(3),bleu(4):");
                                scanf("%i",&choixcol);
                                while((choixcol<1 )&&(choixcol>4))
                                {
                                    printf("!!choisir un nombre entre 1,2,3 et 4!!:");
                                    scanf("%i",&choixcol);
                                }
                                if(ctable[0][0]==14)
                                    roll=1;
                                else
                                    roll=2;
                                ctable[0][1]=choixcol-1;
                            }

                            else
                            {
                                //affichage de main
                                printf("Main de %s : \n",&nom1);
                                for (i=0; i<ncm1; i++)
                                {
                                    affmain(main1[i][0],main1[i][1],i,ncm1,1)   ;

                                }
                                verif=0;
                                i=0;
                                while (i<ncm1 && verif==0)
                                {
                                    if(main1[i][0]==ctable[0][0]||main1[i][1]==ctable[0][1]||main1[i][0]==14||main1[i][0]==13)
                                        verif=1;
                                    i++;
                                }
                                if (verif==1)
                                {
                                    printf("------Tapper 1 pour jeter une carte -------");
                                    printf("------Tapper 2 pour passer le tour  -------:");

                                    scanf("%i",&choixjeux);
                                    while ((choixjeux<1) || (choixjeux>2))
                                    {
                                        printf("!! choisir entre 1 et 2!!:");
                                        scanf("%i",&choixjeux);
                                    }
                                }
                                else
                                {

                                    printf("------Tapper 1 pour passer le tour  -------:");

                                    scanf("%i",&choixjeux);
                                    choixjeux++;
                                    while (choixjeux!=2)
                                    {
                                        printf("!! il faut que taper 1!!:");
                                        scanf("%i",&choixjeux);
                                        choixjeux++;
                                    }

                                }

                                //condition du choix de jeux

                                if(choixjeux==1)
                                {
                                    printf("choisir le carte en respectant les classes des carte=");
                                    scanf("%i",&choixcart);
                                    while ((choixcart)<1 || (choixcart>ncm1) )
                                    {
                                        printf("!! il faut respecter les classes des carte entre 1 et %i!!:",ncm1);
                                        scanf("%i",&choixcart);

                                    }

                                    do
                                    {
                                        verif=0;
                                        if (main1[choixcart-1][0]<13)
                                        {
                                            if(main1[choixcart-1][0]!=ctable[0][0]&& main1[choixcart-1][1]!=ctable[0][1])
                                                verif=1;
                                        }
                                        else if(main1[choixcart-1][0]==14)
                                        {
                                            i=0;
                                            while (i<ncm1 && verif==0)
                                            {
                                                if(main1[i][0]==ctable[0][0]||main1[i][1]==ctable[0][1])
                                                    verif=1;
                                                i++;
                                            }
                                        }
                                        if (verif==1)
                                        {
                                            printf("!!votre choix inopportune!!\n");
                                            printf("rentre votre choix=");
                                            scanf("%i",&choixcart);

                                        }
                                    }
                                    while (verif==1);

                                    if (main1[choixcart-1][1]!=4)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[main1[choixcart-1][1]][c]!=-1);
                                    }
                                    if(main1[choixcart-1][0]==14)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[cl4][c]!=-1);
                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=4;
                                        corbeille[cl4][c]=ctable[0][0];
                                        cl4++;
                                        roll=1;

                                    }
                                    else if(main1[choixcart-1][0]==13)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[clj][c]!=-1);
                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=4;
                                        corbeille[clj][c]=ctable[0][0];
                                        clj++;
                                        roll=1;
                                    }
                                    else if (main1[choixcart-1][0]>9&&main1[choixcart-1][0]<13)
                                    {
                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=main1[choixcart-1][1];
                                        corbeille[main1[choixcart-1][1]][c]=ctable[0][0];
                                        cond=1;
                                        roll=1;
                                    }
                                    else
                                    {


                                        ctable[0][0]=main1[choixcart-1][0];
                                        ctable[0][1]=main1[choixcart-1][1];
                                        corbeille[main1[choixcart-1][1]][c]=ctable[0][0];
                                        roll=2;
                                    }

                                    for(i=choixcart-1; i<ncm1-1; i++)
                                    {
                                        main1[i][0]=main1[i+1][0];
                                        main1[i][1]=main1[i+1][1];
                                    }
                                    ncm1=ncm1-1;
                                    //pour voir esque le pioshe est terminer
                                    l=0;
                                    c=0;
                                    verif=0;
                                    while(l<4&& verif==0)
                                    {
                                        while(c<27&&verif==0)
                                        {
                                            if(carte[l][c]!=-1)
                                                verif=1;
                                            c++;
                                        }
                                        l++;
                                    }
                                    //pour remplire les pioche par les carte dans la corbeille
                                    if (verif==0)
                                    {
                                        for(i=0; i<4; i++)
                                        {
                                            for(j=0; j<27; j++)
                                            {
                                                if(corbeille[i][j]!=-1)
                                                {
                                                    l=0;
                                                    c=0;
                                                    while(l<4&& verif==0)
                                                    {
                                                        while(c<27&&verif==0)
                                                        {
                                                            if(carte[l][c]==-1)
                                                            {
                                                                carte[l][c]=corbeille[i][j];
                                                                corbeille[i][j]=-1;
                                                                verif=1;
                                                            }

                                                            c++;
                                                        }
                                                        l++;
                                                    }
                                                }
                                            }
                                        }
                                    }

//l'orsque le joueur dit uno
                                    if(ncm1==1)
                                    {
                                        begin=time(NULL);
                                        printf("=");
                                        scanf("%c",&uno);
                                        end=time(NULL);
                                        while (uno!='u'&& uno!='U')
                                        {
                                            printf("=");
                                            scanf("%c",&uno);
                                            end=time(NULL);
                                        }
                                        if (difftime(end,begin)<3)
                                        {
                                            system("cls");
                                            printf("##     ##    ##    ##     ####### \n");
                                            printf("##     ##    ###   ##    ##     ## \n");
                                            printf("##     ##    ####  ##    ##     ## \n");
                                            printf("##     ##    ## ## ##    ##     ## \n");
                                            printf("##     ##    ##  ####    ##     ## \n");
                                            printf("##     ##    ##   ###    ##     ## \n");
                                            printf(" #######     ##    ##     ####### \n");

                                            Sleep(5000);
                                        }
                                        else
                                        {system("cls");
                                            printf("contre uno +2 cartes\n");
                                            Sleep(5555);
                                            for (i=ncm1; i<ncm1+2; i++)
                                            {


                                                do
                                                {
                                                    l=rand()%4;
                                                    c=rand()%27;
                                                }
                                                while (carte[l][c]==-1);
                                                corbeille[l][c]=carte[l][c];

                                                if(carte[l][c]>12)
                                                {
                                                    main1[i][0]=carte[l][c];
                                                    main1[i][1]=4;
                                                }
                                                else
                                                {
                                                    main1[i][0]=carte[l][c];
                                                    main1[i][1]=l;
                                                }
                                                carte[l][c]=-1;
                                            }
                                            ncm1=ncm1+2;
                                        }

                                    }

                                }

                                else
                                {
                                    for (i=ncm1; i<ncm1+1; i++)
                                    {


                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=4;
                                        }
                                        else
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=l;
                                        }
                                        carte[l][c]=-1;
                                    }
                                    ncm1=ncm1+1;
                                    roll=2;
                                }

                            }
                            break;
                        case 2:
                            system("cls");
                            printf("Tour Numero %i \n",nbtour);
                            printf("Nombre de points de %s=%d\n",nom1,somm1);

                            printf("Nombre de points de %s=%i\n",nom2,somm2);

                            printf("Rolle de :%s \n",nom2);
                            printf("la carte sur table=\n");
                            affmain(ctable[0][0],ctable[0][1],0,1,0) ;
                            //+2 carte

                            if (ctable[0][0]==11&& cond2==1)
                            {
                                for (i=ncm1; i<ncm1+2; i++)
                                {
                                    do
                                    {
                                        l=rand()%4;
                                        c=rand()%27;
                                    }
                                    while (carte[l][c]==-1);
                                    corbeille[l][c]=carte[l][c];

                                    if(carte[l][c]>12)
                                    {
                                        main1[i][0]=carte[l][c];
                                        main1[i][1]=4;
                                    }
                                    else
                                    {
                                        main1[i][0]=carte[l][c];
                                        main1[i][1]=l;
                                    }
                                }
                                ncm1=ncm1+2;
                                roll=2;
                                cond2++;
                            }
                            //block et reverse
                            else if ((ctable[0][0]==12 || ctable[0][0]==10)&&(cond2==1))
                            {
                                roll=2;
                                cond2++;
                            }
                            //choisir le couleur pour le joueur 1 carte +4 et joker
                            else if ((ctable[0][0]==13&&ctable[0][1]==4)||(ctable[0][0]==14&&ctable[0][1]==4))
                            {
                                printf("Votre Main = \n");
                                for (i=0; i<ncm2; i++)
                                {
                                    affmain(main2[i][0],main2[i][1],i,ncm2,1)   ;

                                }
                                //si la carte est +4
                                if (ctable[0][0]==14)
                                {
                                    for (i=ncm1; i<ncm1+4; i++)
                                    {
                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=4;
                                        }
                                        else
                                        {
                                            main1[i][0]=carte[l][c];
                                            main1[i][1]=l;
                                        }
                                    }
                                    ncm1=ncm1+4;
                                }
                                printf("choisir un couleur :rouge(1),vert(2),jaune(3),bleu(4)=");
                                scanf("%i",&choixcol);
                                while((choixcol<1 )&&(choixcol>4))
                                {
                                    printf("!!choisir un nombre entre 1,2,3 et 4!!:");
                                    scanf("%i",&choixcol);
                                }
                                if(ctable[0][0]==14)
                                    roll=2;
                                else
                                    roll=1;
                                ctable[0][1]=choixcol-1;
                            }

                            else
                            {
                                //affichage de main
                                printf("Main de %s : \n",&nom2);
                                for (i=0; i<ncm2; i++)
                                {
                                    affmain(main2[i][0],main2[i][1],i,ncm2,1)   ;

                                }
                                verif=0;
                                i=0;
                                while (i<ncm2 && verif==0)
                                {
                                    if(main2[i][0]==ctable[0][0]||main2[i][1]==ctable[0][1]||main2[i][0]==14||main2[i][0]==13)
                                        verif=1;
                                    i++;
                                }
                                if (verif==1)
                                {
                                    printf("------Tapper 1 pour jeter une carte -------");
                                    printf("------Tapper 2 pour passer le tour  -------:");

                                    scanf("%i",&choixjeux);
                                    while ((choixjeux<1) || (choixjeux>2))
                                    {
                                        printf("!! choisir entre 1 et 2!!:");
                                        scanf("%i",&choixjeux);
                                    }
                                }
                                else
                                {

                                    printf("------Tapper 1 pour passer le tour  -------:");

                                    scanf("%i",&choixjeux);
                                    choixjeux++;
                                    while (choixjeux!=2)
                                    {
                                        printf("!! il faut que taper 1!!:");
                                        scanf("%i",&choixjeux);
                                        choixjeux++;
                                    }

                                }

                                //condition du choix de jeux

                                if(choixjeux==1)
                                {
                                    printf("choisir le carte en respectant les classes des carte=");
                                    scanf("%i",&choixcart);
                                    while ((choixcart)<1 || (choixcart>ncm2) )
                                    {
                                        printf("!! il faut respecter les classes des carte entre 1 et %i!!:",ncm2);
                                        scanf("%i",&choixcart);

                                    }

                                    do
                                    {
                                        verif=0;
                                        if (main2[choixcart-1][0]<13)
                                        {
                                            if(main2[choixcart-1][0]!=ctable[0][0]&& main2[choixcart-1][1]!=ctable[0][1])
                                                verif=1;
                                        }
                                        else if(main2[choixcart-1][0]==14)
                                        {
                                            i=0;
                                            while (i<ncm2 && verif==0)
                                            {
                                                if(main2[i][0]==ctable[0][0]||main2[i][1]==ctable[0][1])
                                                    verif=1;
                                                i++;
                                            }
                                        }
                                        if (verif==1)
                                        {
                                            printf("!!votre choix inopportune!!\n");
                                            printf("rentre votre choix=");
                                            scanf("%i",&choixcart);

                                        }
                                    }
                                    while (verif==1);

                                    if (main2[choixcart-1][1]!=4)
                                    {
                                        do
                                        {
                                            c=rand()%27;

                                        }
                                        while (corbeille[main2[choixcart-1][1]][c]!=-1);
                                    }
                                    if(main2[choixcart-1][0]==14)
                                    {
                                        do
                                        {
                                            c=rand()%27;
                                        }
                                        while (corbeille[cl4][c]!=-1);
                                        ctable[0][0]=main2[choixcart-1][0];
                                        ctable[0][1]=4;
                                        corbeille[cl4][c]=ctable[0][0];
                                        cl4++;
                                        roll=2;

                                    }
                                    else if(main2[choixcart-1][0]==13)
                                    {
                                        do
                                        {
                                            c=rand()%27;
                                        }
                                        while (corbeille[clj][c]!=-1);
                                        ctable[0][0]=main2[choixcart-1][0];
                                        ctable[0][1]=4;
                                        corbeille[clj][c]=ctable[0][0];
                                        clj++;
                                        roll=2;
                                    }
                                    else if (main2[choixcart-1][0]>9&&main2[choixcart-1][0]<13)
                                    {
                                        ctable[0][0]=main2[choixcart-1][0];
                                        ctable[0][1]=main2[choixcart-1][1];
                                        corbeille[main2[choixcart-1][1]][c]=ctable[0][0];
                                        cond2=1;
                                        roll=2;
                                    }
                                    else
                                    {


                                        ctable[0][0]=main2[choixcart-1][0];
                                        ctable[0][1]=main2[choixcart-1][1];
                                        corbeille[main2[choixcart-1][1]][c]=ctable[0][0];
                                        roll=1;
                                    }

                                    for(i=choixcart-1; i<ncm2-1; i++)
                                    {
                                        main2[i][0]=main2[i+1][0];
                                        main2[i][1]=main2[i+1][1];
                                    }
                                    ncm2=ncm2-1;
                                    //pour voir esque le pioshe est terminer
                                    l=0;
                                    c=0;
                                    verif=0;
                                    while(l<4&& verif==0)
                                    {
                                        while(c<27&&verif==0)
                                        {
                                            if(carte[l][c]!=-1)
                                                verif=1;
                                            c++;
                                        }
                                        l++;
                                    }
                                    //pour remplire les pioche par les carte dans la corbeille
                                    if (verif==0)
                                    {
                                        for(i=0; i<4; i++)
                                        {
                                            for(j=0; j<27; j++)
                                            {
                                                if(corbeille[i][j]!=-1)
                                                {
                                                    l=0;
                                                    c=0;
                                                    while(l<4&& verif==0)
                                                    {
                                                        while(c<27&&verif==0)
                                                        {
                                                            if(carte[l][c]==-1)
                                                            {
                                                                carte[l][c]=corbeille[i][j];
                                                                corbeille[i][j]=-1;
                                                                verif=1;
                                                            }

                                                            c++;
                                                        }
                                                        l++;
                                                    }
                                                }
                                            }
                                        }
                                    }

//l'orsque le joueur dit uno
                                    if(ncm2==1)
                                    {
                                        begin=time(NULL);
                                        printf("=");
                                        scanf("%c",&uno);
                                        end=time(NULL);
                                        while (uno!='u'&& uno!='U')
                                        {
                                            printf("=");
                                            scanf("%c",&uno);
                                            end=time(NULL);
                                        }
                                        if (difftime(end,begin)<3)
                                        {
                                            system("cls");
                                            printf("##     ##    ##    ##     ####### \n");
                                            printf("##     ##    ###   ##    ##     ## \n");
                                            printf("##     ##    ####  ##    ##     ## \n");
                                            printf("##     ##    ## ## ##    ##     ## \n");
                                            printf("##     ##    ##  ####    ##     ## \n");
                                            printf("##     ##    ##   ###    ##     ## \n");
                                            printf(" #######     ##    ##     ####### \n");
                                            Sleep(5000);

                                        }
                                        else
                                        {
                                            system("cls");
                                            printf("contre uno +2 cartes\n");
                                            Sleep(5555);
                                            for (i=ncm2; i<ncm2+2; i++)
                                            {


                                                do
                                                {
                                                    l=rand()%4;
                                                    c=rand()%27;
                                                }
                                                while (carte[l][c]==-1);
                                                corbeille[l][c]=carte[l][c];

                                                if(carte[l][c]>12)
                                                {
                                                    main2[i][0]=carte[l][c];
                                                    main2[i][1]=4;
                                                }
                                                else
                                                {
                                                    main2[i][0]=carte[l][c];
                                                    main2[i][1]=l;
                                                }
                                                carte[l][c]=-1;
                                            }
                                            ncm2=ncm2+2;
                                        }

                                    }

                                }

                                else
                                {
                                    for (i=ncm2; i<ncm2+1; i++)
                                    {


                                        do
                                        {
                                            l=rand()%4;
                                            c=rand()%27;
                                        }
                                        while (carte[l][c]==-1);
                                        corbeille[l][c]=carte[l][c];

                                        if(carte[l][c]>12)
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=4;
                                        }
                                        else
                                        {
                                            main2[i][0]=carte[l][c];
                                            main2[i][1]=l;
                                        }
                                        carte[l][c]=-1;
                                    }
                                    ncm2=ncm2+1;
                                    roll=1;
                                }

                            }
                            break;
                        }

                    }
                    while (ncm1!=0 && ncm2!=0);
                    if (ncm1!=0)
                    {
                        for (i=0; i<ncm1; i++)
                        {
                            somm1=somm1+valcarte(main1[i][0]);
                        }
                    }
                    else
                    {
                        for (i=0; i<ncm2; i++)
                        {
                            somm2=somm2+valcarte(main2[i][0]);
                        }
                    }
                    if (nbtour==2)
                    {
                        system("cls");
                        printf("Nombre de points de %s=%d\n",nom1,somm1);

                        printf("Nombre de points de %s=%i\n",nom2,somm2);
                        if(somm1>somm2)
                        {
                            printf("!!!!!! %s est le gagnant!!!!!!\n",nom2);
                        }
                        else
                        {
                            printf("!!!!!! %s est le gagnant!!!!!!\n",nom1);
                        }

                        printf("Voulez-vous continuer?\n")  ;
                        printf("---------- taper 1 si Oui---------") ;
                        printf("---------- taper 2 si Non---------:") ;
                        scanf("%i",&menup);
                        while(menup<1&&menup>2)
                        {
                            printf("!!! choisissez 1 ou bien 2!!!=");
                            scanf("%i",&menup);
                        }

                    }
                    break;

                }



            }
            while(nbtour!=2);

        }
        while(menup!=2);
    }
    while(choix!=3);
}

