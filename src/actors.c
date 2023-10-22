#include <string.h>
#include <stdlib.h>
#include "game.h"

Actor *new_actor (char *name);

void render_actor_stats ();	//display scores
void render_actor_stat_page ();	//display page for scores
void mod_actor_stat (Actor * a, char *stat_name, int value);
void set_actor_sex (Actor * a, char *gender);
void mod_npc (Actor * a, int mapid);

//mapid name    gender  health  healthmax       image   faction hitdice hitbonus        damagedice      damagebonus     weapon  lootlist        talklist
//1000  a pirate        female  8       8       fpirate_01.png  pirate  1       0       1       1       saber   pirate  female_pirate
char *
get_actor_gender (Actor *a)
{
  //char s[7];
  if (a->sex == 1)
    {
      return "male";
    }
  else if (a->sex == 0)
    {
      return "female";
    }
  else
    {
      return "neutral";
    }
  /*return "neutral"; */
}

void
mod_actor_stat (Actor *a, char *stat_name, int value)
{
  if (strcmp (stat_name, "strength") == 0)
    {
      a->strength += value;
    }
  else if (strcmp (stat_name, "agility") == 0)
    {
      a->agility += value;
    }
}

Actor *
new_actor (char *name)
{
  Actor *a;
  a = (Actor *) malloc (sizeof (Actor));
  strcpy (a->name, name);
  a->npc_map_id = 0;
  a->sex = 1;			//1male,0female,2neutral
  a->race = 0;
  a->portrait = 0;
  a->health = 1;
  a->fatigue = 1;
  a->mana = 1;
  a->level = 1;
  a->experience = 0;
  a->c_copper = 0;
  a->c_silver = 0;
  a->c_gold = 0;
  a->strength = 1;
  a->intelligence = 1;
  a->agility = 1;
  a->wisdom = 1;
  a->stamina = 1;
  a->charisma = 1;
  a->luck = 1;
  a->bonus_attr = 10;
  //new skills
  a->skill_dagger = 0;
  a->skill_sword = 0;
  a->skill_axe = 0;
  a->skill_crossbow = 0;
  a->skill_archery = 0;
  a->skill_throwing = 0;
  a->skill_polearm = 0;		//spears halberds
  a->skill_club = 0;		//clubs and maces
  a->skill_spiked = 0;		//spiked weapons, picks, morning stars, beaks, sythes
  a->grappling = 0;		//wrestling
  a->biting = 0;		//chomp chomp
  a->hand2hand = 0;		//martial arts
  a->shielding = 0;		//bashing and blocking
  a->dodgemelee = 0;
  a->dodgeranged = 0;
  //social skills
  a->speeches = 0;
  a->lying = 0;
  a->charming = 0;
  a->empathy = 0;		//i feel your pain.
  a->debating = 0;		//arguing your point well.
  a->quickwit = 0;		//a smart mouth can have an effect on a weak mind.
  //less than honest skills
  a->pickpocket = 0;
  a->lockpicking = 0;
  a->traps = 0;			//disarming and setting of traps.
  //perception skills
  a->tracking = 0;
  a->ambushing = 0;
  a->lookout = 0;
  a->findhidden = 0;		//doors, chests, traps
  //crafting skills
  a->woodcutting = 0;
  a->stonecutting = 0;
  a->tunneling = 0;
  a->bowmaking = 0;
  a->fletching = 0;
  a->clothmaking = 0;
  a->blacksmithing = 0;		//making horseshoes!
  a->weaponsmithing = 0;
  a->armorsmithing = 0;
  a->leatherworking = 0;
  return a;
}

/*
typedef struct _Actor {
  char name[25];
  int sex; //1 male, 0 female
  int health, fatigue, mana;
  int level,
    experience,
    c_copper,   //currency
    c_silver,
    c_gold;
  int strength,
    intelligence,
    agility,
    wisdom,
    stamina,
    charisma,
    luck;
} Actor;

*/
