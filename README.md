# sheep

Mon premier projet solo en c, très moche mais fonctionne. Il m'a permis de m'entrainer sur la lecture de fichier, la manipulation de pointeurs, et la sdl2.

Il s'agit d'un petit jeu avec des textes et des choix multiples.

Pour run avec l'interface sdl un peu moche :
```
make
./main sdl
```

Pour run dans le terminal :
```
make
./main.c
```

# Pour changer les textes

- Creer un fichier .txt 
- le remplir suivant la methode suivante :
    ```
    ..numero de la boite de dialogue
    nombre de réponse possible
    texte de la boite de dialogue
    numero de la boite de dialogue où mène la réponse 1
    texte de la réponse 1 
    numero de la boite de dialogue où mène la réponse 2 
    texte de la réponse 2 
    _saut de ligne_
    ```
    pour un exemple voir le fichier "test.txt"
- changer le nom du fichier dans const.h
