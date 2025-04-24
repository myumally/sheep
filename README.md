# 🐑 sheep

Mon premier projet solo en C : très moche, mais il fonctionne 😅  
Il m'a permis de m'entraîner sur :
- la lecture de fichiers,
- la manipulation de pointeurs,
- l'utilisation de SDL2.

C’est un petit jeu avec du texte et des choix multiples.

J'y suis revenu plus tard pour m’entraîner au WebAssembly. Le code C est toujours aussi affreux, parce que j’y ai à peine retouché 😬

---

## 📦 Versions

- 🖥️ [Version terminal (avec ou sans SDL)](./Original_App/)
- 🌐 [Version Web (WebAssembly)](./Web_Assembly/)

---

## ✏️ Modifier les textes

Tu veux créer ton propre scénario ? Voici comment faire :

1. Crée un fichier `.txt`
2. Suis ce format pour chaque "boîte de dialogue" :
    ```
    ..<numéro de la boîte de dialogue>
    <nombre de réponses possibles>
    <texte de la boîte de dialogue>
    <numéro de destination pour la réponse 1>
    <texte de la réponse 1>
    <numéro de destination pour la réponse 2>
    <texte de la réponse 2>

    (saut de ligne obligatoire entre chaque boîte)
    ```
    🔍 Un exemple est dispo dans le fichier `test.txt`
3. Mets à jour le nom du fichier dans `const.h`

Et voilà ! Tu peux maintenant écrire le prochain chef-d’œuvre du jeu narratif 😄
