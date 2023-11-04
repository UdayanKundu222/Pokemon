#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ember(int *, int *, char);
int vwhip(int *, int *, char);
int Watergun(int *, int *, char);
int scratch(int *, int *);
int Tackle(int *, int *);
void scaryface(int *);
void growl(int *);
void tailwhip(int *);
void withdraw(int *);
void Growth(int *);

void smove(int self, int opp, int *satk, int *oatk, int *sdef, int *odef, int *shp, int *ohp, int *sspd, int *ospd, char stype, char otype) {
    int damage = 0, choice;

    if (self == 1) {
        printf("\nCharmander, the Flame Pok�mon, is ready to ignite the battle!\n");
        printf("Select a move for Charmander:\n");
        printf("1) Scratch  2) Ember  3) Scary Face  4) Growl\n");
        scanf("%d", &choice);

        if (choice == 2) {
            damage = ember(satk, odef, otype);
            printf("Charmander unleashes Ember, dealing %d HP damage with a fiery attack!\n", damage);
        } else if (choice == 1) {
            damage = scratch(satk, odef);
            printf("Charmander uses Scratch, causing %d HP damage with its sharp claws!\n", damage);
        } else if (choice == 3) {
            scaryface(ospd);
            printf("Charmander employs Scary Face, intimidating the opponent and lowering its speed by 1 stage!\n");
        } else if (choice == 4) {
            growl(oatk);
            printf("Charmander growls to lower the opponent's attack by 1 stage!\n");
        }
    }

    if (self == 2) {
        printf("\nSquirtle, the Tiny Turtle Pok�mon, is ready for action!\n");
        printf("Select a move for Squirtle:\n");
        printf("1) Tackle  2) Water Gun  3) Tail Whip  4) Withdraw\n");
        scanf("%d", &choice);

        if (choice == 2) {
            damage = Watergun(satk, odef, otype);
            printf("Squirtle uses Water Gun, dealing %d HP damage with a water-based attack!\n", damage);
        } else if (choice == 1) {
            damage = Tackle(satk, odef);
            printf("Squirtle tackles the opponent, causing %d HP damage!\n", damage);
        } else if (choice == 3) {
            tailwhip(odef);
            printf("Squirtle performs Tail Whip, lowering the opponent's Defense by 1 stage!\n");
        } else if (choice == 4) {
            withdraw(sdef);
            printf("Squirtle withdraws into its shell to raise its Defense by 1 stage!\n");
        }
    }

    if (self == 3) {
        printf("\nBulbasaur, the Seed Pok�mon, is ready to bloom!\n");
        printf("Select a move for Bulbasaur:\n");
        printf("1) Tackle  2) Vine Whip  3) Growth  4) Growl\n");
        scanf("%d", &choice);

        if (choice == 2) {
            damage = vwhip(satk, odef, otype);
            printf("Bulbasaur uses Vine Whip, dealing %d HP damage with its plant-based attack!\n", damage);
        } else if (choice == 1) {
            damage = Tackle(satk, odef);
            printf("Bulbasaur tackles the opponent, causing %d HP damage!\n", damage);
        } else if (choice == 3) {
            Growth(satk);
            printf("Bulbasaur uses Growth, raising its Attack by 1 stage!\n");
        } else if (choice == 4) {
            growl(oatk);
            printf("Bulbasaur growls to lower the opponent's Attack by 1 stage!\n");
        }
    }

    (*ohp) = (*ohp - damage);
}

void omove(int self, int opp, int *satk, int *oatk, int *sdef, int *odef, int *shp, int *ohp, int *sspd, int *ospd, char stype, char otype) {
    int damage = 0, choice;
    choice = rand() % 4 + 1;

    if (opp == 1) {
        if (choice == 2) {
            damage = ember(oatk, sdef, stype);
            printf("The opponent's Charmander breathes fire with Ember, dealing %d HP damage!\n", damage);
        } else if (choice == 1) {
            damage = scratch(oatk, sdef);
            printf("The opponent's Charmander uses Scratch, causing %d HP damage with sharp claws!\n", damage);
        } else if (choice == 3) {
            scaryface(sspd);
            printf("The opponent's Charmander employs Scary Face, lowering your speed by 1 stage!\n");
        } else if (choice == 4) {
            growl(satk);
            printf("The opponent's Charmander growls to lower your Attack by 1 stage!\n");
        }
    }

    if (opp == 2) {
        if (choice == 2) {
            damage = Watergun(oatk, sdef, stype);
            printf("The opponent's Squirtle uses Water Gun, dealing %d HP damage with a water-based attack!\n", damage);
        } else if (choice == 1) {
            damage = Tackle(oatk, sdef);
            printf("The opponent's Squirtle tackles you, causing %d HP damage!\n", damage);
        } else if (choice == 3) {
            tailwhip(sdef);
            printf("The opponent's Squirtle performs Tail Whip, lowering your Defense by 1 stage!\n");
        } else if (choice == 4) {
            withdraw(odef);
            printf("The opponent's Squirtle withdraws into its shell to raise its Defense by 1 stage!\n");
        }
    }

    if (opp == 3) {
        if (choice == 2) {
            damage = vwhip(oatk, sdef, stype);
            printf("The opponent's Bulbasaur uses Vine Whip, dealing %d HP damage with a plant-based attack!\n", damage);
        } else if (choice == 1) {
            damage = Tackle(oatk, sdef);
            printf("The opponent's Bulbasaur tackles you, causing %d HP damage!\n", damage);
        } else if (choice == 3) {
            Growth(oatk);
            printf("The opponent's Bulbasaur uses Growth, raising its Attack by 1 stage!\n");
        } else if (choice == 4) {
            growl(satk);
            printf("The opponent's Bulbasaur growls to lower your Attack by 1 stage!\n");
        }
    }

    (*shp) = (*shp - damage);
}

int ember(int *atk, int *def, char type) {
    float damage;
    damage = 2.5 * (*atk) / (*def);
    if (type == 'g') {
        return damage * 10;
    } else {
        return damage * 5;
    }
}

int vwhip(int *atk, int *def, char type) {
    float damage;
    damage = 2.5 * (*atk) / (*def);
    if (type == 'w') {
        return damage * 10;
    } else {
        return damage * 5;
    }
}

int Watergun(int *atk, int *def, char type) {
    float damage;
    damage = 2.5 * (*atk) / (*def);
    if (type == 'f') {
        return damage * 10;
    } else {
        return damage * 5;
    }
}

int scratch(int *atk, int *def) {
    float damage;
    damage = 2.5 * (*atk) / (*def);
    return damage * 7;
}

int Tackle(int *atk, int *def) {
    float damage;
    damage = 2.5 * (*atk) / (*def);
    return damage * 7;
}

void scaryface(int *spd) {
    (*spd) = (*spd) * 2 / 3;
}

void growl(int *atk) {
    (*atk) = (*atk) * 2 / 3;
}

void tailwhip(int *defence) {
    (*defence) = (*defence) * 2 / 3;
}

void withdraw(int *defence) {
    (*defence) = (*defence) * 3 / 2;
}

void Growth(int *atk) {
    (*atk) = (*atk) * 3 / 2;
}

int main() {
    int self, opp, satk, oatk, sdef, odef, shp, ohp, sspd, ospd;
    char stype, otype;

    printf("Welcome to the world of Pok�mon Battles!\n");

    printf("Choose your Pok�mon:\n");
    printf("1) Charmander: The Flame Pok�mon\n");
    printf("2) Squirtle: The Tiny Turtle Pok�mon\n");
    printf("3) Bulbasaur: The Seed Pok�mon\n");

    scanf("%d", &self);

    printf("Select your opponent's Pok�mon:\n");
    scanf("%d", &opp);

    if (self == 1) {
        shp = 78;
        satk = 109;
        sdef = 78;
        sspd = 100;
        stype = 'f';
    } else if (self == 2) {
        shp = 79;
        satk = 85;
        sdef = 100;
        sspd = 83;
        stype = 'w';
    } else if (self == 3) {
        shp = 80;
        satk = 82;
        sdef = 83;
        sspd = 80;
        stype = 'g';
    }

    if (opp == 1) {
        ohp = 78;
        oatk = 109;
        odef = 78;
        ospd = 101;
        otype = 'f';
    } else if (opp == 2) {
        ohp = 79;
        oatk = 85;
        odef = 100;
        ospd = 82;
        otype = 'w';
    } else if (opp == 3) {
        ohp = 80;
        oatk = 82;
        odef = 83;
        ospd = 79;
        otype = 'g';
    }

    while (ohp > 0 && shp > 0)  { if(sspd>ospd)
    {smove(self,opp,&satk,&oatk,&sdef,&odef,&shp,&ohp,&sspd,&ospd,stype,otype);
    if(ohp>0)
    {
         printf("\nOpponent has %d hp remaining\n",ohp);

    }
    if (ohp<=0)
    break;
    omove(self,opp,&satk,&oatk,&sdef,&odef,&shp,&ohp,&sspd,&ospd,stype,otype);

    if (shp>0){
        printf("\nYour pokemon has %d hp left\n",shp);

    }
    if(shp<=0)
    break;
    }
   else if(ospd>sspd)
    {omove(self,opp,&satk,&oatk,&sdef,&odef,&shp,&ohp,&sspd,&ospd,stype,otype);
    if (shp>0){
        printf("\nYour pokemon has %d hp left\n",shp);}
        if(shp<=0)
    break;


    smove(self,opp,&satk,&oatk,&sdef,&odef,&shp,&ohp,&sspd,&ospd,stype,otype);
     if(ohp>0)
         {
         printf("\nOpponent has %d hp remaining\n",ohp);}
         if (ohp<=0)
         break;
    }



    }
if (shp<=0)
    {printf("/nYour pokemon fainted. You lost the battle.");}
else if(ohp<=0)

   {printf("/nYour opponent fainted!You win!");}
return 0;
}
