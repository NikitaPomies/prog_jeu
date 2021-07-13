# prog_jeu

Principes du jeu : 

Le joueur contrôle un personnage materialisé par un disque noir.

Il doit survivre aux tirs de ses ennemis en se déplaçant sur l'aire de jeu, en leur tirant dessus et en récuperant des bonus afin de s'aider. Attention, une balle tirée par le joueur disparaît avant de toucher sa cible si le joeur tire à nouveau avant que la balle n'est atteint la cible en question.

Les ennemis apparaissent aléatoirement - toutes les 15 secondes ou lorsque tous sont morts - sur les bords du terrain de jeu.
Les bonus apparaissent aléatoirement - toutes les 20 secondes ou lorsque tous ont été récupérés - sur l'ensemble du terrain de jeu.


Commandes : 

Le joueur se déplace à l'aide des flêches de son clavier et tire en visant avec sa souris.
Il a à sa disposition trois bonus, utilisables comme suit : 

    - barre ESPACE : récupère des points de vie,
    - touche ENTREE : active un bouclier qui le protege des balles ennemis,
    - touche SHIFT : tue immediatement un des ennemis présent sur le terrain.

ATTENTION : les key_codes utilisés pour les bonus dépendent peut être du clavier utilisé parce que les variables KEY_ESPACE, KEY_ENTER etc... n'étaient pas fonctionnelles sur mon ordinateur. 


Structure du code : 

- Une classe perso (pour le joueur) :

        * Atttributs : toutes ses caractéristiques (graphiques et fonctionnelles : vie, attaque, vitesse, bouclier...), ainsi que certaines caractéristiques des balles qu'il tire.
        * Méthodes : gestion de l'affichage (déplacement et barre de vie) et de ses tirs de balle

- Une classe ennemi : 

        * Attributs : comme pour le joueur
        * Methodes : comme pour le joeur, mais en plus avec la barre de vie sous le personnage.

- Une classe balle : 

        Elle est utilisée à la fois par le joeur et les ennemis. 

        * Attributs : toutes ses caractéristiques (taille, vitesse, direction...)
        * Methodes : déplacement, initialisation, mort.

- Un fichier utils :

        Contient une classe point très générique.

        Contient des fonctions standarts d'affichage, d'autres pour gérer l'aléatore ou les collisions par exemple.

- Un fichier bonus :

        Contient essentiellemeent des fonctions d'affichage liées aux bonus.


Ce qui fonctionne bien : 

    - L'implémentation des balles : la classe est utilisable à la fois par le joueur et ses ennemis alors que leur mode de tir est totalement différent, donc très pratique. Les collisions sont bien gérées.

    - L'utilisation des bonus, à deux défauts près : un défaut d'affichage sur certaines récupération de vie, et un autre lorsque le temps limite d'apparition des bonus est dépassé.

    - Le déplacement du personnage et la gestion des entrées clavier/souris.

    - L'affichage de la barre de menu.


Ce qui fonctionne mal / ce qui pourrait être amélioré : 

    - Les détails d'affichage mentionnés au dessus.

    - On aurait voulu : 

        - rendre fonctionnel le systeme de niveau, en utilisant des coefficients (fonctions du niveau en cours) pour piloter certains paramètres de difficults (fréquences d'apparition des ennemis, capacités des ennemis...)

        - implémenter d'autres types d'ennemis, notamment des ennemis qui peuvent se déplacer

        - utiliser un système de portails pour passer d'un niveau à un autre

        - améliorer les graphismes du personnage joueur. 
